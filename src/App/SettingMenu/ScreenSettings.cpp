#include "App/SettingMenu/ScreenSettings.h"
#include "Global.h"

void ScreenSettings::OnStart()
{
  display.clearDisplay();
  selectionMenu->Draw();
  display.display();
}
void ScreenSettings::OnExit() {}
void ScreenSettings::Update() {}
void ScreenSettings::OnKeyDown(BUT key)
{
  display.clearDisplay();
  switch (key)
  {
  case UP:
    menu = Apps::MainMenu;
    break;
  case MIDLE:
    selectionMenu->Next();
    selectionMenu->Draw();
    break;
  case DOWN:
    selectionMenu->ElementNext();
    selectionMenu->Draw();
    break;
  }
  display.display();
}
void ScreenSettings::OnKeyUp(BUT key) {}
void ScreenSettings::OnKey(BUT key) {}