#ifndef SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_REVMOCKUTILITIES_H_
#define SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_REVMOCKUTILITIES_H_

#include <iostream>

#ifndef __FUNCTION_NAME__
#ifdef WIN32
#define __FUNCTION_NAME__ __FUNCTION__
#else
#define __FUNCTION_NAME__ __func__
#endif
#endif

#define LOG_UNSUPPORTED_CAN_FUNC(x)                                           \
    std::cerr << __FUNCTION_NAME__ << "(" << __FILE__ ":" << __LINE__ << ") " \
              << " Unsupported" << x << std::endl;

#ifdef _MSC_VER
#define EXPORT_ __declspec(dllexport)
#else
#define EXPORT_
#endif

#endif // SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_REVMOCKUTILITIES_H_
