# Modified from CMake Tutorial
# https://cmake.org/cmake-tutorial/

cmake_minimum_required (VERSION 2.6)
project (Tutorial)

# should we use our own math functions
option(USE_CGL "Use tutorial provided math implementation" ON)


# add the CGL library?
if (USE_CGL)
  include_directories ("${PROJECT_SOURCE_DIR}/CGL")
  link_directories ("${PROJECT_SOURCE_DIR}/CGL")
  add_subdirectory (CGL)
  set (EXTRA_LIBS ${EXTRA_LIBS} CGL)
endif ()

# add the executable
add_executable (Tutorial tutorial.cpp)
target_link_libraries (Tutorial  ${EXTRA_LIBS})

# add the install targets
install (TARGETS Tutorial DESTINATION lib)