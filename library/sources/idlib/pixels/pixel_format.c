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

#include "idlib/pixels/pixel_format.h"

IDLIB_WARN_UNUSED_RETURN_VALUE() idlib_status
idlib_pixel_format_get_number_of_bytes
  (
    idlib_pixel_format pixel_format,
    size_t* number_of_bytes
  )
{
  switch (pixel_format) {
    case IDLIB_PIXEL_FORMAT_ARGB_U8:
    case IDLIB_PIXEL_FORMAT_BGRA_U8:
    case IDLIB_PIXEL_FORMAT_RGBA_U8:
      *number_of_bytes = 4;
      break;
    case IDLIB_PIXEL_FORMAT_BGR_U8:
    case IDLIB_PIXEL_FORMAT_RGB_U8:
      *number_of_bytes = 3;
      break; 
    default:
      return IDLIB_ARGUMENT_INVALID;
  };
  return IDLIB_SUCCESS;
}

IDLIB_WARN_UNUSED_RETURN_VALUE() idlib_status
idlib_pixel_format_get_number_of_components
  (
    idlib_pixel_format pixel_format,
    size_t* number_of_components
  )
{
  switch (pixel_format) {
    case IDLIB_PIXEL_FORMAT_ARGB_U8:
    case IDLIB_PIXEL_FORMAT_BGRA_U8:
    case IDLIB_PIXEL_FORMAT_RGBA_U8:
      *number_of_components = 4;
      break;
    case IDLIB_PIXEL_FORMAT_BGR_U8:
    case IDLIB_PIXEL_FORMAT_RGB_U8:
      *number_of_components = 3;
      break;
    default:
      return IDLIB_ARGUMENT_INVALID;
  };
  return IDLIB_SUCCESS;
}

IDLIB_WARN_UNUSED_RETURN_VALUE() idlib_status
idlib_pixel_format_get_default_value
  (
    idlib_pixel_format pixel_format,
    void* p
  )
{
  switch (pixel_format) {
    case IDLIB_PIXEL_FORMAT_ARGB_U8: {
      uint8_t* q = p;
      *(q + 0) = 255;
      *(q + 1) = 0;
      *(q + 2) = 0;
      *(q + 3) = 0;
      break;
    } break;
    case IDLIB_PIXEL_FORMAT_BGRA_U8:
    case IDLIB_PIXEL_FORMAT_RGBA_U8: {
      uint8_t* q = p;
      *(q + 0) = 0;
      *(q + 1) = 0;
      *(q + 2) = 0;
      *(q + 3) = 255;
    } break;
    case IDLIB_PIXEL_FORMAT_BGR_U8:
    case IDLIB_PIXEL_FORMAT_RGB_U8: {
      uint8_t* q = p;
      *(q + 0) = 0;
      *(q + 1) = 0;
      *(q + 2) = 0;
    } break;
    default:
      return IDLIB_ARGUMENT_INVALID;
  };
  return IDLIB_SUCCESS;
}
