//for循环先前早已用过，for循环都可以改成while循环
//这里是一个变化闪烁led的程序
//实操需要改接口

#include <Arduino.h>
const int light=3;  //这里仅仅是个例子，需要把接口定义在pwm接口
int lightness=127;  //光强初值
int i;              //用于替代lightness，方便书写 

void setup()
{
  pinMode(light,OUTPUT);
}

void loop()
{

  i=lightness;
  for(i=0;i<=255;i++)        //for循环自动控制光强，if开关控制光强
  {
    analogWrite(light,i);
    delay(10);
  }

  for(i=255;i>=0;i--)
 {
    analogWrite(light,i);
    delay(10);
 }

}