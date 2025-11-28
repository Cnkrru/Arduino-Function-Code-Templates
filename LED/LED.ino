#include<Arduino.h>

const LEDPIN =13;//给led选择一个端口

void setup()
{
  pinMode(LEDPIN,OUTPUT);//将端口设置为输出模式
}
void loop()
{
  digitalWrite(LEDPIN,HIGH);//端口供高电位
  delay(3000);              //延时3s
  digitalwrite(LEDPIN,LOW); //端口供电低电位
  delay(3000);              //延时3s
}
