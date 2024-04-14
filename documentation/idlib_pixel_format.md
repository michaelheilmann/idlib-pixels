# `idllib_pixel_format`

## C Signature
```
typedef enum idlib_pixel_format {
  ...
} idlib_pixel_format;
```

## Description
An enumeration of pixel formats.

## Elements

#### `IDLIB_PIXEL_FORMAT_ABGR_U8``
Format of a pixel consisting of four components, alpha, blue, green, and red in that order.
Each component is an `uint8_t` value where `0` denotes minimum intensity and `255` denotes maximum intensity.
The default value is opaque black `(255,0,0,0)`.

#### `IDLIB_PIXEL_FORMAT_ARGB_U8`
Format of a pixel consisting of four components, alpha, red, green, and blue in that order.
Each component is an `uint8_t` value where `0` denotes minimum intensity and `255` denotes maximum intensity.
The default value is opaque black `(255,0,0,0)`.

#### `IDLIB_PIXEL_FORMAT_BGR_U8`
Format of a pixel consisting of three components, blue, green, and red in that order.
Each component is an `uint8_t` value where `0` denotes minimum intensity and `255` denotes maximum intensity.
The default value is opaque black `(0,0,0)`.

#### `IDLIB_PIXEL_FORMAT_BGRA_U8`
Format of a pixel consisting of four components, blue, green, red, and alpha in that order.
Each component is an `uint8_t` value where `0` denotes minimum intensity and `255` denotes maximum intensity.
The default value is opaque black `(0,0,0,255)`.

#### `IDLIB_PIXEL_FORMAT_RGB_U8`
Format of a pixel consisting of three components, red, green, and blue in that order.
Each component is an `uint8_t` value where `0` denotes minimum intensity and `255` denotes maximum intensity.
The default value is opaque black `(0,0,0)`.

#### `IDLIB_PIXEL_FORMAT_RGBA_U8`
Format of a pixel consisting of four components, red, green, blue, and alpha in that order.
Each component is an `uint8_t` value where `0` denotes minimum intensity and `255` denotes maximum intensity.
The default value is opaque black `(0,0,0,255)`.
