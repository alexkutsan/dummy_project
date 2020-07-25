
set( boost_URL "http://sourceforge.net/projects/boost/files/boost/1.63.0/boost_1_63_0.tar.bz2" )
#set( boost_SHA1 "9f1dd4fa364a3e3156a77dc17aa562ef06404ff6" )
set( boost_INSTALL ${CMAKE_CURRENT_BINARY_DIR}/third_party/boost )
set( boost_INCLUDE_DIR ${boost_INSTALL}/include )
set( boost_LIB_DIR ${boost_INSTALL}/lib )
set(boost_LIBRARY_SUFFIX ".a")

ExternalProject_Add( external_boost
        PREFIX boost
        URL ${boost_URL}
#        URL_HASH SHA1=${boost_SHA1}
        BUILD_IN_SOURCE 1
        CONFIGURE_COMMAND ./bootstrap.sh
            --with-libraries=system
            --with-libraries=log
            --with-libraries=thread
            --with-libraries=filesystem
            --prefix=<INSTALL_DIR>
        BUILD_COMMAND
        ./b2 install link=static variant=release threading=multi runtime-link=static
        INSTALL_COMMAND ""
        INSTALL_DIR ${boost_INSTALL} )
file(MAKE_DIRECTORY ${boost_INCLUDE_DIR})

add_library(boost::system STATIC IMPORTED )
set_property( TARGET boost::system PROPERTY GENERATED TRUE )
set_property( TARGET boost::system PROPERTY IMPORTED_LOCATION ${boost_LIB_DIR}/libboost_system${boost_LIBRARY_SUFFIX} )
set_property( TARGET boost::system PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${boost_INCLUDE_DIR} )
add_dependencies( boost::system external_boost )

add_library(boost::log STATIC IMPORTED )
set_property( TARGET boost::log PROPERTY GENERATED TRUE )
set_property( TARGET boost::log PROPERTY IMPORTED_LOCATION ${boost_LIB_DIR}/libboost_log${boost_LIBRARY_SUFFIX})
set_property( TARGET boost::log PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${boost_INCLUDE_DIR} )
add_dependencies( boost::log external_boost )

add_library(boost::log_setup STATIC IMPORTED )
set_property( TARGET boost::log_setup PROPERTY GENERATED TRUE )
set_property( TARGET boost::log_setup PROPERTY IMPORTED_LOCATION ${boost_LIB_DIR}/libboost_log_setup${boost_LIBRARY_SUFFIX} )
set_property( TARGET boost::log_setup PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${boost_INCLUDE_DIR} )
add_dependencies( boost::log_setup external_boost )

add_library(boost::thread STATIC IMPORTED )
set_property( TARGET boost::thread PROPERTY GENERATED TRUE )
set_property( TARGET boost::thread PROPERTY IMPORTED_LOCATION ${boost_LIB_DIR}/libboost_thread${boost_LIBRARY_SUFFIX} )
set_property( TARGET boost::thread PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${boost_INCLUDE_DIR} )
add_dependencies( boost::thread external_boost )

add_library(boost::filesystem STATIC IMPORTED )
set_property( TARGET boost::filesystem PROPERTY GENERATED TRUE )
set_property( TARGET boost::filesystem PROPERTY IMPORTED_LOCATION ${boost_LIB_DIR}/libboost_filesystem${boost_LIBRARY_SUFFIX} )
set_property( TARGET boost::filesystem PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${boost_INCLUDE_DIR} )
add_dependencies( boost::filesystem external_boost )
