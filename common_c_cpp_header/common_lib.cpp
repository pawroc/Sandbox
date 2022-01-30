#include <common_lib.h>
#include <stdarg.h>
#include <cstdint>
#include <cstdio>
#include <ctime>

class Logger {
public:
    static void log(const char* file, uint32_t line, const char* fmt, va_list args1);
};

void Logger::log(const char* file, uint32_t line, const char* fmt, va_list args1) {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    char time_buf[100];
    size_t rc = strftime(time_buf, sizeof time_buf, "%D %T", gmtime(&ts.tv_sec));
    snprintf(time_buf + rc, sizeof time_buf - rc, ".%06ld UTC", ts.tv_nsec / 1000);

    char file_buf[100];
    sprintf(file_buf, "%s:%u", file, line);
 
    // va_list args1;
    // va_start(args1, fmt);
    va_list args2;
    va_copy(args2, args1);
    char buf[1+vsnprintf(nullptr, 0, fmt, args1)];
    // va_end(args1);
    vsnprintf(buf, sizeof buf, fmt, args2);
    va_end(args2);
 
    printf("%s [debug]:: %s: %s\n", time_buf, file_buf, buf);
}

void c_wrapper(const char* file, uint32_t line, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    Logger::log(file, line, fmt, args);
    va_end(args);
}