#include<otto.h>
void setup() {
  // put your setup code here, to run once:
  otto_UBInit(0,8,9);
}

void loop() {
  // put your main code here, to run repeatedly:
  ultrasonic();
}

