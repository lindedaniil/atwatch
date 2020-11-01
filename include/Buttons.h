#ifndef BUTTONS_H
#define BUTTONS_H
#include "GyverButton.h"
#include "PinsConfig.h"
class Buttons
{
  public:
  GButton* GetB1();
  GButton* GetB2();
  GButton* GetB3();
  void tick();
  private:
  GButton* button1 = new GButton(b1, LOW_PULL, NORM_OPEN);
  GButton* button2 = new GButton(b2, LOW_PULL, NORM_OPEN);
  GButton* button3 = new GButton(b3, LOW_PULL, NORM_OPEN);
};

#endif