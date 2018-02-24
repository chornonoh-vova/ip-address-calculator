#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <bitset>

#include "../util/util.h"

namespace calc {
  class ip_address_calculator {
    std::string _ip;
    uint32_t _num_ip;
    uint32_t _mask;
    std::uint32_t _prefix;

    uint32_t getip(std::string ip);

    uint32_t convert_prefix_to_mask(uint32_t prefix);

    std::string convert_num_to_ip(uint32_t num);

  public:
    ip_address_calculator(std::string ip, uint32_t prefix) : _ip(ip), _prefix(prefix) {
      _num_ip = getip(_ip);
      _mask = convert_prefix_to_mask(prefix);
    }

    std::string getnetwork() {
      uint32_t net = _num_ip & _mask;
      return convert_num_to_ip(net);
    }

    std::string getbroadcast() {
      uint32_t broadcast = _num_ip | ( ~ _mask);
      return convert_num_to_ip(broadcast);
    }

    std::string getmask() {
      return convert_num_to_ip(_mask);
    }

    std::string getip() {
      return convert_num_to_ip(_num_ip);
    }
  };
}

#endif //CALCULATOR_H
