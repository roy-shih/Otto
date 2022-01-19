/**********************************************************
 ** otto Library 1.0 **
 * This library is unofficial. user can adjust the parameters
   of the robot to achieve the best use!
 
 * this library have serveral methods and function for beginner
   to use:
 Setup methods:
    otto_MotorInit(int pIN_YL,int pIN_YR,int pIN_RL,int pIN_RR);
    otto_UBInit(int buzzer pin, int ultrasonic trig pin, int ultrasonic echo pin );
 Marching methods:
    forward();
    back();
    turnLeft();
    turnRight();
 About footstep:
    traverseRight();  // traverse to the right
    traverseLeft();   // traverse to the left
    Step();
    tiptoe(int mode); // mode=1: pick up the toe
                         mode=2: put down the toes
                         mode=3: complete tip toe
 About ultrasonic:
    ultrasonic();      // using ultrasonic and print the distance
    ultrasonicRead();  // read the ultrasonic value ## this function return 'int' type
 Other:
    PhoneVoice();      // Make a ringtone from a traditional phone
    policeVoice();     // issus a police car alarm
 
         --------------- 
        |     O   O     |
        |---------------|
YR 3==> |               | <== YL 2
         ---------------
            ||     ||
            ||     ||
RR 5==>   -----   ------  <== RL 4
         |-----   ------|


* Author: Roy Shih
          2018.8.30 Macbook Pro
**********************************************************/

/******* setup homing angle *******/
int rest_YL= 85;
int rest_YR= 85;
int rest_RL= 85;
int rest_RR= 85;
/*********************************/


#include <Servo.h>

Servo servoYL;  // create servo object to control a servo
Servo servoYR;  // create servo object to control a servo
Servo servoRL;  // create servo object to control a servo
Servo servoRR;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
int PIN_YL ;  // right leg servo
int PIN_YR ;  // left leg servo
int PIN_RL ;  // right foot servo
int PIN_RR ;  // left foot servo
int buzzer ;
int trigpin ;
int echopin;
int T=5,delaysecond=500,dis=0,duration=0;
#define B0  31
#define C1  33
#define C1s 35
#define D1  37
#define D1s 39
#define E1  41
#define F1  44
#define F1s 46
#define G1  49
#define G1s 52
#define A1  55
#define A1s 58
#define B1  62

#define C2  65
#define C2s 69
#define D2  73
#define D2s 78
#define E2  82
#define F2  87
#define F2s 93
#define G2  98
#define G2s 104
#define A2  110
#define A2s 117
#define B2  123

#define C3  131
#define C3s 139
#define D3  147
#define D3s 156
#define E3  165
#define F3  175
#define F3s 185
#define G3  196
#define G3s 208
#define A3  220
#define A3s 233
#define B3  247

#define C  262
#define Cs 277
#define D  294
#define Ds 311
#define E  330
#define F  349
#define Fs 370
#define G  392
#define Gs 415
#define A  440
#define As 466
#define B  494

#define C5  523
#define C5s 554
#define D5  587
#define D5s 622
#define E5  659
#define F5  698
#define F5s 740
#define G5  784
#define S5s 831
#define A5  880
#define A5s 932
#define B5  988

#define C6  1047
#define C6s 1109
#define D6  1175
#define D6s 1245
#define E6  1319
#define F6  1397
#define F6s 1480
#define G6  1568
#define G6s 1661
#define A6  1760
#define A6s 1865
#define B6  1976

#define C7  2093
#define C7s 2217
#define D7  2349
#define D7s 2489
#define E7  2637
#define F7  2794
#define F7s 2960
#define G7  3136
#define G7s 3322
#define A7  3520
#define A7s 3729
#define B7  3951

#define C8  4186
#define C8s 4435
#define D8  4699
#define D8s 4978


void otto_MotorInit(int pIN_YL,int pIN_YR,int pIN_RL,int pIN_RR){
    int PIN_YL=pIN_YL ;  // right leg servo
    int PIN_YR = pIN_YR;  // left leg servo
    int PIN_RL =pIN_RL;  // right foot servo
    int PIN_RR =pIN_RR;  // left foot servo
    servoYL.attach(PIN_YL);// attaches the servoYL on PIN_YL to the servoYL object
    servoYR.attach(PIN_YR);// attaches the servoYR on PIN_YR to the servoYR object
    servoRL.attach(PIN_RL);// attaches the servoRL on PIN_RL to the servoRL object
    servoRR.attach(PIN_RR);// attaches the servoRR on PIN_RR to the servoRR object
}
void otto_UBInit(int buzz, int trig, int echo ){
    pinMode(buzz,OUTPUT);
    buzzer=buzz;
    noTone(buzz);
    Serial.begin(9600);
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    trigpin=trig;
    echopin=echo;
}

