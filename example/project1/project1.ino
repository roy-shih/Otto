#include<otto.h>

void setup() {
  // put your setup code here, to run once:
  otto_MotorInit(2,3,4,5);
  otto_UBInit(0,8,9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = ultrasonicRead();
  if(distance<10 && distance>0){
    forward();
  }
}
