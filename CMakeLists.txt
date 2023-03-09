cmake_minimum_required (VERSION 3.11)

# set(CMAKE_CXX_COMPILER "/opt/gcc-latest/bin/g++")

include(FetchContent)

# --- Fetch fmt -----------------------------------------------------------

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG 9.0.0
)

FetchContent_GetProperties(fmt)
if(NOT fmt_POPULATED)
  FetchContent_Populate(fmt)
  add_subdirectory(${fmt_SOURCE_DIR} ${fmt_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------

project(cl-cpp
  LANGUAGES CXX # CUDA
  VERSION 1.0.0
)


add_executable(cl-cpp main.cpp)
set_property(TARGET cl-cpp PROPERTY CXX_STANDARD 20)
target_include_directories(cl-cpp PRIVATE src)

target_link_libraries(cl-cpp
#   PRIVATE range-v3
  PRIVATE fmt
)

# add_executable(tests tests/tests.cpp)
# target_link_libraries(tests
#   PRIVATE ut
#   PRIVATE fmt)
# target_include_directories(tests PRIVATE src)
# target_link_libraries(tests PRIVATE range-v3)
