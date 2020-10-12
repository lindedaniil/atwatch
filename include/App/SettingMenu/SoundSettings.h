#ifndef SOUND_SETTING_MENU_H
#define SOUND_SETTING_MENU_H

#include "../Application.h"
#include "../../Menu/SelectionMenu.h"

class SoundSettings : public Application
{
public:
  virtual void OnStart() override;
  virtual void OnExit() override;
  virtual void Update() override;
  virtual void OnKeyDown(BUT keyNum) override;
  virtual void OnKeyUp(BUT keyNum) override;
  virtual void OnKey(BUT keyNum) override;

private:
  static const int size = 2;
  String enableOptions[2] = {"ON", "OFF"};
  String offsetOptions[3] = {"0", "10", "100"};
  SelectionMenuElement *enableElement = new SelectionMenuElement("Enable", 2, enableOptions);
  SelectionMenuElement *offsetElement = new SelectionMenuElement("Offset", 3, offsetOptions);
  SelectionMenuElement *elements[size] = {enableElement, offsetElement};
  SelectionMenu *selectionMenu = new SelectionMenu(size, elements);
};

#endif
