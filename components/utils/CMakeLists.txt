project(ProjectLib)
SET(Boost_USE_STATIC_LIBS ON)
set(SOURCES
            logger_impl.cc
            $<$<STREQUAL:${LOGGER},log4cxx>:log4cxxlogger.cc>
            $<$<STREQUAL:${LOGGER},boost>:boostlogger.cc>
            $<$<STREQUAL:${LOGGER},std>:std_logger.cc>
            )
add_library(UtilsLib ${SOURCES})


target_include_directories(UtilsLib PUBLIC
                                      "impl")

target_link_libraries(UtilsLib PUBLIC
  $<$<STREQUAL:${LOGGER},log4cxx>:log4cxx::log4cxx>
  $<$<STREQUAL:${LOGGER},boost>:boost::log_setup>
  $<$<STREQUAL:${LOGGER},boost>:boost::log>
  $<$<STREQUAL:${LOGGER},boost>:boost::thread>
  $<$<STREQUAL:${LOGGER},boost>:boost::system>
  $<$<STREQUAL:${LOGGER},boost>:boost::filesystem>
  $<$<STREQUAL:${LOGGER},boost>:pthread>
)
