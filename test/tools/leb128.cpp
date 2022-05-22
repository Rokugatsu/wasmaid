/**
 * @file leb128.cpp
 * @author lipingan (lipingan.dev@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-05-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "wasmaid/tools/leb128.h"
#include "wasmaid/tools/byte_ops.h"
#include "llvm/Support/LEB128.h"
#include "gtest/gtest.h"
namespace wasmaid {

TEST(Leb128_Unsigned_32, case_0) {
  std::uint8_t *bs1 = new std::uint8_t[5];
  std::uint8_t *bs2 = new std::uint8_t[5];
  std::uint32_t r1;
  std::uint32_t r2;
  for (std::uint32_t value = 0; value < 10241024; value++) {
    int len1 = Leb128EncodeUint32(value, bs1);
    int len2 = llvm::encodeULEB128(value, bs2);
    EXPECT_EQ(len1, len2);
    EXPECT_TRUE(IsBytesEqual(bs1, bs2, len1));
    Leb128DecodeUint32(bs1, &r1);
    r2 = llvm::decodeULEB128(bs2);
    EXPECT_EQ(r1, r2);
  }
}

TEST(Leb128_Signed_32, case_0) {
  std::uint8_t *bs1 = new std::uint8_t[5];
  std::uint8_t *bs2 = new std::uint8_t[5];
  std::int32_t r1;
  std::int32_t r2;
  for (std::int32_t value = -10241024; value < 10241024; value++) {
    int len1 = Leb128EncodeInt32(value, bs1);
    int len2 = llvm::encodeSLEB128(value, bs2);
    EXPECT_EQ(len1, len2);
    EXPECT_TRUE(IsBytesEqual(bs1, bs2, len1));
    Leb128DecodeInt32(bs1, &r1);
    r2 = llvm::decodeSLEB128(bs2);
    EXPECT_EQ(r1, r2);
  }
}


TEST(Leb128_Unsigned_64, case_0) {
  std::uint8_t *bs1 = new std::uint8_t[5];
  std::uint8_t *bs2 = new std::uint8_t[5];
  std::uint64_t r1;
  std::uint64_t r2;
  for (std::uint64_t value = 0; value < 10241024; value++) {
    int len1 = Leb128EncodeUint64(value, bs1);
    int len2 = llvm::encodeULEB128(value, bs2);
    EXPECT_EQ(len1, len2);
    EXPECT_TRUE(IsBytesEqual(bs1, bs2, len1));
    Leb128DecodeUint64(bs1, &r1);
    r2 = llvm::decodeULEB128(bs2);
    EXPECT_EQ(r1, r2);
  }
}

TEST(Leb128_Signed_64, case_0) {
  std::uint8_t *bs1 = new std::uint8_t[10];
  std::uint8_t *bs2 = new std::uint8_t[10];
  std::int64_t r1;
  std::int64_t r2;
  for (std::int64_t value = -10241024; value < 10241024; value++) {
    int len1 = Leb128EncodeInt64(value, bs1);
    int len2 = llvm::encodeSLEB128(value, bs2);
    EXPECT_EQ(len1, len2);
    EXPECT_TRUE(IsBytesEqual(bs1, bs2, len1));
    Leb128DecodeInt64(bs1, &r1);
    r2 = llvm::decodeSLEB128(bs2);
    EXPECT_EQ(r1, r2);
  }
}

} // namespace wasmaid
