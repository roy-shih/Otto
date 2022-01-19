#include <otto.h>

void setup() {
  otto_MotorInit(2,3,4,5);
  Home();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  traverseRight();
}
