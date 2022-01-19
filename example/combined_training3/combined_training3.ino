#include <otto.h>

void setup() {
  otto_MotorInit(2,3,4,5);
  Home();
  delay(2000);
}

void loop() {
  for(int i=0;i<3;i++){
    forward();
  }
   for(int i=0;i<3;i++){
    back();
  }
   for(int i=0;i<3;i++){
    turnLeft();
  }
   for(int i=0;i<3;i++){
    turnRight();
  }
}
