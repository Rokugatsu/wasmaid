/**
 * @file leb128.cpp
 * @author lipingan (lipingan.dev@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "leb128.h"
namespace wasmaid {

int Leb128EncodeUint32(std::uint32_t value, std::uint8_t *bytes) {
  return Leb128EncodeUnsigned<std::uint32_t>(value, bytes);
}

int Leb128EncodeUint64(std::uint64_t value, std::uint8_t *bytes) {
  return Leb128EncodeUnsigned<std::uint64_t>(value, bytes);
}

int Leb128EncodeInt32(std::int32_t value, std::uint8_t *bytes) {
  return Leb128EncodeSigned<std::int32_t>(value, bytes);
}

int Leb128EncodeInt64(std::int64_t value, std::uint8_t *bytes) {
  return Leb128EncodeSigned<std::int64_t>(value, bytes);
}

int Leb128DecodeUint32(const std::uint8_t *bytes, std::uint32_t *result) {
  return Leb128DecodeUnsigned<std::uint32_t>(bytes, result);
}

int Leb128DecodeUint64(const std::uint8_t *bytes, std::uint64_t *result) {
  return Leb128DecodeUnsigned<std::uint64_t>(bytes, result);
}

int Leb128DecodeInt32(const std::uint8_t *bytes, std::int32_t *result) {
  return Leb128DecodeSigned<std::int32_t>(bytes, result);
}

int Leb128DecodeInt64(const std::uint8_t *bytes, std::int64_t *result) {
  return Leb128DecodeSigned<std::int64_t>(bytes, result);
}

} // namespace wasmaid
