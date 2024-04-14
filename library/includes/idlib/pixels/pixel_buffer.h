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

#if !defined(IDLIB_PIXELS_PIXEL_BUFFER_H_INCLUDED)
#define IDLIB_PIXELS_PIXEL_BUFFER_H_INCLUDED

#include "idlib/pixels/pixel_format.h"

typedef struct idlib_pixel_buffer {
  void* bytes;
  int32_t width;
  int32_t height;
  int32_t padding;
  idlib_pixel_format pixel_format;
} idlib_pixel_buffer;

IDLIB_WARN_UNUSED_RETURN_VALUE() idlib_status
idlib_pixel_buffer_initialize
  (
    idlib_pixel_buffer* pixel_buffer,
    int32_t width,
    int32_t height,
    int32_t padding,
    idlib_pixel_format pixel_format
  );

IDLIB_WARN_UNUSED_RETURN_VALUE() idlib_status
idlib_pixel_buffer_uninitialize
  (
    idlib_pixel_buffer* pixel_buffer
  );

#endif // IDLIB_PIXELS_PIXEL_BUFFER_H_INCLUDED
