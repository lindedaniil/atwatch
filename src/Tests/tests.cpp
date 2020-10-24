#include "Tests/tests.h"
#include "PinsConfig.h"
#include "Arduino.h"
#include "Global.h"
#include "sput.h"

void test_buttons_1_press()
{
  butt1.tick();
  digitalWrite(b1, HIGH);
  butt1.tick();
  delay(150);
  butt1.tick();
  sput_fail_unless(butt1.isPress(), "Button 1 click");
}

void test_buttons_2_press()
{
  butt2.tick();
  digitalWrite(b2, HIGH);
  butt2.tick();
  delay(150);
  butt2.tick();
  sput_fail_unless(butt2.isPress(), "Button 2 click");
}
void test_buttons_3_press()
{
  butt3.tick();
  digitalWrite(b3, HIGH);
  butt3.tick();
  delay(150);
  butt3.tick();
  sput_fail_unless(butt3.isPress(), "Button 3 click");
}

int run_tests()
{
  while (!Serial);
  sput_start_testing();

  sput_enter_suite("buttons");
  sput_run_test(test_buttons_1_press);
  sput_run_test(test_buttons_2_press);
  sput_run_test(test_buttons_3_press);

  sput_finish_testing();
  return sput_get_return_value();
}