void Home(){
  servoRL.write(rest_RL);
  servoRR.write(rest_RR);
  servoYL.write(rest_YL);
  servoYR.write(rest_YR);
}

void forward(){
  for (pos = rest_YL; pos >= rest_YL-45; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
     servoYL.write(pos-5);
     servoYR.write(pos); 
     servoRL.write(rest_YL+15);
     servoRR.write(rest_YL+15);
     delay(T);                       // waits 15ms for the servo to reach the position
   }
   for (pos = rest_YL-45; pos <= rest_YL; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
     servoYL.write(pos-5); 
     servoYR.write(pos); 
     servoRL.write(rest_YL-15);
     servoRR.write(rest_YL-15);
     delay(T);                       // waits 15ms for the servo to reach the position
   }
   for (pos = rest_YL; pos <= rest_YL+45; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
     servoYL.write(pos+5); 
     servoYR.write(pos);  
     servoRL.write(rest_YL-15);
     servoRR.write(rest_YL-15);
     delay(T);                       // waits 15ms for the servo to reach the position
   }
   for (pos = rest_YL+45; pos >= rest_YL; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
     servoYL.write(pos+5); 
     servoYR.write(pos); 
     servoRL.write(rest_YL+15);
     servoRR.write(rest_YL+15);
     delay(T);                       // waits 15ms for the servo to reach the position
   }
}

