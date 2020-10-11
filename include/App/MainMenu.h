#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "Arduino.h"
#include "Application.h"
#include "../Global.h"

class MainMenu: public Application
{
  public:
    virtual void OnStart() override;
    virtual void OnExit() override;
    virtual void Update() override;
    virtual void OnKeyDown(BUT keyNum) override;
    virtual void OnKeyUp(BUT keyNum) override;
    virtual void OnKey(BUT keyNum) override;
  private:
    byte point = 0;
};
#endif

