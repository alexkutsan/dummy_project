project(ProjectLib)

set(SOURCES proj_logger.cc std_logger.cc log4cxxlogger.cc)
add_library(UtilsLib ${SOURCES})

#FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
#INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )


target_include_directories(UtilsLib PUBLIC
                                      "impl")


target_link_libraries(UtilsLib PUBLIC log4cxx)
target_link_libraries(UtilsLib PUBLIC Boost::log)
#TARGET_LINK_LIBRARIES(UtilsLib LINK_PUBLIC ${Boost_LIBRARIES} )
