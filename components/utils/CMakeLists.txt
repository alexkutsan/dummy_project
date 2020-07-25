project(ProjectLib)
SET(Boost_USE_STATIC_LIBS ON)
set(SOURCES proj_logger.cc
            std_logger.cc
            log4cxxlogger.cc
            boostlogger.cc)
add_library(UtilsLib ${SOURCES})

#SET(Boost_USE_STATIC_LIBS 1)
add_definitions(-DBOOST_LOG_DYN_LINK)
#// This is available in all editors.
FIND_PACKAGE( Boost 1.65.1 COMPONENTS log log_setup system thread REQUIRED )

target_include_directories(UtilsLib PUBLIC
                                      "impl"
                                      ${Boost_INCLUDE_DIR})


target_link_libraries(UtilsLib PUBLIC log4cxx)
target_link_libraries(UtilsLib PUBLIC
  boost_log
  boost_log_setup
  boost_system
  boost_thread
  pthread
  )

#target_link_libraries(UtilsLib PUBLIC Boost::log )
#TARGET_LINK_LIBRARIES(UtilsLib LINK_PUBLIC ${Boost_LIBRARIES} )
