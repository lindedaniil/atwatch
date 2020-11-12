#include "Tests/tests.h"
#include "PinsConfig.h"
#include "Arduino.h"
#include "Global.h"
#include "App/ApplicationManager.h"
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

void direct_menu_navigation()
{
  applicationManager.SetMenu(Apps::MainClock);
  applicationManager.GetCurApp()->Update();
  sput_fail_unless(applicationManager.GetCurApp() == applicationManager.GetApp(Apps::MainClock), "Move to main screen");
  delay(200);
  applicationManager.SetMenu(Apps::MainMenu);
  applicationManager.GetCurApp()->Update();
  sput_fail_unless(applicationManager.GetCurApp() == applicationManager.GetApp(Apps::MainMenu), "Move to main menu");
  delay(200);
}

void integration_menu_navigation()
{
  //reset menu
  applicationManager.SetMenu(Apps::MainClock);
  applicationManager.GetCurApp()->Update();

  //simulation buuton click
  buttons.GetB3()->tick();
  digitalWrite(b3, HIGH);
  buttons.GetB3()->tick();
  delay(150);
  buttons.GetB3()->tick();

  //check menu
  sput_fail_unless(applicationManager.GetCurApp() == applicationManager.GetApp(Apps::MainMenu), "Move to main menu");
} 

int run_tests()
{
  while (!Serial);
  sput_start_testing();

  sput_enter_suite("buttons");
  sput_run_test(test_buttons_1_press);
  sput_run_test(test_buttons_2_press);
  sput_run_test(test_buttons_3_press);
  sput_enter_suite("direct menu navigation");
  sput_run_test(direct_menu_navigation);
 // sput_enter_suite("integration menu navigation");
  //sput_run_test(integration_menu_navigation);

  sput_finish_testing();
  return sput_get_return_value();
}