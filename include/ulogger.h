#ifndef UNSALTED_ULOGGER_H
#define UNSALTED_ULOGGER_H

#include <stdio.h>
#include <stdarg.h>

struct _logger_t {
    FILE* file;
    char* level_prefix[];
};

struct _logger_t logger_t;

void logger_log(logger_t * logger, size_t log_level, char fmt[], ...){
    fputs(logger->level_prefix[log_level]);

    va_list args;
    va_start(args, fmt);
    vfprintf(logger->file, fmt, args);
    va_end(args);
}

#endif //UNSALTED_ULOGGER_H
