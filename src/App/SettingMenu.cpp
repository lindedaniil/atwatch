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
    if (basicMenu->GetPoint() == 0)
      menu = Apps::SoundSettings;
    break;
  }
}
void SettingMenu::OnKeyUp(BUT key) {}
void SettingMenu::OnKey(BUT key) {}