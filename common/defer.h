#pragma once

template<typename T>
class __defer_9ec0ab5f
{
  __defer_9ec0ab5f(const __defer_9ec0ab5f&) = delete;
  __defer_9ec0ab5f &operator =(const __defer_9ec0ab5f&) = delete;
public:
  __defer_9ec0ab5f(T&& fn): fn_(fn) { }
  ~__defer_9ec0ab5f() { fn_(); }
private:
  T fn_;
};

#define defer_9ec0ab5f_1(line) __defer_9ec0ab5f_obj_##line
#define defer_9ec0ab5f_2(line) defer_9ec0ab5f_1(line)

#define lmcu_defer(...) __defer_9ec0ab5f defer_9ec0ab5f_2(__LINE__)(__VA_ARGS__)
