project(ProjectLib)
SET(Boost_USE_STATIC_LIBS ON)
set(SOURCES proj_logger.cc
            std_logger.cc
            log4cxxlogger.cc
            boostlogger.cc)
add_library(UtilsLib ${SOURCES})

target_include_directories(UtilsLib PUBLIC
                                      "impl")

target_link_libraries(UtilsLib PUBLIC
  log4cxx::log4cxx
  boost::log_setup
  boost::log
  boost::thread
  boost::system
  boost::filesystem
  pthread
)
