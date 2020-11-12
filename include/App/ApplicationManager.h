#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
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

class ApplicationManager
{
public:
  ApplicationManager();
  Application *GetCurApp();
  void SetMenu(byte newMenu);
  bool IsActive();
  void UpdateTime();
  void UpdateTime(unsigned long time);
  Application** GetAllApps();
  Application* GetApp(byte menu);
  byte GetCurAppID();
private:
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
  byte menu;
  unsigned long curTime;
};

extern ApplicationManager applicationManager;
#endif
