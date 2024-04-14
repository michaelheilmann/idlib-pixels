# `idllib_pixel_buffer_initialize`

## C Signature
```
idlib_status
idlib_pixel_buffer_initialize
  (
    idlib_pixel_buffer* pixel_buffer,
    int32_t width,
    int32_t height,
    int32_t padding,
    idlib_pixel_format pixel_format
  )
```

## Description
Initialize an `idlib_pixel_buffer` object.

## Parameters
- `pixel_buffer` A pointer to the `idlib_pixel_buffer` object.
- `width` The width, in pixels. Must be non-negative.
- `height` The height, in pixels. Must be non-negative.
- `padding` The padding, in pixels. Must be non-negative.
- `pixel_format` The pixel format.

## Return value
`IDLIB_SUCCESS` on success. A non-zero `idlib_status` value on failure.

## Remarks
The pixels are initialized with the default value for the specified pixel format `pixel_format`.
