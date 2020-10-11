#ifndef CLOCK_MENU_H
#define CLOCK_MENU_H

#include "Arduino.h"
#include "Application.h"
#include "../Global.h"
#include "../Menu/BasicMenu.h"

class ClockMenu: public Application
{
  public:
    virtual void OnStart() override;
    virtual void OnExit() override;
    virtual void Update() override;
    virtual void OnKeyDown(BUT key) override;
    virtual void OnKeyUp(BUT key) override;
    virtual void OnKey(BUT key) override;
  private:
    static const int size = 3;
    String data[size] = {"TimeSettings", "StopWatch", "Timer"};
    BasicMenu* basicMenu = new BasicMenu(size, data);
};
#endif

