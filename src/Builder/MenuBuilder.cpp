#include "Builder/MenuBuilder.h"
#include "config.h"


void MenuBuilder::DrawSelection(byte size, String data[], byte optionsSize[], String options[], byte& point, byte pointsOptions[])
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
    byte optionsPoint = 0;
    for(byte j = offset; j < i; j++)//+1
    {
      optionsPoint += optionsSize[j];
    }
    optionsPoint+=pointsOptions[i];

    display.setCursor(10, 10 * (i - offset));
    display.print(data[i]);
    display.print(F(">"));
    display.print(options[optionsPoint]);
    display.println(F("<"));
  }
  display.setCursor(0, 10 * (point - offset));
  display.write(16);
}

void MenuBuilder::DrawBasic(byte size, String data[], byte &point)
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
void MenuBuilder::IncPoint(byte size, byte& point)
{
  if (point != size - 1)
    point++;
  else
    point = 0;
}
