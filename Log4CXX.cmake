
#set( boost_URL "http://sourceforge.net/projects/boost/files/boost/1.73.0/boost_1_73_0.tar.bz2" )
#set( boost_SHA1 "9f1dd4fa364a3e3156a77dc17aa562ef06404ff6" )
set( log4cxx_INSTALL ${CMAKE_CURRENT_BINARY_DIR}/third_party/logging-log4cxx )
set( log4cxx_INCLUDE_DIR ${log4cxx_INSTALL}/include )
set( log4cxx_LIB_DIR ${log4cxx_INSTALL}/lib )

ExternalProject_Add(logging-log4cxx
  PREFIX third_party/logging-log4cxx
  GIT_REPOSITORY    https://github.com/apache/logging-log4cxx
  GIT_TAG           master
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND cmake . -D CMAKE_INSTALL_PREFIX=${log4cxx_INSTALL}
  BUILD_COMMAND     make
  INSTALL_COMMAND   make install
  INSTALL_DIR ${log4cxx_INSTALL}
)
file(MAKE_DIRECTORY ${log4cxx_INCLUDE_DIR})

add_library(log4cxx::log4cxx STATIC IMPORTED )
set_property( TARGET log4cxx::log4cxx PROPERTY GENERATED TRUE )
set_property( TARGET log4cxx::log4cxx PROPERTY IMPORTED_LOCATION ${log4cxx_LIB_DIR}/liblog4cxx.so)
set_property( TARGET log4cxx::log4cxx PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${log4cxx_INSTALL} )
add_dependencies( log4cxx::log4cxx logging-log4cxx )

