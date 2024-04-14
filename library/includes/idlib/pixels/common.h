/*
  IdLib Pixels
  Copyright (C) 2018-2024 Michael Heilmann. All rights reserved.

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#if !defined(IDLIB_PIXELS_COMMON_H_INCLUDED)
#define IDLIB_PIXELS_COMMON_H_INCLUDED

#include "idlib/pixels/configure.h"
#include "idlib/process.h"

#if (IDLIB_COMPILER_C == IDLIB_COMPILER_C_GCC)
  #define IDLIB_WARN_UNUSED_RETURN_VALUE() __attribute__((warn_unused_result))
#elif IDLIB_COMPILER_C == IDLIB_COMPILER_C_MSVC
  #include <sal.h>
  #define IDLIB_WARN_UNUSED_RETURN_VALUE() _Check_return_
#else
  #define IDLIB_WARN_UNUSED_RETURN_VALUE()
#endif

static inline IDLIB_WARN_UNUSED_RETURN_VALUE() idlib_status
idlib_safe_add_i32
  (
    int32_t* RETURN,
    int32_t x,
    int32_t y
  )
{
  int64_t temporary = (int64_t)x + (int64_t)y;
  if (temporary < INT32_MIN || temporary > INT32_MAX) {
    return IDLIB_OVERFLOW;
  }
  *RETURN = (int32_t)temporary;
  return IDLIB_SUCCESS;
}

static inline IDLIB_WARN_UNUSED_RETURN_VALUE() idlib_status
idlib_safe_mul_i32
  (
    int32_t* RETURN,
    int32_t x,
    int32_t y
  )
{
  int64_t temporary = (int64_t)x * (int64_t)y;
  if (temporary < INT32_MIN || temporary > INT32_MAX) {
    return IDLIB_OVERFLOW;
  }
  *RETURN = (int32_t)temporary;
  return IDLIB_SUCCESS;
}

#endif // IDLIB_PIXELS_COMMON_H_INCLUDED
