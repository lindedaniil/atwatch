#ifndef SCREEN_SETTING_MENU_H
#define SCREEN_SETTING_MENU_H

#include "../Application.h"
#include "../../Menu/SelectionMenu.h"

class ScreenSettings : public Application
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
  String rotationOptions[2] = {"ON", "OFF"};
  String brightnessOptions[3] = {"MIN", "MID", "MAX"};
  SelectionMenuElement *rotationElement = new SelectionMenuElement("Rotation", 2, rotationOptions);
  SelectionMenuElement *brightnessElement = new SelectionMenuElement("Brightness", 3, brightnessOptions);
  SelectionMenuElement *elements[size] = {rotationElement, brightnessElement};
  SelectionMenu *selectionMenu = new SelectionMenu(size, elements);
};

#endif
