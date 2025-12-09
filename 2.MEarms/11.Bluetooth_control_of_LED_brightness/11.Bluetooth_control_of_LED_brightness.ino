//蓝牙控制LED
//蓝牙相当于把电脑上的串口监视器换成手机无线连接蓝牙的方式，其实代码是没变的，这里只是复习一下
#include<Arduino.h>

int LED=11;

void setup()
{
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()>0)
  {
    int num=Serial.parseInt();
    if(num>=0 && num<=255)
    {
      Serial.print("亮度变为:");
      Serial.println(num);
      analogWrite(11,num);
      delay(10);
    }
  }
}