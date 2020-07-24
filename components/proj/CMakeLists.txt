project(ProjectLib)

set(SOURCES project.cc)
add_library(ProjectLib ${SOURCES})

target_link_libraries(ProjectLib UtilsLib)

target_include_directories(ProjectLib PUBLIC
                                      "impl")
