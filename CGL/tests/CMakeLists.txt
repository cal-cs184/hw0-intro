# Original file Copyright CMU462 Fall 2015: 
# Kayvon Fatahalian, Keenan Crane,
# Sky Gao, Bryce Summers, Michael Choquette.
link_libraries(CGL)

include_directories("${PROJECT_SOURCE_DIR}/include")

link_libraries(
  glfw ${GLFW_LIBRARIES}
  glew ${GLEW_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${FREETYPE_LIBRARIES}
)

# OSD
add_executable(osd osd.cpp)

# Install tests
install(TARGETS osd DESTINATION bin/tests)
