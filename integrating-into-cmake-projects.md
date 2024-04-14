# Integrate with your CMake project
The proper way to integrate *IdLib Bit Scan* with your CMake project is by using `FetchContent`:

You need to fetch *IdLib Bit Scan* and its dependency *IdLib Process*:

You can do that as follows:

```
include(FetchContent)

#######################################################################################################################

set(idlib-process.repository CACHE STRING "IdLib Process: The Git repository to check out")
if (NOT idlib-process.repository)
  set(idlib-process.repository https://github.com/michaelheilmann/idlib-process.git)
endif()

set(idlib-process.tag CACHE STRING "IdLib Process: The Git tag to check out")
if (NOT idlib-process.tag)
  set(idlib-process.tag 1.2)
endif()

set(idlib-process.source-dir CACHE STRING "IdLib Process: Path to the source directory")
if (NOT idlib-process.source-dir)
  set(idlib-process.source-dir "${CMAKE_CURRENT_BINARY_DIR}/idlib-process-1.4-src")
endif()

set(idlib-process.binary-dir CACHE STRING "IdLib Process: Path to the build directory")
if (NOT idlib-process.binary-dir)
  set(idlib-process.binary-dir "${CMAKE_CURRENT_BINARY_DIR}/idlib-process-1.4-bld")
endif()
                    
#######################################################################################################################

set(idlib-pixels.repository CACHE STRING "IdLib Pixels: The Git repository to check out")
if (NOT idlib-pixels.repository)
  set(idlib-pixels.repository https://github.com/michaelheilmann/idlib-pixels.git)
endif()

set(idlib-pixels.tag CACHE STRING "IdLib Pixels: The Git tag to check out")
if (NOT idlib-pixels.tag)
  set(idlib-pixels.tag 1.0)
endif()

set(idlib-pixels.source-dir CACHE STRING "IdLib Pixels: Path to the source directory")
if (NOT idlib-pixels.source-dir)
  set(idlib-pixels.source-dir "${CMAKE_CURRENT_BINARY_DIR}/idlib-pixels-1.0-src")
endif()

set(idlib-pixels.binary-dir CACHE STRING "IdLib Pixels: Path to the build directory")
if (NOT idlib-pixels.binary-dir)
  set(idlib-pixels.binary-dir "${CMAKE_CURRENT_BINARY_DIR}/idlib-pixels-1.0-bld")
endif()

#######################################################################################################################

FetchContent_Declare(idlib-bit-scan
                     GIT_REPOSITORY ${idlib-pixels.repository}
                     GIT_TAG ${idlib-pixels.tag}
                     SOURCE_DIR ${idlib-pixels.source-dir}
                     BINARY_DIR ${idlib-pixels.binary-dir})

```

Now simply add
```
FetchContent_MakeAvailable(idlib-bit-scan)
```
And you can use *IdLib Pixels* by linking the library target `idlib-pixels` to a target `<target>`
```
target_link_libraries(<target> idlib-pixels)
```
and by adding the include directive  
```
#include "idlib/pixels.h"
```
in your C files.
