#include <LedToggle.h>

LedToggle led(LED_BUILTIN, 250);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  led.toggle();
}
