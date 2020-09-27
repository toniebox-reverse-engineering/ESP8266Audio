
#include <Arduino.h>

#ifndef _AUDIOLOGGER_H
#define _AUDIOLOGGER_H

class DevNullOut: public Print
{
public:
    virtual size_t write(uint8_t) { return 1; }
    virtual int printf_P(const char *fmt, ...) { Serial.print(fmt);return 0; };
};

extern DevNullOut silencedLogger;

// Global `audioLogger` is initialized to &silencedLogger
// It can be initialized anytime to &Serial or any other Print:: derivative instance.
extern DevNullOut* audioLogger;

#endif
