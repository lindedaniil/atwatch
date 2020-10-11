#ifndef STOP_WATCH_H
#define STOP_WATCH_H

#include "Application.h"

class StopWatch: public Application
{
  public:
    virtual void OnStart() override;
    virtual void OnExit() override;
    virtual void Update() override;
    virtual void OnKeyDown(BUT key) override;
    virtual void OnKeyUp(BUT key) override;
    virtual void OnKey(BUT key) override;
  private:
    unsigned long timer = 0;
    unsigned long deltaTime = 0;
    bool pause = false;
};

#endif
