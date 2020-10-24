#include "App/SettingMenu.h"
#include "Global.h"

void SettingMenu::OnStart()
{
  display.clearDisplay();
  basicMenu->Draw();
  display.display();
}
void SettingMenu::OnExit() {}
void SettingMenu::Update() {}
void SettingMenu::OnKeyDown(BUT key)
{
  switch (key)
  {
  case UP:
    menu = Apps::MainMenu;
    break;
  case MIDLE:
    display.clearDisplay();
    basicMenu->Next();
    basicMenu->Draw();
    display.display();
    break;
  case DOWN:
    switch (basicMenu->GetPoint())
    {
    case 0:
      menu = Apps::SoundSettings;
      break;
    case 1:
      menu = Apps::ScreenSettings;
      break;
    }
    break;
  }
}
void SettingMenu::OnKeyUp(BUT key) {}
void SettingMenu::OnKey(BUT key) {}