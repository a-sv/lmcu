#pragma once
#include <type_traits>
#include <lmcu/hwi/common>
#include <lmcu/hash>

namespace lmcu::mtd {

template<
  typename _dev,
  uint32_t _start_block,
  uint32_t _end_block,
  bool _seekable,
  typename _struct
>
class log
{
public:
  explicit log(_dev &dev): dev_(dev) { }

  log(const log&) = delete;
  log &operator =(const log&) = delete;

  io::result open(const delay::expirable &t)
  {
    if constexpr(_seekable) {
      bi_.rec_count = 0;
    }
    bi_.end.seq = 0;
    bi_.end.ofs = 0;

    if constexpr(_seekable) {
      bi_.beg.idx = _start_block;
      bi_.beg.ofs = sizeof(rec);
      bi_.beg.seq = 0;
    }

    //
    // lookup end block
    //

    block_head bh;

    for(uint32_t idx = _start_block; idx < _end_block; idx++) {
      const uint32_t ofs = idx * _dev::page_size;

      if(auto res = dev_.read(ofs, &bh, sizeof(bh), t); res != io::result::success) {
        if(res == io::result::busy) { return res; }
        continue;
      }

      if constexpr(_seekable) {
        if(bh.calc_crc() == bh.crc) {
          bi_.rec_count += records_per_block;

          if(bh.seq > bi_.end.seq) {
            bi_.end.idx = idx;
            bi_.end.seq = bh.seq;

            if(!bi_.beg.is_valid()) {
              bi_.beg.idx = idx;
              bi_.beg.seq = bh.seq;
            }
          }
          else
          if(bi_.beg.seq > bh.seq) {
            bi_.beg.idx = idx;
            bi_.beg.seq = bh.seq;
          }
        }

        bi_.cur.blk = bi_.beg;
        bi_.cur.rec = 0;
      }
      else {
        if(bh.seq > bi_.end.seq && bh.calc_crc() == bh.crc) {
          bi_.end.idx = idx;
          bi_.end.seq = bh.seq;
        }
      }
    }

    if(!bi_.end.is_valid()) {
      bi_.end.idx = _start_block;
      bi_.end.seq = 1;
      return io::result::success;
    }

    //
    // lookup last record
    //

    const uint32_t data_ofs = (bi_.end.idx * _dev::page_size) + sizeof(block_head);
    rec r;
    uint32_t count = 0, ofs = 0;

    for(uint32_t n = 1; (block_data_size - ofs) >= sizeof(rec); n++) {
      if(auto res = dev_.read(data_ofs + ofs, &r, sizeof(rec), t); res != io::result::success) {
        return res;
      }
      ofs += sizeof(rec);
      if(r.crc == r.data.calc_checksum()) { bi_.end.ofs = ofs; count = n; }
    }

    if constexpr(_seekable) {
      bi_.rec_count -= records_per_block - count;
    }

    return io::result::success;
  }

  io::result seek(uint32_t rec_n, const delay::expirable &t)
  {
    auto n = rec_n;

    if constexpr(_seekable) {
      if(!bi_.beg.is_valid() || !bi_.end.is_valid()) { return io::result::error; }

      if(n < records_per_block) {
        bi_.cur.blk     = bi_.beg;
        bi_.cur.blk.ofs = sizeof(rec) * (n + 1);
        bi_.cur.rec     = rec_n;
        return io::result::success;
      }

      block_head bh;

      for(auto idx = bi_.beg.idx; ; idx++) {
        if(idx >= _end_block) { idx = _start_block; }

        if(
          auto res = dev_.read(idx * _dev::page_size, &bh, sizeof(bh), t);
          res != io::result::success
        ) {
          if(res == io::result::busy) { return res; }
          continue;
        }

        if(bh.crc == bh.calc_crc()) {
          n -= records_per_block;
          if(n < records_per_block) {
            if(++idx >= _end_block) { idx = _start_block; }
            bi_.cur.blk.idx = idx;
            bi_.cur.blk.seq = bh.seq;
            bi_.cur.blk.ofs = sizeof(rec) * (n + 1);
            bi_.cur.rec     = rec_n;
            return io::result::success;
          }
        }

        if(idx == bi_.end.idx) { break; }
      }
    }

    return io::result::error;
  }