void back(){
    for (pos = rest_YL; pos >= rest_YL-45; pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servoYL.write(pos- 5);
        servoYR.write(pos);
        servoRL.write(rest_YL-15);
        servoRR.write(rest_YL-15);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    for (pos = rest_YL-45; pos <= rest_YL; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servoYL.write(pos-5);
        servoYR.write(pos);
        servoRL.write(rest_YL+15);
        servoRR.write(rest_YL+15);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    for (pos = rest_YL; pos <= rest_YL+45; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servoYL.write(pos+5);
        servoYR.write(pos);
        servoRL.write(rest_YL+15);
        servoRR.write(rest_YL+15);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    for (pos = rest_YL+45; pos >= rest_YL; pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servoYL.write(pos+5);
        servoYR.write(pos);
        servoRL.write(rest_YL-15);
        servoRR.write(rest_YL-15);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
}

void turnRight(){
    for (pos = rest_YL; pos >=rest_YL-45; pos -= 1) {
        servoYL.write(pos+20); //+20
        servoYR.write(pos-20); //-10
        servoRL.write(rest_YL+15);
        servoRR.write(rest_YL+15);
        delay(T);
    }
    for (pos = rest_YL-45; pos <= rest_YL; pos += 1) {
        servoYL.write(pos+20); //+20
        servoYR.write(pos-20); //-10
        servoRL.write(rest_YL-15);
        servoRR.write(rest_YL-15);
        delay(T);
    }
    for (pos = rest_YL; pos <= rest_YL+45; pos += 1) {
        servoYL.write(pos-20); //-20
        servoYR.write(pos+20); // +10
        servoRL.write(rest_YL-15);
        servoRR.write(rest_YL-15);
        delay(T);
    }
    for (pos = rest_YL+45; pos >= rest_YL; pos -= 1) {
        servoYL.write(pos-20); //-20
        servoYR.write(pos+20); //+10
        servoRL.write(rest_YL+15);
        servoRR.write(rest_YL+15);
        delay(T);
    }
}

void turnLeft(){
    for (pos = rest_YL; pos >=rest_YL-45; pos -= 1) {
        servoYL.write(pos-20); //+20
        servoYR.write(pos+20); //-10
        servoRL.write(rest_YL+15);
        servoRR.write(rest_YL+15);
        delay(T);
    }
    for (pos = rest_YL-45; pos <= rest_YL; pos += 1) {
        servoYL.write(pos-20); //+20
        servoYR.write(pos+20); //-10
        servoRL.write(rest_YL-15);
        servoRR.write(rest_YL-15);
        delay(T);
    }
    for (pos = rest_YL; pos <= rest_YL+45; pos += 1) {
        servoYL.write(pos+20); //-20
        servoYR.write(pos-20); // +10
        servoRL.write(rest_YL-15);
        servoRR.write(rest_YL-15);
        delay(T);
    }
    for (pos = rest_YL+45; pos >= rest_YL; pos -= 1) {
        servoYL.write(pos+20); //-20
        servoYR.write(pos-20); //+10
        servoRL.write(rest_YL+15);
        servoRR.write(rest_YL+15);
        delay(T);
    }
}

void tiptoe(int m){
    if(m==1){
        for (pos = rest_YL; pos <= rest_YL+50; pos ++) {
            servoRL.write(pos);                             // 讓左腳從 90 度轉的到140度 -> 順時針轉 50 度
            servoRR.write(180-pos);                     // 讓右腳從 90 度轉的到 40 度 -> 逆時針轉 50 度
            delay(T);                                        // 等待 5 毫秒讓伺服馬達轉到 pos 度
        }
    }else if(m==2){
        for (pos = rest_YL+50; pos >= rest_YL; pos-- ) {
            servoRL.write(pos);                            // 讓左腳從 140 度轉的到 90 度 -> 逆時針轉 50 度
            servoRR.write(180-pos);                    // 讓右腳從 40 度轉的到 90 度 -> 順時針轉 50 度
            delay(T);                                         // 等待 5 毫秒讓伺服馬達轉到 pos 度
        }
    }else if(m==3){
        for (pos = rest_YL; pos <= rest_YL+50; pos ++) {
            servoRL.write(pos);                             // 讓左腳從 90 度轉的到140度 -> 順時針轉 50 度
            servoRR.write(180-pos);                     // 讓右腳從 90 度轉的到 40 度 -> 逆時針轉 50 度
            delay(T);                                        // 等待 5 毫秒讓伺服馬達轉到 pos 度
        }
        delay(delaysecond);                             // 讓 otto 踮腳一秒鐘
        for (pos = rest_YL+50; pos >= rest_YL; pos-- ) {
            servoRL.write(pos);                            // 讓左腳從 140 度轉的到 90 度 -> 逆時針轉 50 度
            servoRR.write(180-pos);                    // 讓右腳從 40 度轉的到 90 度 -> 順時針轉 50 度
            delay(T);                                         // 等待 5 毫秒讓伺服馬達轉到 pos 度
        }
        Home( );                                                       // 呼叫 Home( ) 副程式 -> 讓 otto 立正
        delay(delaysecond);                              // 讓 otto 立正一秒鐘
    }
}

void Step(){
    for (pos = rest_YL; pos <= rest_YL+60; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servoRL.write(pos);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    delay(delaysecond);
    for (pos = rest_YL+60; pos >= rest_YL; pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        // tell servo to go to position in variable 'pos'
        servoRL.write(pos);
        
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    delay(delaysecond);
    for (pos = rest_YL; pos >= rest_YL-60; pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        
        servoRR.write(pos);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    delay(delaysecond);
    for (pos = rest_YL-60; pos <= rest_YL; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        // tell servo to go to position in variable 'pos'
        
        servoRR.write(pos);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    delay(delaysecond);
}
void traverseLeft(){
    for (pos =  rest_YL; pos >=  rest_YL-60; pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servoRR.write(pos);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    for (pos =  rest_YL; pos <=  rest_YL+60; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        // tell servo to go to position in variable 'pos'
        servoRL.write(pos);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    for (pos =  rest_YL-60; pos <=  rest_YL; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        // tell servo to go to position in variable 'pos'
        servoRR.write(pos);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    for (pos =  rest_YL+60; pos >=  rest_YL; pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servoRL.write(pos);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
}
void traverseRight(){
    for (pos = rest_YL; pos >= rest_YL-60; pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servoRR.write(pos);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    for (pos = rest_YL; pos <= rest_YL+60; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        // tell servo to go to position in variable 'pos'
        servoRL.write(pos);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    for (pos = rest_YL-60; pos <= rest_YL; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        // tell servo to go to position in variable 'pos'
        servoRR.write(pos);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
    for (pos =rest_YL+60; pos >= rest_YL; pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servoRL.write(pos);
        delay(T);                       // waits 15ms for the servo to reach the position
    }
}
void PhoneVoice(){
    for ( int ii=0; ii<10; ii++ ) {
        
        tone(buzzer,1000);
        
        delay(50);
        
        tone(buzzer,500);
        delay(50);
    }
    noTone(buzzer);
    delay(2000);
}
void ultrasonic(){
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigpin,LOW);
    duration = pulseIn(echopin,HIGH);
    dis = (duration*0.034/2);
    Serial.print("Distance = ");
    Serial.print(dis);
    Serial.println(" cm" );
    delay(100);
}

int ultrasonicRead(){
    ultrasonic();
    return dis;
}

void policeVoice(){
    for (int i=150; i<1800; i++) {
        tone(buzzer, i, 10);
        delay(1);
    }
    for (int i=1800; i>150; i--) {
        tone(buzzer, i, 10);
        delay(1);
    }
}
void Forward(int n){
    if(n==0){
        forward();
    }else if(n==1){
        forward();
        Home();
    }
}
