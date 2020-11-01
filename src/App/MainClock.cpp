#include "PinsConfig.h"
#include "App/MainClock.h"
#include "Arduino.h"
#include "Images.h"
#include "App/ApplicationManager.h"

void MainClock::OnStart() {}
void MainClock::OnExit() {}
void MainClock::Update()
{
  display.clearDisplay();
  RTC.readTime();
  h = RTC.getHours();
  m = RTC.getMinutes();
  s = RTC.getSeconds();
  d = RTC.getDays();
  mo = RTC.getMonths();
  y = RTC.getYears();
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.setFont(&FreeSans18pt7b);
  if (h <= 9)  display.print F("0");
  display.print (h);
  display.print F(":");
  if (m <= 9)  display.print F("0");
  display.print (m);
  display.print F(":");
  display.setFont(&FreeSans12pt7b);
  if (s <= 9)  display.print F("0");
  display.print (s);

  display.setFont();
  display.setCursor(40, 50);
  display.print (d);
  display.print F("-");
  display.print (months[mo - 1]);
  display.print F("-");
  display.print(y);
  panel();
  display.display();
}
void MainClock::OnKeyDown(BUT keyNum)
{
  switch (keyNum)
  {
    case UP:
    applicationManager.SetMenu(Apps::MainMenu);
     // menu = Apps::MainMenu;
      break;
  }
}
void MainClock::OnKeyUp(BUT keyNum) {}
void MainClock::OnKey(BUT keyNum) {}

void MainClock::panel()
{
  if (batteryMonitor.getVCell() > 1) {
    vbat = batteryMonitor.getVCell();
    stateOfCharge = batteryMonitor.getSoC();
  }
  if (lastUSBState != digitalRead(USBPin)) {
    tone(BuzzerPin, 4000, 500);
    tone(BuzzerPin, 3500, 300);
    lastUSBState = digitalRead(USBPin);
  }
  if (lastUSBState == HIGH) {
    display.drawBitmap(112, 56, USBCable, 16, 8, 1);
  }
  if (digitalRead(ChardgePin) == LOW) {
    display.drawBitmap(18, 56, USBCharge, 8, 8, 1);
  }
  if (6.6 > stateOfCharge) {
    display.drawBitmap(0, 56, bat_bmp0, 16, 7, 1);
  }
  else if (13.3 < stateOfCharge && stateOfCharge <= 19.9) {
    display.drawBitmap(0, 56, bat_bmp1, 16, 7, 1);
  }
  else if (19.9 < stateOfCharge && stateOfCharge <= 26.5) {
    display.drawBitmap(0, 56, bat_bmp2, 16, 7, 1);
  }
  else if (26.5 < stateOfCharge && stateOfCharge <= 33.1) {
    display.drawBitmap(0, 56, bat_bmp3, 16, 7, 1);
  }
  else if (33.1 < stateOfCharge && stateOfCharge <= 39.7) {
    display.drawBitmap(0, 56, bat_bmp4, 16, 7, 1);
  }
  else if (39.7 < stateOfCharge && stateOfCharge <= 46.3) {
    display.drawBitmap(0, 56, bat_bmp5, 16, 7, 1);
  }
  else if (46.3 < stateOfCharge && stateOfCharge <= 52.9) {
    display.drawBitmap(0, 56, bat_bmp6, 16, 7, 1);
  }
  else if (52.9 < stateOfCharge && stateOfCharge <= 59.5) {
    display.drawBitmap(0, 56, bat_bmp7, 16, 7, 1);
  }
  else if (59.5 < stateOfCharge && stateOfCharge <= 66.1) {
    display.drawBitmap(0, 56, bat_bmp8, 16, 7, 1);
  }
  else if (66.1 < stateOfCharge && stateOfCharge <= 72.7) {
    display.drawBitmap(0, 56, bat_bmp9, 16, 7, 1);
  }
  else if (72.7 < stateOfCharge && stateOfCharge <= 79.3) {
    display.drawBitmap(0, 56, bat_bmp10, 16, 7, 1);
  }
  else if (79.3 > stateOfCharge && stateOfCharge <= 85.9) {
    display.drawBitmap(0, 56, bat_bmp11, 16, 7, 1);
  }
  else if (85.9 > stateOfCharge && stateOfCharge <= 92.5) {
    display.drawBitmap(0, 56, bat_bmp12, 16, 7, 1);
  }
  else {
    display.drawBitmap(0, 56, bat_bmp13, 16, 7, 1);
  }

  display.setTextSize(1);
  display.setCursor(95, 0);
  display.print(vbat);
  display.print F("V");

  display.setCursor(0, 0);
  display.setFont();
  display.print F("ATWatch");
}

