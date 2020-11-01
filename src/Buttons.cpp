#include "Buttons.h"
#include "Config.h"
#include "Global.h"
#include "App/ApplicationManager.h"

void Buttons::tick()
{
  button1->tick();
  button2->tick();
  button3->tick();

  bool resetTimer = false;
  if (button1->isClick())
  {
    tone(BuzzerPin, 2000, 200);
    applicationManager.GetCurApp()->OnKeyDown(BUT::DOWN);
    resetTimer = true;
  }
  if (button2->isClick())
  {
    tone(BuzzerPin, 4000, 200);
    applicationManager.GetCurApp()->OnKeyDown(BUT::MIDLE);
    resetTimer = true;
  }
  if (button3->isClick())
  {
    tone(BuzzerPin, 1000, 200);
    applicationManager.GetCurApp()->OnKeyDown(BUT::UP);
    resetTimer = true;
  }

  if (button1->isStep())
  {
    tone(BuzzerPin, 2000, 200);
    applicationManager.GetCurApp()->OnKey(BUT::DOWN);
    resetTimer = true;
  }
  if (button2->isStep())
  {
    tone(BuzzerPin, 4000, 200);
    applicationManager.GetCurApp()->OnKey(BUT::MIDLE);
    resetTimer = true;
  }
  if (button3->isStep())
  {
    tone(BuzzerPin, 1000, 200);
    applicationManager.GetCurApp()->OnKey(BUT::UP);
    resetTimer = true;
  }

  if (resetTimer)
  {
    applicationManager.UpdateTime();
  }
}

GButton* Buttons::GetB1()
{
  return button1;
}
GButton* Buttons::GetB2()
{
  return button2;
}
GButton* Buttons::GetB3()
{
  return button3;
}