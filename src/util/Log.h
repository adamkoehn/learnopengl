#ifndef INCLUDE_LOG_H
#define INCLUDE_LOG_H

#include <iostream>

class Log
{
public:
    static void info(const char *message) { std::cout << "INFO: " << message << std::endl; }
    static void error(const char *message) { std::cout << "ERROR: " << message << std::endl; }
};

#endif