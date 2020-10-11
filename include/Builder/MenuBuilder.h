#ifndef MENU_BUILDER_H
#define MENU_BUILDER_H

#include "Arduino.h"
#include "Global.h"

class MenuBuilder
{
  public:
    static void DrawBasic(byte size, String data[], byte& point);
    static void IncPoint(byte size, byte& point);
    static void DrawSelection(byte size, String data[], byte optionsSize[], String options[], byte& point, byte pointsOptions[]);
};
#endif

