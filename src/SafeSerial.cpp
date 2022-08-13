#include "SafeSerial.h"
#include <SerialUSB.h>

SafeSerialClass::SafeSerialClass() {
  _SafeSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
  if ( ( _SafeSerialSemaphore ) != NULL )
    xSemaphoreGive( ( _SafeSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
}

SafeSerialClass::~SafeSerialClass()
{
  if (_SafeSerialSemaphore != nullptr)
    vSemaphoreDelete(_SafeSerialSemaphore);
}

size_t SafeSerialClass::printf(const char *fmt, ...) {
  char buf[256];
  va_list args;
  va_start(args, fmt);
  int rc = vsnprintf(buf, sizeof(buf), fmt, args);
  va_end(args);

  if ( xSemaphoreTake( _SafeSerialSemaphore, portMAX_DELAY ) == pdTRUE ) {
    Serial.print(buf);
    xSemaphoreGive( _SafeSerialSemaphore );
  }
  return (size_t)rc;
}

size_t SafeSerialClass::print(const char *str)
{
  size_t rc;
  if ( xSemaphoreTake( _SafeSerialSemaphore, portMAX_DELAY ) == pdTRUE ) {
    rc = Serial.print(str);
    xSemaphoreGive( _SafeSerialSemaphore );
  }
  return rc;
}

size_t SafeSerialClass::print(String str)
{
  size_t rc;
  if ( xSemaphoreTake( _SafeSerialSemaphore, portMAX_DELAY ) == pdTRUE ) {
    Serial.print(str);
    xSemaphoreGive( _SafeSerialSemaphore );
  }
  return rc;
}

size_t SafeSerialClass::print(int var)
{
  size_t rc;
  if ( xSemaphoreTake( _SafeSerialSemaphore, portMAX_DELAY ) == pdTRUE ) {
    rc = Serial.print(var);
    xSemaphoreGive( _SafeSerialSemaphore );
  }
  return rc;
}

size_t SafeSerialClass::println(const char *str)
{
  size_t rc;
  if ( xSemaphoreTake( _SafeSerialSemaphore, portMAX_DELAY ) == pdTRUE ) {
    rc = Serial.println(str);
    xSemaphoreGive( _SafeSerialSemaphore );
  }
  return rc;
}

size_t SafeSerialClass::println(String str)
{
  size_t rc;
  if ( xSemaphoreTake( _SafeSerialSemaphore, portMAX_DELAY ) == pdTRUE ) {
    rc = Serial.println(str);
    xSemaphoreGive( _SafeSerialSemaphore );
  }
  return rc;
}

size_t SafeSerialClass::println(int var)
{
  size_t rc;
  if ( xSemaphoreTake( _SafeSerialSemaphore, portMAX_DELAY ) == pdTRUE ) {
    rc = Serial.println(var);
    xSemaphoreGive( _SafeSerialSemaphore );
  }
  return rc;
}

SafeSerialClass SafeSerial;