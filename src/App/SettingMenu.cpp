#include "App/SettingMenu.h"
#include "Global.h"
#include "App/ApplicationManager.h"

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
    applicationManager.SetMenu(Apps::MainMenu);
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
      applicationManager.SetMenu(Apps::SoundSettings);
      break;
    case 1:
      applicationManager.SetMenu(Apps::ScreenSettings);
      break;
    }
    break;
  }
}
void SettingMenu::OnKeyUp(BUT key) {}
void SettingMenu::OnKey(BUT key) {}