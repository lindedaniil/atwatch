#ifndef Application_H
#define Application_H

#include "Arduino.h"
#include "PAdafruitDisplay.h"
#include "DS1337.h"
#include "config.h"

class Application
{
  public:
    virtual void OnStart() {}
    virtual void OnExit() {}
    virtual void Update() {}
    virtual void OnKeyDown(BUT key) {}
    virtual void OnKeyUp(BUT key) {}
    virtual void OnKey(BUT key) {}
};

#endif
