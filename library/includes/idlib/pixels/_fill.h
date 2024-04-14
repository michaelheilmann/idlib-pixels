#if !defined(IDLIB_PIXELS_FILL_H_INCLUDED)
#define IDLIB_PIXELS_FILL_H_INCLUDED

#include "idlib/math.h"
#include "idlib/pixels/pixel_buffer.h"
#include "idlib/pixels/_pixel_rectangle.h"

static inline idlib_status
_convert_color_3_u8
  (
    uint8_t* target,
    idlib_pixel_format pixel_format,
    idlib_color_3_u8 const* source
  )
{
  switch (pixel_format) {
    case IDLIB_PIXEL_FORMAT_ARGB_U8: {
      target[0] = UINT8_C(255);
      target[1] = source->r;
      target[2] = source->g;
      target[3] = source->b;
      return IDLIB_SUCCESS;
    } break;
    case IDLIB_PIXEL_FORMAT_BGR_U8: {
      target[0] = source->b;
      target[1] = source->g;
      target[2] = source->r;
      target[3] = UINT8_C(0);
      return IDLIB_SUCCESS;
    } break;
    case IDLIB_PIXEL_FORMAT_BGRA_U8: {
      target[0] = source->b;
      target[1] = source->g;
      target[2] = source->r;
      target[3] = UINT8_C(255);
      return IDLIB_SUCCESS;
    } break;
    case IDLIB_PIXEL_FORMAT_RGB_U8: {
      target[0] = source->r;
      target[1] = source->g;
      target[2] = source->b;
      target[3] = UINT8_C(0);
      return IDLIB_SUCCESS;
    } break;
    case IDLIB_PIXEL_FORMAT_RGBA_U8: {
      target[0] = source->r;
      target[1] = source->g;
      target[2] = source->b;
      target[3] = UINT8_C(255);
      return IDLIB_SUCCESS;
    } break;
    default: {
      return IDLIB_ARGUMENT_INVALID;
    } break;
  };
}

/// Fill the pixel rectangle in a pixel buffer with the specified color.
/// If the image has an alpha channel then this function assumes a fill value of 255 (fully opaque).
static inline idlib_status
_fill
  (
    idlib_pixel_buffer* pixel_buffer,
    _pixel_rectangle const* fill_rectangle,
    uint8_t const* fill_color
  )
{
  _pixel_rectangle clipped_fill_rectangle = *fill_rectangle, canvas_rectangle;
  canvas_rectangle.x = 0;
  canvas_rectangle.y = 0;
  canvas_rectangle.w = pixel_buffer->width;
  canvas_rectangle.h = pixel_buffer->height;
  _pixel_rectangle_intersect(&clipped_fill_rectangle, &canvas_rectangle, &clipped_fill_rectangle);
  if (_pixel_rectangle_is_empty(&clipped_fill_rectangle)) {
    return IDLIB_SUCCESS;
  }
  
  size_t number_of_bytes_per_pixel;
  idlib_status status;
  status = idlib_pixel_format_get_number_of_bytes(pixel_buffer->pixel_format, &number_of_bytes_per_pixel);
  if (status) {
    return status;
  }
                                         
  uint8_t* target = pixel_buffer->bytes;

  target += clipped_fill_rectangle.y * (number_of_bytes_per_pixel * pixel_buffer->width + pixel_buffer->padding);
  for (int32_t y = clipped_fill_rectangle.y, yy = clipped_fill_rectangle.y + clipped_fill_rectangle.h; y < yy; ++y) {
    target += clipped_fill_rectangle.x * number_of_bytes_per_pixel;
    for (int32_t x = clipped_fill_rectangle.x, xx = clipped_fill_rectangle.x + clipped_fill_rectangle.w; x < xx; ++x) {
      for (int32_t i = 0; i < number_of_bytes_per_pixel; ++i) {
        (*target) = fill_color[i];
        target++;
      }
    }
    // Advance to next line.
    target += pixel_buffer->padding;
  }
  return IDLIB_SUCCESS;
}

#endif // IDLIB_PIXELS_FILL_H_INCLUDED
