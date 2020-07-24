project(SharedLib)

set(SOURCES shared_lib.cc)
add_library(SharedLib ${SOURCES})

target_link_libraries(SharedLib UtilsLib)

target_include_directories(SharedLib PUBLIC
                                     "impl")
