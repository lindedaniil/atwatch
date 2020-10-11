#include "App/StopWatch.h"
#include "Global.h"

void StopWatch::OnStart() {}
void StopWatch::OnExit() {}
void StopWatch::Update() 
{
  CurTime = millis() + TimeUp;
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println F("Stopwatch");
  if (pause) {
    deltaTime = (millis() - timer) / 1000;
  }

  if (deltaTime / 60 / 60 < 10) {
    display.print F("0");
  }
  display.print (deltaTime / 60 / 60);
  display.print F(":");
  if (deltaTime / 60 % 60 < 10) {
    display.print F("0");
  }
  display.print ((deltaTime / 60) % 60);
  display.print F(":");
  if (deltaTime % 60 < 10) {
    display.print F("0");
  }
  display.println (deltaTime % 60);
  if (!pause) {
    display.println F("Pause");
  }
  display.display();
}
void StopWatch::OnKeyDown(BUT key) 
{
  switch (key)
  {
  case UP:
    pause = false;
    menu = Apps::ClockMenu;
    break;
  case MIDLE:
    pause = !pause;
    if(pause)
      timer += (((millis() - timer) / 1000) - (deltaTime)) * 1000;
    break;
  case DOWN:
    timer = millis();
    pause = true;
    break;
  }
}
void StopWatch::OnKeyUp(BUT key) {}
void StopWatch::OnKey(BUT key) {}