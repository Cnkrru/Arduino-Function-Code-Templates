#include<Arduino.h>

const int key=13;//给开关一个端口

void setup()
{
  pinMode(key,INPUT_PULLUP);//初始化开关端口
  Serial.begin(9600);       //初始化串口通讯器
}
void loop()
{
  int sensorVal=digitalRead(key);//把开关端口的状态赋给一个值
  Serial.println(sensorVal);     //根据开关端口状态反应
}