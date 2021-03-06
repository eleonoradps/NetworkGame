message("Hello Emscripten")
set(Emscripten ON CACHE BOOL "")

add_compile_definitions(EMSCRIPTEN=1)
add_compile_definitions(__EMSCRIPTEN__=1)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --emrun -s EXPORT_ALL=1" CACHE STRING "")

set(NEKO_LIBS_FLAGS "")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".a")

set(Neko_SameThread BOOL ON CACHE FORCE BOOL "")

set(RUN_HAVE_STD_REGEX 0 OFF CACHE INTERNAL "")
set(CMAKE_CROSSCOMPILING BOOL TRUE CACHE FORCE BOOL "")