#include <Arduino.h>

int pinnum=1;
void setup()
{
  while(pinnum<8)             //使用while循环初始化（推荐），建议将同种功能的模块的引脚定义在一起，这样可以优化代码
  {
    pinMode(pinnum,OUTPUT);
    pinnum++;                 //不要忘记写递增！！！（补充：也可以用for循环）
  }
}

void loop()
//   1
//6     2
//   7
//5     3
//   4
{
  int num=random(1,10);
  switch(num)                    //用switch处理多情况（1~9+0）10种数字的闪烁
                                 //也可以使用if else
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
    default:
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
  }
  delay(1000);    //进行一个延时，后续会刷新界面
             
//重置             
digitalWrite(1,LOW);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
delay(500);

}