  io::result read(_struct &data, const delay::expirable &t)
  {
    block_t *block;

    if constexpr(_seekable) {
      if(bi_.rec_count == 0 || bi_.cur.rec >= bi_.rec_count) { return io::result::eof; }
      block = &bi_.cur.blk;
    }
    else {
      block = &bi_.end;
      if(!block->is_valid()) { return io::result::error; }
    }

    if(block->ofs == 0) { return io::result::eof; }

    const uint32_t ofs = block->idx * _dev::page_size + sizeof(block_head) +
                         (block->ofs - sizeof(rec));

    if constexpr(_seekable) {
      block->ofs += sizeof(rec);
      if(block->ofs >= block_data_size) {
        auto idx = block->idx;
        block_head bh;
        while(true) {
          if(++idx >= _end_block) { idx = _start_block; }

          if(
            auto res = dev_.read(idx * _dev::page_size, &bh, sizeof(bh), t);
            res != io::result::success
          ) {
            if(res == io::result::busy) { return res; }
            continue;
          }

          if(idx == bi_.beg.idx) { bi_.cur.rec = bi_.rec_count + 1; return io::result::eof; }

          if(bh.crc == bh.calc_crc()) {
            block->idx = idx;
            block->seq = bh.seq;
            block->ofs = sizeof(rec);
            break;
          }
        }
      }

      bi_.cur.rec++;
    }

    rec r;
    if(auto res = dev_.read(ofs, &r, sizeof(r), t); res != io::result::success) { return res; }

    if(r.crc != r.data.calc_checksum()) { return io::result::error; }

    data = r.data;

    return io::result::success;
  }

