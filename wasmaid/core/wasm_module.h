/**
 * @file wasm_module.h
 * @author lipingan (lipingan.dev@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-05-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __WASMAID_CORE_WASM_MODULE_H__
#define __WASMAID_CORE_WASM_MODULE_H__
#include "wasm_types.h"
namespace wasmaid {
// Definitions are referenced with zero-based indices.
typedef u32 typeidx;
typedef u32 funcidx;
typedef u32 tableidx;
typedef u32 memidx;
typedef u32 globalidx;
typedef u32 elemidx;
typedef u32 dataidx;
typedef u32 localidx;
typedef u32 labelidx;
} // namespace wasmaid

#endif