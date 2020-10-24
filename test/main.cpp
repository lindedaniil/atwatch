#ifndef UNIT_TEST // disable program main loop while unit testing in progress

#include <Arduino.h>

void blink_once(unsigned int delay_ms)
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delay_ms);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delay_ms);
}


void setup() {
    Serial.begin(9600);
    Serial.println("Program started!");
}

void loop() {
    Serial.print("Addition: ");
    blink_once(200);
    Serial.print("Subtraction: ");
    blink_once(200);
    Serial.print("Multiplication: ");
    blink_once(200);
    Serial.print("Division: ");
    blink_once(200);
}

#endif