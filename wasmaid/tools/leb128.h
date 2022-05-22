/**
 * @file leb128.h
 * @author lipingan (lipingan.dev@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __WASMAID_TOOLS_LEB128_H__
#define __WASMAID_TOOLS_LEB128_H__
#include "cstdint"

namespace wasmaid {

int Leb128EncodeUint32(std::uint32_t value, std::uint8_t *bytes);

int Leb128EncodeUint64(std::uint64_t value, std::uint8_t *bytes);

int Leb128EncodeInt32(std::int32_t value, std::uint8_t *bytes);

int Leb128EncodeInt64(std::int64_t value, std::uint8_t *bytes);

int Leb128DecodeUint32(const std::uint8_t *bytes, std::uint32_t *result);

int Leb128DecodeUint64(const std::uint8_t *bytes, std::uint64_t *result);

int Leb128DecodeInt32(const std::uint8_t *bytes, std::int32_t *result);

int Leb128DecodeInt64(const std::uint8_t *bytes, std::int64_t *result);

template <typename Tp> int Leb128EncodeUnsigned(Tp value, std::uint8_t *bytes) {
  if (bytes) {
    bool has_next;
    std::uint8_t *p = bytes;
    do {
      std::uint8_t seg = value & 0x7F;
      value >>= 7;
      has_next = (value != 0);
      if (has_next) {
        seg |= 0x80;
      }
      *p = seg;
      ++p;
    } while (has_next);
    return static_cast<int>(p - bytes);
  }
  return -1;
}

template <typename Tp> int Leb128EncodeSigned(Tp value, std::uint8_t *bytes) {
  if (bytes) {
    bool has_next;
    std::uint8_t *p = bytes;
    do {
      std::uint8_t seg = value & 0X7F;
      value >>= 7;
      has_next = !((((value == 0) && ((seg & 0x40) == 0)) ||
                    ((value == -1) && ((seg & 0x40) != 0))));
      if (has_next) {
        seg |= 0x80;
      }
      *p = seg;
      ++p;
    } while (has_next);
    return static_cast<int>(p - bytes);
  }
  return -1;
}

template <typename Tp>
int Leb128DecodeUnsigned(const std::uint8_t *bytes, Tp *result) {
  if (bytes && result) {
    const std::uint8_t *p = bytes;
    Tp value{0};
    unsigned shift{0};
    do {
      Tp seg = *p & 0x7F;
      value |= (seg << shift);
      shift += 7;
    } while ((*p++ >= 0x80)); // * first and then ++.
    *result = value;
    return (p - bytes);
  }
  return -1;
}

template <typename Tp>
int Leb128DecodeSigned(const std::uint8_t *bytes, Tp *result) {
  if (bytes && result) {
    const std::uint8_t *p = bytes;
    std::uint8_t byte;
    Tp value{0};
    unsigned shift{0};
    bool has_next = true;
    do {
      byte = *p;
      Tp seg = byte & 0x7F;
      value |= (seg << shift);
      shift += 7;
      ++p;
    } while (byte >= 0x80);
    if (byte & 0x40) {
      value |= std::uintmax_t(-1) << shift;
    }
    *result = value;
    return (p - bytes);
  }
  return -1;
}
} // namespace wasmaid

#endif