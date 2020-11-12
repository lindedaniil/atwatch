#include "App/ApplicationManager.h"
#include "Config.h"

ApplicationManager::ApplicationManager()
{
  allApp[Apps::MainClock] = &mainClock;
  allApp[Apps::MainMenu] = &mainMenu;
  allApp[Apps::TimeSetting] = &timeSetting;
  allApp[Apps::ClockMenu] = &clockMenu;
  allApp[Apps::StopWatch] = &stopWatch;
  allApp[Apps::SettingMenu] = &settingMenu;
  allApp[Apps::SoundSettings] = &soundSettings;
  allApp[Apps::ScreenSettings] = &screenSettings;

  curApp = allApp[Apps::MainClock];
}

Application *ApplicationManager::GetCurApp()
{
  return curApp;
}

void ApplicationManager::SetMenu(byte newMenu)
{
  allApp[menu]->OnExit();
  menu = newMenu;
  curApp = allApp[menu];
  curApp->OnStart();
}

bool ApplicationManager::IsActive()
{
  return millis() < curTime;
}

void ApplicationManager::UpdateTime()
{
  curTime = millis() + TimeUp;
}

void ApplicationManager::UpdateTime(unsigned long time)
{
  curTime = millis() + time;
}

Application** ApplicationManager::GetAllApps()
{
  return allApp;
}
Application* ApplicationManager::GetApp(byte menu)
{
  return allApp[menu];
}

byte ApplicationManager::GetCurAppID()
{
  return menu;
}
