#include "Menu/BasicMenu.h"
#include "config.h"

BasicMenu::BasicMenu(byte size, String *data)
{
  this->size = size;
  this->data = data;
  point = 0;
}

void BasicMenu::Draw()
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
    display.println(data[i]);
  }
  display.setCursor(0, 10 * (point - offset));
  display.write(16);
}

void BasicMenu::Next()
{
  if (point != size - 1)
    point++;
  else
    point = 0;
}

String *BasicMenu::GetData()
{
  return data;
}

byte BasicMenu::GetSize()
{
  return size;
}

byte BasicMenu::GetPoint()
{
  return point;
}
