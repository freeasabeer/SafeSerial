#pragma once

#include <Arduino.h>
#if defined (ESP32)
  #include <freertos/FreeRTOS.h>
#elif defined (ARDUINO_ARCH_RP2040)
  #include <FreeRTOS.h>
  #include <semphr.h>
#else
#pragma message("Fix me !")
#endif

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
      size_t println();
      size_t write(const uint8_t* buffer, size_t size);
    private:
        volatile SemaphoreHandle_t _SafeSerialSemaphore = nullptr;
  };

extern SafeSerialClass SafeSerial;
