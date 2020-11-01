#include "App/TimeSetting.h"
#include "Arduino.h"
#include "App/ApplicationManager.h"

void TimeSetting::OnStart() 
{
  count = 0; 
}
void TimeSetting::OnExit() {}
void TimeSetting::OnKeyUp(BUT key) {}

void TimeSetting::Update()
{
  display.clearDisplay();
  applicationManager.UpdateTime();
  display.setTextSize(3);
  display.setCursor(0, 0);
  display.setFont();

  switch (count)
  {
  case 0: //set houe
    display.println F("Hour:");
    display.setTextSize(5);
    display.println(hour);
    break;
  case 1: //set minute
    display.println F("Minute:");
    display.setTextSize(5);
    display.println(minute);
    break;
  case 2: //set second
    display.println F("Second:");
    display.setTextSize(5);
    display.println(second);
    break;
  case 3: //set day
    display.println F("Day:");
    display.setTextSize(5);
    display.println(day);
    break;
  case 4: //set month
    display.println F("Month:");
    display.setTextSize(5);
    display.println(month);
    break;
  case 5: //set year
    display.println F("Year:");
    display.setTextSize(5);
    display.println(year + 2000);
    break;
  case 6: //save data
    RTC.setSeconds(second);
    RTC.setMinutes(minute);
    RTC.setHours(hour);
    RTC.setDays(day);
    RTC.setMonths(month);
    RTC.setYears(year);
    RTC.writeTime();
    delay(1);
    count = 0;
    applicationManager.SetMenu(Apps::MainClock);
    break;
  }
  display.display();
}
void TimeSetting::OnKeyDown(BUT key)
{
  switch (key)
  {
  case MIDLE:
    count++;
    break;
  case UP:
  case DOWN:
    OnKey(key);
    break;
  }
}
void TimeSetting::OnKey(BUT key)
{
  switch (key)
  {
  case UP:
    switch (count)
    {
    case 0: //set houe
      if (hour != 23)
      {
        hour++;
      }
      break;
    case 1: //set minute
      if (minute != 59)
      {
        minute++;
      }
      break;
    case 2: //set second
      if (second != 59)
      {
        second++;
      }
      break;
    case 3: //set day
      if (day != 31)
      {
        day++;
      }
      break;
    case 4: //set mounth
      if (month != 12)
      {
        month++;
      }
      break;
    case 5: //set year
      if (year != 100)
      {
        year++;
      }
      break;
    }
    break;
  case DOWN:
    switch (count)
    {
    case 0: //set houe
      if (hour != 0)
      {
        hour--;
      }
      break;
    case 1: //set minute
      if (minute != 0)
      {
        minute--;
      }
      break;
    case 2: //set second
      if (second != 0)
      {
        second--;
      }
      break;
    case 3: //set day
      if (day != 1)
      {
        day--;
      }
      break;
    case 4: //set month
      if (month != 1)
      {
        month--;
      }
      break;
    case 5: //set year
      if (year != 0)
      {
        year--;
      }
      break;
    }
    break;
  default:
    break;
  }
}
