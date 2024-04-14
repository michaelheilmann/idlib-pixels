#if !defined(IDLIB_PIXELS_RECTANGLE_H_INCLUDED)
#define IDLIB_PIXELS_RECTANGLE_H_INCLUDED

#include <stdbool.h>
#include <inttypes.h>

// A pixel rectangle is considered as empty if w or h is negative or 0.
typedef struct _pixel_rectangle {
  int32_t x, y;
  int32_t w, h;
} _pixel_rectangle;

static inline bool
_pixel_rectangle_is_empty
  (
    _pixel_rectangle const* a
  )
{
  return a->w <= 0
      || a->h <= 0;
}

static inline void
_pixel_rectangle_intersect
  (
    _pixel_rectangle const* a,
    _pixel_rectangle const* b,
    _pixel_rectangle* c
  )
{
  if (_pixel_rectangle_is_empty(a) || _pixel_rectangle_is_empty(b)) {
    c->x = a->x;
    c->y = a->y;
    c->w = 0;
    c->h = 0;
    return;
  }
  int32_t amin, bmin, amax, bmax;
  
  // horizontal clip
  amin = a->x;
  bmin = b->x;
  amax = a->x + a->w;
  bmax = b->x + b->w;
  if (bmin > amin) {
    amin = bmin;
  }
  c->x = amin;
  if (bmax < amax) {
    amax = bmax;
  }
  c->w = amax - amin;
  
  // vertical clip
  amin = a->y;
  bmin = b->y;
  amax = a->y + a->h;
  bmax = b->y + b->h;
  if (bmin > amin) {
    amin = bmin;
  }
  c->y = amin;
  if (bmax < amax) {
    amax = bmax;
  }
  c->h = amax - amin;
}

#endif // IDLIB_PIXELS_RECTANGLE_H_INCLUDED
