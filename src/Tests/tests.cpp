#include "Tests/tests.h"
#include "PinsConfig.h"
#include "Arduino.h"
#include "Global.h"
#include "sput.h"

void test_buttons_1_press()
{
  buttons.GetB1()->tick();
  digitalWrite(b1, HIGH);
  buttons.GetB1()->tick();
  delay(150);
  buttons.GetB1()->tick();
  sput_fail_unless(buttons.GetB1()->isPress(), "Button 1 click");
}

void test_buttons_2_press()
{
  buttons.GetB2()->tick();
  digitalWrite(b2, HIGH);
  buttons.GetB2()->tick();
  delay(150);
  buttons.GetB2()->tick();
  sput_fail_unless(buttons.GetB2()->isPress(), "Button 2 click");
}
void test_buttons_3_press()
{
  buttons.GetB3()->tick();
  digitalWrite(b3, HIGH);
  buttons.GetB3()->tick();
  delay(150);
  buttons.GetB3()->tick();
  sput_fail_unless(buttons.GetB3()->isPress(), "Button 3 click");
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