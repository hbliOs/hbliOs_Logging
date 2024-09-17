#include "Print.h"
#ifndef DPOS_LOGGING_H
#define DPOS_LOGGING_H

#include "Arduino.h"
#include "DPOS_cfg.h"

#define DPOS_LOG_OUTPUT_LEVEL DPOS_LOG_LEVEL_INFO



template<typename T>
void logPrint(const char* tag, T value) {
  Serial.print(tag);
  Serial.print(" : ");
  Serial.println(value);
}

template<typename T, typename V>
void logPrint(const char* tag, T value, V value2) {
  Serial.print(tag);
  Serial.print(" , ");
  Serial.print(value);
  Serial.print(" : ");
  Serial.println(value2);
}



template<typename T>
void LOGE(const char* tag, T value) {
  Serial.print("[ERROR] ");
  logPrint(tag, value);
}

template<typename T, typename V>
void LOGE(const char* tag, T value, V value2) {
  Serial.print("[ERROR] ");
  logPrint(tag, value, value2);
}


template<typename T>
void LOGI(const char* tag, T value) {
  if (DPOS_LOG_OUTPUT_LEVEL >= DPOS_LOG_LEVEL_INFO) {
    Serial.print("[INFO] ");
    logPrint(tag, value);
  }
}

template<typename T, typename V>
void LOGI(const char* tag, T value, V value2) {
  if (DPOS_LOG_OUTPUT_LEVEL >= DPOS_LOG_LEVEL_INFO) {
    Serial.print("[INFO] ");
    logPrint(tag, value, value2);
  }
}


template<typename T>
void LOGV(const char* tag, T value) {
  if (DPOS_LOG_OUTPUT_LEVEL == DPOS_LOG_LEVEL_VERBOSE) {
    Serial.print("[VERBOSE] ");
    logPrint(tag, value);
  }
  // while (!Serial.availableForWrite()) {};
}

template<typename T, typename V>
void LOGV(const char* tag, T value, V value2) {
  if (DPOS_LOG_OUTPUT_LEVEL >= DPOS_LOG_LEVEL_INFO) {
    Serial.print("[VERBOSE] ");
    logPrint(tag, value, value2);
  }
}


template<typename T>
void LOGG(const char* tag, T value) {
  if (DPOS_LOG_OUTPUT_LEVEL == DPOS_LOG_LEVEL_DEBUG) {
    Serial.print("[DEBUG] ");
    logPrint(tag, value);
  }
}

template<typename T, typename V>
void LOGG(const char* tag, T value, V value2) {
  if (DPOS_LOG_OUTPUT_LEVEL >= DPOS_LOG_LEVEL_INFO) {
    Serial.print("[DEBUG] ");
    logPrint(tag, value, value2);
  }
}

#endif