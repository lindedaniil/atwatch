#include "Menu/SelectionMenu.h"

SelectionMenu::SelectionMenu(byte size, SelectionMenuElement **menuElemets, byte defaultPointValue)
{
  this->size = size;
  this->menuElemets = menuElemets;
  point = defaultPointValue;
}

void SelectionMenu::Draw()
{
  display.setFont();
  display.setTextSize(1);

  byte offset = 0;
  if (point >= 6)
  {
    offset = point - 5;
  }

  for (byte i = offset; i < size; i++)
  {
    display.setCursor(10, 10 * (i - offset));
    display.print(menuElemets[i]->GetName());
    display.print(F(">"));
    display.print(menuElemets[i]->GetCurOptionName());
    display.println(F("<"));
  }
  display.setCursor(0, 10 * (point - offset));
  display.write(16);
}

void SelectionMenu::ElementNext()
{
  menuElemets[point]->Next();
}

void SelectionMenu::Next()
{
  if (point != size - 1)
    point++;
  else
    point = 0;
}

byte SelectionMenu::GetSize()
{
  return size;
}

byte SelectionMenu::GetPoint()
{
  return point;
}
SelectionMenuElement *SelectionMenu::GetCurElement()
{
  return menuElemets[point];
}
SelectionMenuElement **SelectionMenu::GetMenuElements()
{
  return menuElemets;
}