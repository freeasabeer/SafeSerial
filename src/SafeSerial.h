#pragma once

#include <Arduino.h>
#include <FreeRTOS.h>
#include <semphr.h>

class SafeSerialClass
  {
    public:
      SafeSerialClass();
      virtual ~SafeSerialClass();
      size_t printf(const char *fmt, ...);
      size_t print(const char *str);
      size_t print(int var);
      size_t print(String str);
      size_t println(const char *str);
      size_t println(String str);
      size_t println(int var);
    private:
        volatile SemaphoreHandle_t _SafeSerialSemaphore = nullptr;
  };

extern WiFiClass WiFi;