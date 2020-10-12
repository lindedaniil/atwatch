#ifndef SELECTION_MENU_ELEMENT_H
#define SELECTION_MENU_ELEMENT_H

#include "Arduino.h"
#include "Global.h"

class SelectionMenuElement
{
public:
  SelectionMenuElement(String name, byte size, String *data, byte defaultPointValue = 0);
  void Next();
  String GetCurOptionName();
  byte GetPoint();
  byte GetSize();
  String* GetData();
  String GetName();
private:
  String name;
  byte size;
  String *data;
  byte point;
};
#endif
