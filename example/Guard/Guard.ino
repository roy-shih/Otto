#include<otto.h>                                    

void setup() {
  otto_UBInit(10,8,9);
}

void loop() {
  int distance = ultrasonicRead();
  if( distance < 10 && distance > 0){                        // 判斷距離使否小於 10？是：從33行開始執行；否：回到31行
      policeVoice();
   } 
}
