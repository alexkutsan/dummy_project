#ifndef EXTERNAL_LOGGER_H
#define EXTERNAL_LOGGER_H
#ifdef USE_BOOST_LOGGER
#include "logger/boostlogger.h"
#endif
#ifdef USE_LOG4CXX_LOGGER
#include "logger/log4cxxlogger.h"
#endif
#ifdef USE_STD_LOGGER
#include "logger/std_logger.h"
#endif
#endif // EXTERNAL_LOGGER_H
