#include "Menu/Element/SelectionMenuElement.h"

SelectionMenuElement::SelectionMenuElement(String name, byte size, String *data, byte defaultPointValue)
{
  this->name = name;
  this->size = size;
  this->data = data;
  point = defaultPointValue;
}

void SelectionMenuElement::Next()
{
  if (point != size - 1)
    point++;
  else
    point = 0;
}
String SelectionMenuElement::GetCurOptionName()
{
  return data[point];
}
byte SelectionMenuElement::GetPoint()
{
  return point;
}
byte SelectionMenuElement::GetSize()
{
  return size;
}
String *SelectionMenuElement::GetData()
{
  return data;
}
String SelectionMenuElement::GetName()
{
  return name;
}
