#include <Arduino.h>

void setup()
{

  Serial.begin(9600);            //启用串口通讯
  Serial.println("请输入数据");  //相当于C++中的cout

}

void loop()
{
  if(Serial.available()>0)     //根据available的值判断
  {
    int num =Serial.read();    //把read结果暂存在中间值（read函数常规操作）

    Serial.println(num);       //输出 
  }
  

}