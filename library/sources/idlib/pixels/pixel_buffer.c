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

#include "idlib/pixels/pixel_buffer.h"

#include <malloc.h>
#include "idlib/math.h"
#include "idlib/pixels/_pixel_rectangle.h"
#include "idlib/pixels/_fill.h"

IDLIB_WARN_UNUSED_RETURN_VALUE() idlib_status
idlib_pixel_buffer_initialize
  (
    idlib_pixel_buffer* pixel_buffer,
    int32_t width,
    int32_t height,
    int32_t padding,
    idlib_pixel_format pixel_format
  )
{
  if (!pixel_buffer || width < 0 || height < 0 || padding < 0) {
    return IDLIB_ARGUMENT_INVALID;
  }
  size_t number_of_bytes_per_pixel;
  idlib_status status = idlib_pixel_format_get_number_of_bytes(pixel_format, &number_of_bytes_per_pixel);
  if (status) {
    return status;
  }
  int32_t number_of_bytes;
  if (idlib_safe_mul_i32(&number_of_bytes, width, (int32_t)number_of_bytes_per_pixel)) {
    return IDLIB_ARGUMENT_INVALID;
  }
  if (idlib_safe_add_i32(&number_of_bytes, number_of_bytes, padding)) {
    return IDLIB_ARGUMENT_INVALID;
  }
  if (idlib_safe_mul_i32(&number_of_bytes, number_of_bytes, height)) {
    return IDLIB_ARGUMENT_INVALID;
  }
  void* bytes = malloc(number_of_bytes > 0 ? number_of_bytes : 1);
  if (!bytes) {
    return IDLIB_ALLOCATION_FAILED;
  }
  pixel_buffer->bytes = bytes;
  pixel_buffer->width = width;
  pixel_buffer->height = height;
  pixel_buffer->padding = padding;
  pixel_buffer->pixel_format = pixel_format;
  // Fill the image with the default value for the specified pixel format.
  uint8_t fill_color[4];
  status = idlib_pixel_format_get_default_value(pixel_buffer->pixel_format, &fill_color[0]);
  if (status) {
    free(pixel_buffer->bytes);
    return status;
  }
  _pixel_rectangle fill_rectangle;
  fill_rectangle.x = 0;
  fill_rectangle.y = 0;
  fill_rectangle.w = pixel_buffer->width;
  fill_rectangle.h = pixel_buffer->height;
  status = _fill(pixel_buffer, &fill_rectangle, fill_color);
  if (status) {
    free(pixel_buffer->bytes);
    return status;
  }
  return IDLIB_SUCCESS;
}

IDLIB_WARN_UNUSED_RETURN_VALUE() idlib_status
idlib_pixel_buffer_uninitialize
  (
    idlib_pixel_buffer* pixel_buffer
  )
{
  if (!pixel_buffer) {
    return IDLIB_ARGUMENT_INVALID;
  }
  free(pixel_buffer->bytes);
  pixel_buffer->bytes = NULL;
  return IDLIB_SUCCESS;
}
