#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <bitset>

#include <string.h>

#include "calc/calculator.h"

int main(int argc, char** argv)
{
  if (strcmp(argv[1], "--help") == 0) {
    std::cout << "type ip-calculator --all <ip>/<prefix> to compute all network boundaries" << std::endl;
    std::cout << "type ip-calculator --net <ip>/<prefix> to compute only network address" << std::endl;
    std::cout << "type ip-calculator --mask <ip>/<prefix> to compute only network mask" << std::endl;
    std::cout << "type ip-calculator --broadcast <ip>/<prefix> to compute only broadcast address" << std::endl;
    return 0;
  } else if (strcmp(argv[1], "--all") == 0 && strlen(argv[2]) != 0) {
    std::string given_parameters(argv[2]);
    std::size_t found = given_parameters.find('/');
    if (found != std::string::npos) {
      std::string given_ip = given_parameters.substr(0, found);
      std::string given_prefix = given_parameters.substr(found + 1, given_parameters.size() - 1);

      if (std::stoi(given_prefix) > 32 || std::stoi(given_prefix) < 0) {
        std::cerr << "prefix must be less than 32 and greater than 0" << std::endl;
        return 3;
      }

      calc::ip_address_calculator given(given_ip, std::stoi(given_prefix));
      std::cout << "Given ip: " << given.getip() << std::endl;
      std::cout << "Network address: " << given.getnetwork() << std::endl;
      std::cout << "Mask: " << given.getmask() << std::endl;
      std::cout << "Broadcast address: " << given.getbroadcast() << std::endl;
    } else {
      std::cerr << "valid ip-prefix string: 192.168.1.1/23" << std::endl;
      return 2;
    }
  } else if (strcmp(argv[1], "--net") == 0 && strlen(argv[2]) != 0) {
    std::string given_parameters(argv[2]);
    std::size_t found = given_parameters.find('/');
    if (found != std::string::npos) {
      std::string given_ip = given_parameters.substr(0, found);
      std::string given_prefix = given_parameters.substr(found + 1, given_parameters.size() - 1);

      if (std::stoi(given_prefix) > 32 || std::stoi(given_prefix) < 0) {
        std::cerr << "prefix must be less than 32 and greater than 0" << std::endl;
        return 3;
      }

      calc::ip_address_calculator given(given_ip, std::stoi(given_prefix));
      std::cout << "Network address: " << given.getnetwork() << std::endl;
    } else {
      std::cerr << "valid ip-prefix string: 192.168.1.1/23" << std::endl;
      return 2;
    }
  } else if (strcmp(argv[1], "--mask") == 0 && strlen(argv[2]) != 0) {
    std::string given_parameters(argv[2]);
    std::size_t found = given_parameters.find('/');
    if (found != std::string::npos) {
      std::string given_ip = given_parameters.substr(0, found);
      std::string given_prefix = given_parameters.substr(found + 1, given_parameters.size() - 1);

      if (std::stoi(given_prefix) > 32 || std::stoi(given_prefix) < 0) {
        std::cerr << "prefix must be less than 32 and greater than 0" << std::endl;
        return 3;
      }

      calc::ip_address_calculator given(given_ip, std::stoi(given_prefix));
      std::cout << "Mask: " << given.getmask() << std::endl;
    } else {
      std::cerr << "valid ip-prefix string: 192.168.1.1/23" << std::endl;
      return 2;
    }
  } else if (strcmp(argv[1], "--broadcast") == 0 && strlen(argv[2]) != 0) {
    std::string given_parameters(argv[2]);
    std::size_t found = given_parameters.find('/');
    if (found != std::string::npos) {
      std::string given_ip = given_parameters.substr(0, found);
      std::string given_prefix = given_parameters.substr(found + 1, given_parameters.size() - 1);

      if (std::stoi(given_prefix) > 32 || std::stoi(given_prefix) < 0) {
        std::cerr << "prefix must be less than 32 and greater than 0" << std::endl;
        return 3;
      }

      calc::ip_address_calculator given(given_ip, std::stoi(given_prefix));
      std::cout << "Broadcast address: " << given.getbroadcast() << std::endl;
    } else {
      std::cerr << "valid ip-prefix string: 192.168.1.1/23" << std::endl;
      return 2;
    }
  } else {
    std::cout << "type ip-calculator --help to get help" << std::endl;
    return 1;
  }
  return 0;
}
