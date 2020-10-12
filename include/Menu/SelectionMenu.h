#ifndef SELECTION_MENU_H
#define SELECTION_MENU_H

#include "Arduino.h"
#include "Global.h"
#include "Element/SelectionMenuElement.h"

class SelectionMenu
{
public:
  SelectionMenu(byte size, SelectionMenuElement **menuElemets, byte defaultPointValue = 0);
  void Draw();
  void Next();
  void ElementNext();
  byte GetSize();
  SelectionMenuElement **GetMenuElements();
  byte GetPoint();

private:
  byte size;
  SelectionMenuElement **menuElemets;
  byte point;
};
#endif
