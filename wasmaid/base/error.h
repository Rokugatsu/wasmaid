/**
 * @file error.h
 * @author lipingan (lipingan.dev@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __WASMAID_BASE_ERROR_H__
#define __WASMAID_BASE_ERROR_H__
namespace wasmaid {
enum ErrorCode : int {
  SUCCESS = 0,
  NULL_POINTER = 1,
  INTEGER_OVERFLOW = 2,
  ARRAY_OUT_OF_BOUNDS = 3
  // TODO
};
} // namespace wasmaid

#endif