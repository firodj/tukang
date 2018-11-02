cmake_minimum_required (VERSION 3.4)
project (tukang)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

find_package(OpenGL REQUIRED)

# Setup externals
set(GL3W_ROOT "${CMAKE_SOURCE_DIR}/gl3w")
set(GL3W_INC "${GL3W_ROOT}/include")
set(GL3W_SRC "${GL3W_ROOT}/src/gl3w.c")

if (NOT EXISTS ${GL3W_SRC})
	message(STATUS "Generating gl3w source files")
	execute_process(COMMAND python gl3w_gen.py
					WORKING_DIRECTORY ${GL3W_ROOT})
endif()

add_subdirectory(glfw)

include_directories(SYSTEM
  ${OPENGL_INCLUDE_DIR}
  ${GLFW_SOURCE_DIR}/include
  ${GL3W_INC}
  glm
  imgui
  imgui/examples
  stb
)

add_executable(tukang
  Application.cpp
  Application.hpp
  
  ${GL3W_SRC}
  
  imgui/imgui.cpp
  imgui/imgui.h
  imgui/imgui_internal.h
  imgui/imgui_draw.cpp
  imgui/imgui_widgets.cpp
  imgui/imconfig.h
  imgui/examples/imgui_impl_opengl3.cpp
  imgui/examples/imgui_impl_opengl3.h
  imgui/examples/imgui_impl_glfw.cpp
  imgui/examples/imgui_impl_glfw.h
  imgui/imgui_demo.cpp
  imgui_club/imgui_memory_editor/imgui_memory_editor.h

  stb/stb_textedit.h
  stb/stb_truetype.h
  stb/stb_rect_pack.h
  stb/stb_image.h

  glm/glm/glm.hpp
)

source_group(imgui imgui/)
source_group(glad glad/)
source_group(stb stb/)
source_group(glm glm/)

target_compile_definitions(tukang PUBLIC  -D_CRT_SECURE_NO_WARNINGS)

target_link_libraries(tukang
  ${OPENGL_LIBRARIES}
  glfw
)
