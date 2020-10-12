#ifndef SETTING_MENU_H
#define SETTING_MENU_H

#include "Application.h"
#include "../Menu/BasicMenu.h"

class SettingMenu : public Application
{
public:
  virtual void OnStart() override;
  virtual void OnExit() override;
  virtual void Update() override;
  virtual void OnKeyDown(BUT keyNum) override;
  virtual void OnKeyUp(BUT keyNum) override;
  virtual void OnKey(BUT keyNum) override;

private:
  static const int size = 4;
  String data[size] = {"Sound", "Screen", "Sensors", "Buttons"};
  BasicMenu *basicMenu = new BasicMenu(size, data);
};

#endif
