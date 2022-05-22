/**
 * @file byte_ops.h
 * @author lipingan (lipingan.dev@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-05-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __WASMAID_TOOLS_BYTE_OPS_H__
#define __WASMAID_TOOLS_BYTE_OPS_H__

#include "cstdint"
namespace wasmaid {

bool IsBytesEqual(uint8_t *bs1, uint8_t *bs2, std::size_t length);

void DumpBytes(std::uint8_t *address, std::size_t length);

} // namespace wasmaid

#endif