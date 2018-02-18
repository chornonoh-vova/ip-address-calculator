#include "calculator.h"

namespace calc {

  uint32_t ip_address_calculator::getip(std::string ip) {
    auto bin_func([] (auto iter_first, auto iter_second) {
      return std::stoi(std::string(iter_first, iter_second), nullptr, 10);
    });

    std::vector<uint32_t> int_list;
    util::split(std::begin(ip), std::end(ip), std::back_inserter(int_list), '.', bin_func);

    uint32_t sum = 0;
    for (int i = 0; i <= 3; ++i) {
      sum += int_list.at(i);
      if (i == 3) break;
      sum <<= 8;
    }

    return sum;
  }

  uint32_t ip_address_calculator::convert_prefix_to_mask(uint32_t prefix) {
    uint32_t result = 0;

    for (int i = 0; i <= 31; ++i) {
      if (i < prefix) {
        result += 1;
      }
      if (i == 31) break;
      result <<= 1;
    }
    return result;
  }

  std::string ip_address_calculator::convert_num_to_ip(uint32_t num) {
    uint32_t num_ip = num;
    std::string result;
    uint32_t byte = 0x000000ff;
    for (auto i = 0; i < 4; ++i, num_ip >>= 8) {
      uint32_t digit = num_ip & byte;
      result.insert(0, "." + std::to_string(digit));
    }
    result.erase(std::begin(result));
    return result;
  }

}
