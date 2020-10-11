#ifndef SOUND_SETTING_MENU_H
#define SOUND_SETTING_MENU_H

#include "../Application.h"
#include "../../Builder/MenuBuilder.h"

class SoundSettings: public Application
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
    static const int size = 2;
    String data[size] = {"Enable", "Offset"};
    byte optionsSize[size] = {2, 3};
    String options[5] = {"ON", "OFF",
                         "0", "10", "100"};
    byte pointsOptions[size] = {0 , 1};
    MenuBuilder menuBuilder;
};

#endif
