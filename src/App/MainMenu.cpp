#include "App/MainMenu.h"
#include "Arduino.h"
#include "Images.h"

void MainMenu::OnStart() {}
void MainMenu::OnExit() {}
void MainMenu::Update()
{
  display.clearDisplay();
  display.drawBitmap(2, 25, MenuText, 21, 21, 1);
  display.drawBitmap(35, 25, MenuSettings, 21, 21, 1);
  display.drawBitmap(68, 25, MenuTime, 21, 21, 1);
  display.drawBitmap(101, 25, MenuAlarm, 21, 21, 1);
  display.setTextSize(2);
  display.setCursor(0, 0);
  if (point == 0)
    display.print(F("Clock"));
  if (point == 1)
    display.print(F("Settings"));
  if (point == 2)
    display.print(F("Apps"));
  if (point == 3)
    display.print(F("Trainer"));
  display.drawBitmap(2 + (33 * point), 50, MenuCur, 21, 2, 1);
  display.display();
}
void MainMenu::OnKeyDown(BUT keyNum)
{
  switch (keyNum)
  {
    case DOWN:
      if (point == 0)     menu = Apps::ClockMenu;
      else if(point == 1) menu = Apps::SettingMenu;
      break;
    case MIDLE:
      if (point != 3)
      {
        point++;
      }
      else
      {
        point = 0;
      }
      break;
    case UP:
      menu = Apps::MainClock;
      break;
  }
}
void MainMenu::OnKeyUp(BUT keyNum) {}
void MainMenu::OnKey(BUT keyNum) {}



