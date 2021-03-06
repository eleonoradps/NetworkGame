
#opengl
LIST(APPEND GLES3_WRAPPER_LIBS Neko_Core ktx freetype)
if(NOT Emscripten)
    if(NOT Neko_Android)
        set(OpenGL_GL_PREFERENCE GLVND)
        find_package(OpenGL REQUIRED)
        include_directories(${OPENGL_INCLUDE_DIR})
        message("OpenGL Libraries: ${OPENGL_LIBRARIES}")
        add_compile_definitions(IMGUI_IMPL_OPENGL_LOADER_GLAD=1)
        LIST(APPEND GLES3_WRAPPER_LIBS "${OPENGL_LIBRARIES}" glad)
    endif()
endif()
if(NOT MSVC)
    if(CMAKE_MINOR_VERSION LESS 11)
        add_definitions(-DIMGUI_IMPL_OPENGL_ES3=1)
    else()
        add_compile_definitions(IMGUI_IMPL_OPENGL_ES3=1)
    endif()
endif()
if(Emscripten)
    add_compile_definitions(IMGUI_IMPL_OPENGL_LOADER_CUSTOM=1)
endif()
if(Neko_Android)
    LIST(APPEND GLES3_WRAPPER_LIBS glad)
    add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD=1)
endif()



file(GLOB_RECURSE gles3_wrapper_src include/*.h src/*.cpp)
add_library(gles3_wrapper STATIC ${gles3_wrapper_src})
target_link_libraries(gles3_wrapper PUBLIC ${GLES3_WRAPPER_LIBS})

target_include_directories(gles3_wrapper PUBLIC "include/")
neko_lib_config(gles3_wrapper)
if(Emscripten)
    set_property(TARGET gles3_wrapper APPEND_STRING PROPERTY LINK_FLAGS " -s USE_WEBGL2=1 ")
endif()
set_target_properties (gles3_wrapper PROPERTIES FOLDER Neko/Common)