#pragma once  
#include <string>
#include <cstdio>
#include <cstdarg>

namespace azmq{ 
namespace util {
/**
 * std::string format
 */
template<typename = void>
std::string formatv(const char * format, va_list args)
{
    std::string s;

    if (format && *format)
    {
        // under windows and linux system,std::vsnprintf(nullptr, 0, format, args)
        // can get the need buffer len for the output,
        va_list args_copy;

        va_copy(args_copy, args);
        int len = std::vsnprintf(nullptr, 0, format, args_copy);

        if (len > 0)
        {
            s.resize(len);

            va_copy(args_copy, args);
            std::vsprintf((char*)s.data(), format, args_copy);
        }
    }

    return s;
}
/**
 * std::string format
 */
template<typename = void>
std::string format(const char * format, ...)
{
    std::string s;

    if (format && *format)
    {
        // under windows and linux system,std::vsnprintf(nullptr, 0, format, args)
        // can get the need buffer len for the output,
        va_list args;
        va_start(args, format);

        s = formatv(format, args);

        va_end(args);
    }

    return s;
}

}
}