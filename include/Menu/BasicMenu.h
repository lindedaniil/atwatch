#ifndef BASIC_MENU_H
#define BASIC_MENU_H

#include "Arduino.h"
#include "Global.h"

class BasicMenu
{
public:
  BasicMenu(byte size, String *data);
  void Draw();
  void Next();
  byte GetSize();
  String *GetData();
  byte GetPoint();
private:
  byte size;
  String *data;
  byte point;
};
#endif
