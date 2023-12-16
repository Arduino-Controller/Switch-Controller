#include <Mouse.h>
#include <Wire.h>
#include <Keyboard.h>

# define UP 2
# define RIGHT 3
# define DOWN 4
# define LEFT 5
# define E 6
# define F 7
# define Joy_BT 8
# define Joy_X A0
# define Joy_Y A1
 int bottons[]={UP,RIGHT,DOWN,LEFT,E,F,Joy_BT};
 
void setup(){
  for(int i=0;i<7;i++) pinMode(bottons[i],INPUT);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop(){

  int up = digitalRead(UP);
  int right = digitalRead(RIGHT);
  int down = digitalRead(DOWN);
  int left = digitalRead(LEFT);
  int e = digitalRead(E);
  int f = digitalRead(F);
  int joy_bt = digitalRead(Joy_BT);
  int joy_x = analogRead(Joy_X);
  int joy_y = analogRead(Joy_Y);

  if(up==0){
    Keyboard.press('2');
  }
  else{
    Keyboard.release('2');
  }

  if(right==0){
    Keyboard.press(KEY_LEFT_CTRL);
  }
  else{
    Keyboard.release(KEY_LEFT_CTRL);
  }

  if(left==0){
    Keyboard.press('1');
  }
  else{
    Keyboard.release('1');
  }

  if(down==0){
    Keyboard.press(' ');
  }
  else{
    Keyboard.release(' ');
  }
  
  //사용하지 않는 버튼
  /*
  if(e==0){
    Keyboard.press('e');
  }
  else{
    Keyboard.release('e');
  }

  if(f==0){
    Keyboard.press('f');
  }
  else{
    Keyboard.release('f');
  }
  */

/*
  if(joy_bt==0){
    Keyboard.press('t');
  }
  else{
    Keyboard.release('t');
  }
*/
  
  if(joy_x<=100){
    Keyboard.press(KEY_LEFT_ARROW);
  }
  else{
    Keyboard.release(KEY_LEFT_ARROW);
  }

  if(joy_x>=1000){
    Keyboard.press(KEY_RIGHT_ARROW);
  }
  else{
    Keyboard.release(KEY_RIGHT_ARROW);
  }

  if(joy_y<=100){
    Keyboard.press(KEY_DOWN_ARROW);
  }
  else{
    Keyboard.release(KEY_DOWN_ARROW);
  }
  if(joy_y>=1000){
    Keyboard.press(KEY_UP_ARROW);
  }
  else{
    Keyboard.release(KEY_UP_ARROW);
  }

  delay(10);
}

/*
//스위치 조이스틱 및 버튼 값 시리얼 출력
void Switch_Print(){
  Serial.print("UP: ");Serial.println(up);
  Serial.print("RIGHT: ");Serial.println(right);
  Serial.print("LEFT: ");Serial.println(left);
  Serial.print("DOWN: ");Serial.println(down);
  Serial.print("E: ");Serial.println(e);
  Serial.print("F: ");Serial.println(f);
  Serial.print("Joy_BT: ");Serial.println(joy_bt);
  Serial.print("Joy_X: ");Serial.println(joy_x);
  Serial.print("Joy_Y: ");Serial.println(joy_y);

}
*/