#ifndef TIME_SETTING_H
#define TIME_SETTING_H

#include "Arduino.h"
#include "Application.h"
#include "Global.h"

class TimeSetting: public Application
{
  public:
    virtual void OnStart() override;
    virtual void OnExit() override;
    virtual void Update() override;
    virtual void OnKeyDown(BUT key) override;
    virtual void OnKeyUp(BUT key) override;
    virtual void OnKey(BUT key) override;
  private:
    byte count = 0;
    byte hour = 0;
    byte minute = 0;
    byte second = 0;
    byte day = 1;
    byte month = 1;
    byte year = 0;
};
#endif

