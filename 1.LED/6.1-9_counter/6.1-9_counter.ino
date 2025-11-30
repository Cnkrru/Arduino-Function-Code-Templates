#include <Arduino.h>

int i;                   //常规for循环初始化端口
const int key=13;
 
void clean()            //常规清屏函数
{
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
}

void setup()
{

  for(i=1;i<8;i++)
  {
    pinMode(i,OUTPUT);
  }

  pinMode(key,INPUT_PULLUP);
}

int addition=0;               //按钮控制变量
int laststate=HIGH;           //常规控制模板

void loop()
{
  int state=digitalRead(key);
  
  if(state==0 && laststate==HIGH)    //模板
  {

    clean();
  
    delay(200);

  addition++;
  if(addition==10)
  {
    addition=0;
  }

  switch(addition)
  {
    case 1:
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    break;

    case 2:
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
    break;

    case  3:
    digitalWrite(1,HIGH); 
    digitalWrite(2,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    break;

    case 4:
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    break;

    case 5:
    digitalWrite(1,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    break;

    case 6:
    digitalWrite(1,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(7,HIGH);
    break;

    case 7:
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    break;

    case 8:
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    break;

    case 9:
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    break;
     //写完发现貌似用不上？
    default:
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    break;

  } 
  }
    laststate=state;

}