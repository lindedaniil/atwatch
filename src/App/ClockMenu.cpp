#include "App/ClockMenu.h"
#include "Arduino.h"
#include "App/ApplicationManager.h"

void ClockMenu::OnStart()
{
  display.clearDisplay();
  basicMenu->Draw();
  display.display();
}
void ClockMenu::OnExit() {}
void ClockMenu::OnKeyUp(BUT key) {}
void ClockMenu::Update() {}
void ClockMenu::OnKeyDown(BUT key)
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
    if (basicMenu->GetPoint() == 0)
      applicationManager.SetMenu(Apps::TimeSetting);
    else if (basicMenu->GetPoint() == 1)
      applicationManager.SetMenu(Apps::StopWatch);
    break;
  }
}
void ClockMenu::OnKey(BUT key) {}
