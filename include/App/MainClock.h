#ifndef MainClock_H
#define MainClock_H

#include "Arduino.h"
#include "Application.h"
#include "Global.h"

class MainClock: public Application
{
  public:
    virtual void OnStart() override;
    virtual void OnExit() override;
    virtual void Update() override;
    virtual void OnKeyDown(BUT keyNum) override;
    virtual void OnKeyUp(BUT keyNum) override;
    virtual void OnKey(BUT keyNum) override;
  private:
    void panel();
    const String months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    byte h = 0;
    byte m = 0;
    byte s = 0;
    byte d = 0;
    byte mo = 0;
    int y = 0;
    float vbat = 0;
    float stateOfCharge = 0;
    bool lastUSBState = false;
};
#endif

