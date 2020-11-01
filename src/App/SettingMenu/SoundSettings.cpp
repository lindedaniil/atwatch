#include "App/SettingMenu/SoundSettings.h"
#include "Global.h"
#include "App/ApplicationManager.h"

void SoundSettings::OnStart()
{
  display.clearDisplay();
  selectionMenu->Draw();
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
    applicationManager.SetMenu(Apps::MainMenu);
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
void SoundSettings::OnKeyUp(BUT key) {}
void SoundSettings::OnKey(BUT key) {}