#pragma once

#include <fmt/format.h>
#include <string>

class Logger
{
public:
    template <typename... Args>
    static void log(const std::string &fmt, Args... args)
    {
        fmt::print(fmt, args...);
    }
};