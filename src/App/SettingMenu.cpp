#include "App/SettingMenu.h"
#include "Global.h"

void SettingMenu::OnStart() 
{
  display.clearDisplay();
  menuBuilder.DrawBasic(size, data, point);
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
    menuBuilder.IncPoint(size, point);
    menuBuilder.DrawBasic(size, data, point);
    display.display();
    break;
  case DOWN:
    if(point == 0) menu = Apps::SoundSettings;
    break;
  }
}
void SettingMenu::OnKeyUp(BUT key) {}
void SettingMenu::OnKey(BUT key) {}