  io::result append(const _struct &data, const delay::expirable &t)
  {
    uint32_t idx = bi_.end.idx, ofs = bi_.end.ofs;

    [[maybe_unused]] auto move_beg = [&](const uint32_t index)
    {
      if constexpr(_seekable) {
        block_head bh;

        for(auto idx = index;; idx++) {
          if(idx >= _end_block) { idx = _start_block; }

          if(
            auto res = dev_.read(idx * _dev::page_size, &bh, sizeof(bh), t);
              res != io::result::success
              ) {
            if(res == io::result::busy) { return res; }
            if(idx == index) { return io::result::error; }
            continue;
          }

          if(bh.crc == bh.calc_crc()) {
            bi_.beg.idx = idx;
            bi_.beg.seq = bh.seq;
            bi_.beg.ofs = sizeof(rec);
            break;
          }

          if(idx == index) { return io::result::error; }
        }
      }

      return io::result::success;
    };

    auto prepare_new_block = [&](bool next)
    {
      auto next_index = [&] { return ((idx + 1 >= _end_block)? _start_block : idx + 1); };

      if(next) { idx = next_index(); }

      while(!t.expired()) {
        if constexpr(_seekable) {
          if(bi_.beg.is_valid() && bi_.beg.idx == idx) {
            if(auto res = move_beg(idx + 1); res != io::result::success) { return res; }
          }
        }

        bool is_empty = false;
        if(auto res = dev_.page_empty(idx, 1, is_empty, t); res != io::result::success) {
          if(res == io::result::busy) { return res; }
          idx = next_index();
          continue;
        }

        if(!is_empty) {
          if(auto res = dev_.page_erase(idx, 1, t); res != io::result::success) {
            if(res == io::result::busy) { return res; }
            idx = next_index();
            continue;
          }

          if constexpr(_seekable) { bi_.rec_count -= records_per_block; }
        }

        ofs = 0;
        return io::result::success;
      }
      return io::result::busy;
    };

    if(ofs == 0) {
      if(auto res = prepare_new_block(false); res != io::result::success) { return res; }
    }

    const uint32_t rec_crc = data.calc_crc();
    rec r = { rec_crc, data };

    while(!t.expired()) {
      if((block_data_size - ofs) < sizeof(rec)) {
        if(auto res = prepare_new_block(true); res != io::result::success) {
          if(res == io::result::busy) { return res; }
          continue;
        }
      }

      const uint32_t
          b_ofs = idx * _dev::page_size,
          r_ofs = b_ofs + sizeof(block_head) + ofs;

      const bool is_new_block = (ofs == 0);
      ofs += sizeof(rec);

      if(auto res = dev_.write(r_ofs, &r, sizeof(rec), t); res != io::result::success) {
        if(res == io::result::busy) { return res; }
        continue;
      }

      if(auto res = dev_.sync(t); res != io::result::success) { return res; }

      if(auto res = dev_.read(r_ofs, &r, sizeof(rec), t); res != io::result::success) {
        if(res == io::result::busy) { return res; }
        continue;
      }

      if((rec_crc == r.crc) && (rec_crc == r.data.calc_crc())) {
        if(is_new_block) {
          block_head bh;
          bh.seq = bi_.end.seq + 1;
          bh.crc = bh.calc_crc();
          const auto bh_crc = bh.crc;

          if(auto res = dev_.write(b_ofs, &bh, sizeof(bh), t); res != io::result::success) {
            if(res == io::result::busy) { return res; }
            ofs = block_data_size;
            continue;
          }

          if(auto res = dev_.sync(t); res != io::result::success) { return res; }

          if(
            auto res = dev_.read(b_ofs, &bh, sizeof(bh), t);
            (res != io::result::success) || (bh.calc_crc() != bh_crc)
          ) {
            if(res == io::result::busy) { return res; }
            ofs = block_data_size;
            continue;
          }

          bi_.end.seq = bh.seq;
        }

        bi_.end.idx = idx;
        bi_.end.ofs = ofs;

        if constexpr(_seekable) {
          if(!bi_.beg.is_valid()) {
            bi_.beg.idx = bi_.end.idx;
            bi_.beg.seq = bi_.end.seq;
            bi_.beg.ofs = sizeof(rec);
          }
          bi_.rec_count++;
        }

        return io::result::success;
      }
    }

    return io::result::busy;
  }

  inline uint32_t rec_count() const
  {
    if constexpr(_seekable) {
      return bi_.rec_count;
    }
    else {
      return 1;
    }
  }

  inline uint32_t current_rec() const
  {
    if constexpr(_seekable) {
      return bi_.cur.rec;
    }
    else {
      return 1;
    }
  }
private:
  struct block_head
  {
    uint32_t seq, crc;

    uint32_t calc_crc() const
    {
#ifdef _LMCU_DEVICE_STM32_
      using namespace lmcu::hash::hw;

      crc32::reset();
      crc32::update(seq);
      return crc32::value();
#else
      return 0; // TODO: software crc calculation
#endif // _LMCU_DEVICE_STM32_
    }
  };

  struct block_t
  {
    uint32_t idx = 0;
    uint32_t seq = 0;
    uint32_t ofs = 0;

    inline bool is_valid() const noexcept { return seq != 0; }
  };

  struct nonseekable_t
  {
    block_t end;
  };

  struct cur_t
  {
    block_t blk;
    uint32_t rec = 0;
  };

  struct seekable_t
  {
    block_t beg, end;
    cur_t cur;
    uint32_t rec_count = 0;
  };

  struct rec
  {
    decltype(_struct().calc_checksum()) crc;
    _struct data;
  };

  using block_info_t = std::conditional_t<_seekable, seekable_t, nonseekable_t>;

  static constexpr uint32_t
    block_data_size   = _dev::page_size - sizeof(block_head),
    records_per_block = block_data_size / sizeof(rec)
  ;

  _dev &dev_;
  block_info_t bi_;

  static_assert(_dev::dev_class == dev_class::mtd, "_dev must be MTD compatible device");
  static_assert(block_data_size >= sizeof(rec), "_struct not fit into MTD page");
};

} // namespace lmcu::mtd::log
