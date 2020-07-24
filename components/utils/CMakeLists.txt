project(ProjectLib)

set(SOURCES proj_logger.cc std_logger.cc)
add_library(UtilsLib ${SOURCES})

target_include_directories(UtilsLib PUBLIC
                                      "include")
