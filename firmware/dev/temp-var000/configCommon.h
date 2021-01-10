#ifndef CONFIGCOMMON
#define CONFIGCOMMON

#define ARDUINOJSON_USE_LONG_LONG 1

#define LARGE_JSON_BUFFERS 1

#include <Arduino.h>
#include <Thing.h>
#include <WebThingAdapter.h>

#ifdef ESP32
#include <analogWrite.h>
#endif


WebThingAdapter *adapter;


#endif
