#ifndef _SafeSerial_H
#define _SafeSerial_H
#include <Arduino.h>
#include <FreeRTOS.h>
#include <semphr.h>

class SafeSerial
  {
    public:
      SafeSerial();
      virtual ~SafeSerial();
      size_t printf(const char *fmt, ...);
      size_t print(const char *str);
      size_t print(String str);
      size_t println(const char *str);
      size_t println(String str);
    private:
        volatile SemaphoreHandle_t _SafeSerialSemaphore = nullptr;
  };
#endif // SafeSerial_H