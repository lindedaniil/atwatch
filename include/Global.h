#ifndef GLOBAL_H
#define GLOBAL_H

#include "Config.h"
#ifdef SH1106
extern Adafruit_SH1106 display;
#else
extern Adafruit_SSD1306 display;
#endif
extern DS1337 RTC;
extern MAX17043 batteryMonitor;
extern MAX30105 particleSensor;
extern byte menu;
extern unsigned long CurTime;
extern Adafruit_LIS3DH lis;
extern Adafruit_BMP280 bmp;
extern RF24 radio;

#endif
