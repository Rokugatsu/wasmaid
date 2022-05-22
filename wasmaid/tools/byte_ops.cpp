/**
 * @file byte_ops.cpp
 * @author lipingan (lipingan.dev@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-05-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "byte_ops.h"
#include "iostream"
namespace wasmaid {
bool IsBytesEqual(uint8_t *bs1, uint8_t *bs2, std::size_t length) {
  for (std::size_t i = 0; i < length; i++) {
    if (bs1[i] != bs2[i])
      return false;
  }
  return true;
}
void DumpBytes(std::uint8_t *address, std::size_t length) {
  std::size_t i = 0;
  std::printf("[start address: %p]", address);
  for (; i < length; ++i) {
    std::printf(" %2x ", address[i]);
  }
  std::printf("[end address: %p]", address + i);
}
} // namespace wasmaid
