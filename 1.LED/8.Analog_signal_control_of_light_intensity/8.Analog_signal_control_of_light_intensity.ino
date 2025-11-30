#include <Arduino.h>

const int key1=1;
const int key2=2;
const int light=13;
int lightness=124;     //给予亮度初值（analogWrite函数参数）

void setup()
{
  pinMode(key1,INPUT_PULLUP);
  pinMode(key2,INPUT_PULLUP);
  pinMode(light,OUTPUT);
  Serial.begin(9600);  //启用串口监视器，观察参数变化
}

void loop()
{
  k1=digitalRead(key1);
  k2=digitalRead(key2);

  if(!k1 && light>0 )
  {
    lightness++;
  }

  else(!k2 && light<255)
  {
    lightness--
  }

  analogWrite(light,lightness);//输出模拟数值
  Serial.println(lightness);
  delay(20);

}