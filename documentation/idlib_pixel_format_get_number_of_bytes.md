# `idllib_pixel_format_get_number_of_bytes`

## C Signature
```
idlib_status
idllib_pixel_format_get_number_of_bytes
  (
    idlib_pixel_format pixel_format
    size_t *number_of_bytes
  )
```

## Description
Get the number of components of an `idlib_pixel_format`.

## Parameters
- `pixel_format` The pixel format.
- `number_of_bytes` A pointer to a `size_t` variable.

## Success
`*number_of_bytes` was assigned the number of bytes of a pixel of the specified pixel format.

## Return value
`IDLIB_SUCCESS` on success. A non-zero `idlib_status` value on failure.
