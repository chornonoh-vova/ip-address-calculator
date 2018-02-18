#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <algorithm>
#include <iterator>

namespace util {
  template <typename Iterator, typename OutIterator, typename T, typename Function>
  Iterator split(Iterator begin, Iterator end, OutIterator out, T split_val, Function func) {
    while (begin != end) {
      auto slice_end(std::find(begin, end, split_val));
      *out++ = func(begin, slice_end);
      if(slice_end == end) {
        return end;
      }
      begin = std::next(slice_end);
    }
    return begin;
  }
}

#endif //UTIL_H
