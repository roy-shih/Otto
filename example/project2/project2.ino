#include<otto.h>
int notes[] ={
  G,G,A,G,C5,B,0,
  G,G,A,G,D5,C5,0,
  G,G,G5,E5,C5,B,A,
  F5,F5,E5,C5,D5,C5
};
// 決定每個音階的拍子，注意這邊用 unsigned long 所以拍子只能是正整數
byte beats[] = {
1,1,2,2,2,3,1,
1,1,2,2,2,3,1,
1,1,2,2,2,2,4,
1,1,2,2,2,4
};

void setup() {
  // put your setup code here, to run once:
  otto_MotorInit(2,3,4,5);
  otto_UBInit(10,8,9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = ultrasonicRead();
  if(distance<10 && distance>0){
    for(int i=0;i<7;i++){
      int times = beats[i]* 200;
      tone(10, notes[i], times);
      delay(times*1.3);
    }  
    tiptoe(1);
    for(int i=7;i<14;i++){
      int times = beats[i]* 200;
      tone(10, notes[i], times);
      delay(times*1.3);
    }  
    tiptoe(2);
    for(int i=14;i<21;i++){
      int times = beats[i]* 200;
      tone(10, notes[i], times);
      delay(times*1.3);
    }  
    tiptoe(1);
    for(int i=21;i<27;i++){
      int times = beats[i]* 200;
      tone(10, notes[i], times);
      delay(times*1.3);
    }  
    tiptoe(2);
    delay(100);
    noTone(10);
  }
  Home();
}
