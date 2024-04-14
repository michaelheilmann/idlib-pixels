# `idllib_pixel_buffer_uninitialize`

## C Signature
```
idlib_status
idlib_pixel_buffer_uninitialize
  (
    idlib_pixel_buffer* pixel_buffer
  )
```

## Description
Uninitialize an `idlib_pixel_buffer` object.

## Parameters
- `pixel_buffer` A pointer to the `idlib_pixel_buffer` object.

## Return value
`IDLIB_SUCCESS` on success. A non-zero `idlib_status` value on failure.
