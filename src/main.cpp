#include <Wire.h>
#include "PinsConfig.h"
#include <Adafruit_LIS3DH.h>
//#include "config.h"
#include "Images.h"
#include "Global.h"
#include "PAdafruitDisplay.h"
#include <DS1337.h>
#include "MAX17043.h"
#include "LowPower.h"
#include "GyverButton.h"
#include "RF24.h"
/*Apps*/
#include "App/Application.h"
#include "App/MainClock.h"
#include "App/MainMenu.h"
#include "App/TimeSetting.h"
#include "App/ClockMenu.h"
#include "App/StopWatch.h"
#include "App/SettingMenu.h"
/*Apps/SettinMenu*/
#include "App/SettingMenu/SoundSettings.h"
#include "App/SettingMenu/ScreenSettings.h"
/*Test*/
#include "Tests/tests.h"

/*Create Objects*/
#ifdef I2CVer
#ifdef SH1106
Adafruit_SH1106 display(OLED_RESET);
#else
Adafruit_SSD1306 display(OLED_RESET);
#endif
#else
#ifdef SH1106
Adafruit_SH1106 display(OLED_DC, OLED_RESET, OLED_CS);
#else
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);
#endif
#endif

DS1337 RTC;
MAX17043 batteryMonitor;
MAX30105 particleSensor;
Adafruit_LIS3DH lis;
Adafruit_BMP280 bmp;
RF24 radio(3, 4);

/*Buttons*/
GButton butt1(b1, LOW_PULL, NORM_OPEN);
GButton butt2(b2, LOW_PULL, NORM_OPEN);
GButton butt3(b3, LOW_PULL, NORM_OPEN);

/*Apps*/
MainClock mainClock;
MainMenu mainMenu;
TimeSetting timeSetting;
ClockMenu clockMenu;
StopWatch stopWatch;
SettingMenu settingMenu;
SoundSettings soundSettings;
ScreenSettings screenSettings;

Application **allApp = new Application *[ApplicationBufferSize];
Application *curApp;

/*Variables*/
byte menu;
unsigned long CurTime;
byte lastMenuState;

void AppManager();
void Buttons();
void DisableModules();
void EnableModules();
void SleepAnimation();
void wakeUp();

void setup()
{
  Serial.begin(9600);
  /*add Apps*/
  allApp[Apps::MainClock] = &mainClock;
  allApp[Apps::MainMenu] = &mainMenu;
  allApp[Apps::TimeSetting] = &timeSetting;
  allApp[Apps::ClockMenu] = &clockMenu;
  allApp[Apps::StopWatch] = &stopWatch;
  allApp[Apps::SettingMenu] = &settingMenu;
  allApp[Apps::SoundSettings] = &soundSettings;
  allApp[Apps::ScreenSettings] = &screenSettings;

  RTC.start();
  lis.begin(0x19);
  radio.begin();

#ifdef SH1106
  display.begin(SH1106_SWITCHCAPVCC);
#else
  display.begin(SSD1306_SWITCHCAPVCC);
#endif

  batteryMonitor.reset();
  batteryMonitor.quickStart();
  particleSensor.begin(Wire, I2C_SPEED_FAST);
  particleSensor.setup(0x1F, 1, 2, 3200, 411, 16384);

  display.setTextColor(WHITE);
  display.setTextSize(1);

  /*Pins*/
  pinMode(v18, OUTPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(USBPin, INPUT);
  pinMode(ChardgePin, INPUT);
  pinMode(Motor, OUTPUT);
  digitalWrite(Motor, LOW);
  digitalWrite(v18, LOW);

  run_tests();

  DisableModules();
}

void loop()
{
  display.clearDisplay();
  display.display();
  DisableModules();
  lastMenuState = menu = Apps::MainClock;
  attachInterrupt(2, wakeUp, HIGH); //2
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  detachInterrupt(2); //2
  EnableModules();

  CurTime = millis() + TimeUp;

  while (millis() < CurTime)
  {
    AppManager();
    Buttons();
    curApp->Update();
  }
  SleepAnimation();
}
void AppManager()
{
  if (lastMenuState != menu)
  {
    allApp[lastMenuState]->OnExit();
    allApp[menu]->OnStart();
  }
  curApp = allApp[menu];
  lastMenuState = menu;
}

void Buttons()
{
  butt1.tick();
  butt2.tick();
  butt3.tick();
  bool resetTimer = false;
  if (butt1.isClick())
  {
    digitalWrite(Motor, HIGH);
    delay(100);
    digitalWrite(Motor, LOW);
    tone(BuzzerPin, 2000, 200);
    curApp->OnKeyDown(BUT::DOWN);
    resetTimer = true;
  }
  if (butt2.isClick())
  {
    tone(BuzzerPin, 4000, 200);
    curApp->OnKeyDown(BUT::MIDLE);
    resetTimer = true;
  }
  if (butt3.isClick())
  {
    tone(BuzzerPin, 1000, 200);
    curApp->OnKeyDown(BUT::UP);
    resetTimer = true;
  }

  if (butt1.isStep())
  {
    tone(BuzzerPin, 2000, 200);
    curApp->OnKey(BUT::DOWN);
    resetTimer = true;
  }
  if (butt2.isStep())
  {
    tone(BuzzerPin, 4000, 200);
    curApp->OnKey(BUT::MIDLE);
    resetTimer = true;
  }
  if (butt3.isStep())
  {
    tone(BuzzerPin, 1000, 200);
    curApp->OnKey(BUT::UP);
    resetTimer = true;
  }

  if (resetTimer)
  {
    CurTime = millis() + TimeUp;
  }
}

void DisableModules()
{
  lis.setDataRate(LIS3DH_DATARATE_POWERDOWN);
  particleSensor.shutDown();
  bmp.sleep();
  radio.powerDown();
  ADCSRA = 0;
#ifdef SH1106
  display.SH1106_command(SH1106_DISPLAYOFF);
#else
  display.ssd1306_command(SSD1306_DISPLAYOFF);
#endif
  //Serial.end();
  noTone(BuzzerPin);
  pinMode(ChardgePin, INPUT);
  disablePower(POWER_ALL);
}
void EnableModules()
{
  enablePower(POWER_ALL);
  batteryMonitor.reset();
  batteryMonitor.quickStart();
  particleSensor.wakeUp();
#ifdef SH1106
  display.SH1106_command(SH1106_DISPLAYON);
#else
  display.ssd1306_command(SSD1306_DISPLAYON);
#endif
  // Serial.begin(115200);
  pinMode(ChardgePin, INPUT_PULLUP);
}

void SleepAnimation()
{
  for (byte i = 0; i <= 32; i++)
  {
    tone(BuzzerPin, 1500 + i * 100);
    display.drawLine(0, i, 128, i, 1);
    display.drawLine(0, 64 - i, 128, 64 - i, 1);

    display.display();
    display.drawLine(0, i, 128, i, 0);
    display.drawLine(0, 64 - i, 128, 64 - i, 0);
#ifndef I2CVer
    delay(15);
#endif
  }
  display.display();
  display.clearDisplay();
}

void wakeUp() {}
