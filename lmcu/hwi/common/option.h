#pragma once
#include <type_traits>
#include <tuple>

namespace lmcu::option {

struct null {};

template<typename _type>
struct invalid;

template<typename _type>
struct duplicate;

template<auto _opt_val>
constexpr bool is_null()
{
  return std::is_same_v<std::remove_cv_t<decltype(_opt_val)>, null>;
}

namespace detail {

template<typename _opt, auto _arg, auto ..._args>
constexpr auto get()
{
  if constexpr(std::is_same_v<std::remove_cv_t<_opt>, std::remove_cv_t<decltype(_arg)>>) {
    return _arg;
  }
  else
  if constexpr(sizeof...(_args) > 0) {
    return get<_opt, _args...>();
  }
  else {
    return null{};
  }
}

template<typename _opt, auto _arg, auto ..._args>
constexpr auto get([[maybe_unused]] _opt defval)
{
  if constexpr(std::is_same_v<std::remove_cv_t<_opt>, std::remove_cv_t<decltype(_arg)>>) {
    return _arg;
  }
  else
  if constexpr(sizeof...(_args) > 0) {
    return get<_opt, _args...>(defval);
  }
  else {
    return defval;
  }
}

template<typename _arg, typename _options, int _i = 0>
constexpr bool find()
{
  if constexpr(
    std::is_same_v<
      std::remove_cv_t<_arg>,
      std::remove_cv_t<std::tuple_element_t<_i, _options>>
    >
  ) {
    return true;
  }
  else
  if constexpr((_i + 1) < std::tuple_size<_options>::value) {
    return find<_arg, _options, _i + 1>();
  }
  else {
    return false;
  }
}

template<typename _opt, int _n, auto _arg, auto ..._args>
constexpr auto count()
{
  using arg = std::remove_cv_t<decltype(_arg)>;
  constexpr auto n = std::is_same_v<std::remove_cv_t<_opt>, arg>? _n + 1 : _n;

  if constexpr(sizeof...(_args) > 0) {
    return count<_opt, n, _args...>();
  }
  else {
    return n;
  }
}

template<typename _options, int _i, auto ..._args>
constexpr bool find_dup()
{
  using opt_t = std::remove_cv_t<std::tuple_element_t<_i, _options>>;

  if constexpr(count<opt_t, 0, _args...>() > 1) {
    return true;
    duplicate<opt_t>{};
  }

  if constexpr((_i + 1) < std::tuple_size<_options>::value) {
    return find_dup<_options, _i + 1, _args...>();
  }
  else {
    return false;
  }
}

template<typename _options, auto _arg, auto ..._args>
constexpr bool check()
{
  using arg_t = std::remove_cv_t<decltype(_arg)>;

  if constexpr(!find<arg_t, _options>()) {
    return false;
    invalid<arg_t>{};
  }
  else {
    if constexpr(find_dup<_options, 0, _arg, _args...>()) {
      return false;
    }
    else
    if constexpr(sizeof...(_args) > 0) {
      return check<_options, _args...>();
    }
    else {
      return true;
    }
  }
}

} // namespace detail

template<typename _opt, auto ..._args>
constexpr auto get()
{
  if constexpr(sizeof...(_args) > 0) {
    return detail::get<_opt, _args...>();
  }
  else {
    return null{};
  }
}

template<typename _opt, auto ..._args>
constexpr auto get_u()
{
  if constexpr(sizeof...(_args) > 0) {
    constexpr auto opt = get<_opt, _args...>();
    if constexpr(is_null<opt>()) {
      return null{};
    }
    else {
      return std::underlying_type_t<_opt>(opt);
    }
  }
  else {
    return null{};
  }
}

template<typename _opt, auto ..._args>
constexpr auto get(_opt defval)
{
  if constexpr(sizeof...(_args) > 0) {
    return detail::get<_opt, _args...>(defval);
  }
  else {
    return defval;
  }
}

template<typename _opt, auto ..._args>
constexpr auto get_u(_opt defval)
{
  if constexpr(sizeof...(_args) > 0) {
    return std::underlying_type_t<_opt>(get<_opt, _args...>(defval));
  }
  else {
    return std::underlying_type_t<_opt>(defval);
  }
}

template<typename _options, auto ..._args>
constexpr bool check()
{
  if constexpr(sizeof...(_args) > 0) {
    return detail::check<_options, _args...>();
  }
  else {
    return true;
  }
}

} // namespace lmcu::option
