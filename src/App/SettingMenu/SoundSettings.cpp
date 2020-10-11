#include "App/SettingMenu/SoundSettings.h"
#include "Global.h"

void SoundSettings::OnStart() 
{
  display.clearDisplay();
  menuBuilder.DrawSelection(size, data, optionsSize, options, point, pointsOptions);
  display.display();
}
void SoundSettings::OnExit() {}
void SoundSettings::Update() {}
void SoundSettings::OnKeyDown(BUT key) 
{
  display.clearDisplay();
  switch (key)
  {
  case UP:
    menu = Apps::MainMenu;
    break;
  case MIDLE:
    menuBuilder.IncPoint(size, point);
    menuBuilder.DrawSelection(size, data, optionsSize, options, point, pointsOptions);
  //  menuBuilder.IncAndDrawBasic(size, data, point);
    break;
  case DOWN:
    menuBuilder.IncPoint(optionsSize[point], pointsOptions[point]);
    menuBuilder.DrawSelection(size, data, optionsSize, options, point, pointsOptions);
    break;
  }
  display.display();
}
void SoundSettings::OnKeyUp(BUT key) {}
void SoundSettings::OnKey(BUT key) {}