#include <otto.h>

void setup() {
  otto_MotorInit(2,3,4,5);
}

void loop() {
  // put your main code here, to run repeatedly:
  Home();
}
