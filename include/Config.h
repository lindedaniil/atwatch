#ifndef CONFIG_H
#define CONFIG_H

/*HARDWARE*/
//#define SH1106
//#define I2CVer

#include "PAdafruitDisplay.h"
#include "DS1337.h"
#include "MAX17043.h"
#include "MAX30105.h"
#include "RF24.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_BMP280.h>

#define ApplicationBufferSize 20

#ifdef I2CVer
#define OLED_RESET 4
#else
#define OLED_RESET 24
#endif
/*TIMERS*/
#define TimeUp 6000
#define TimeUpInApps 20000
#define TimeMotorButtons 150

namespace Apps
{
	enum App
	{
		MainClock,
		MainMenu,
		TimeSetting,
		ClockMenu,
		StopWatch,
		SettingMenu,
		SoundSettings
	};
}
enum BUT
{
	UP,
	MIDLE,
	DOWN
};

//0 часы
//1 меню
//2 настройка времени
//3 Clock
//4 Настройки
//5 Приложения
//6 Fitness
//7 тест сенсоров
//8 настройки дисплея
//9 Погодная станция
//10 0 gravity detector
//11 cards
//12 Heartbeat
//13 app5
//14 app6
//15 Секундомер
//16 Таймер
//17 Календарь
//18 Будильник

#endif
