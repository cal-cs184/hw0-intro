add_library(CGL vector2D.cpp vector2D.h)

install (TARGETS CGL DESTINATION lib)
install (FILES vector2D.h DESTINATION include)
