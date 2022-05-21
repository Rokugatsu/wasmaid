/**
 * @file wasm_types.h
 * @author lipingan (lipingan.dev@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */

// This implementation is according to
// https://webassembly.github.io/spec/core/syntax/types.html#

#ifndef __WASMAID_CORE_WASM_TYPES_H__
#define __WASMAID_CORE_WASM_TYPES_H__
#include "cstdint"
#include "vector"
namespace wasmaid {
// bytes ::= 0x00|...|0xFF
typedef std::uint8_t byte;

// Integers
typedef std::int32_t s32;
typedef std::int64_t s64;
typedef std::uint32_t u32;
typedef std::uint64_t u64;
typedef u32 i32;
typedef u64 i64;
// Floating point
typedef float f32;
typedef double f64;

//  vectors used by SIMD instructions. The C++ standard does not specify widths
//  of 128-bit integer type.
typedef __uint128_t v128; // think twice.

typedef byte TypeId;
constexpr TypeId kI32TypeId = 0x7F;
constexpr TypeId kI64TypeId = 0x7E;
constexpr TypeId KF32TypeId = 0x7D;
constexpr TypeId kF64TypeId = 0x7C;
constexpr TypeId kV128TypeId = 0x7B;
constexpr TypeId kFuncRefTypeId = 0x70;
constexpr TypeId kExternRefTypeId = 0x6F;
constexpr TypeId kFunctionTypeId = 0x60;
constexpr TypeId kResultTypeId = 0x40;

// 0x7A-0x71 reserved
class Reference {
  void *address;
};

union Slot {
  Reference ref_val;
  i32 i32_val;
  i64 i64_val;
  f32 f32_val;
  f64 f64_val;
  v128 v128_val;
};
class Value {
  TypeId id_;

  Slot s_;
};

class Result {
  std::vector<Value> values_;
};

class Function {
  Result results_;
  Result paramters_;
};

class Limits {
  u32 max_;
  u32 min_;
};

class Table {};

class Global {
  bool is_mutable_;
  Value val_;
};

class External {};

} // namespace wasmaid

#endif