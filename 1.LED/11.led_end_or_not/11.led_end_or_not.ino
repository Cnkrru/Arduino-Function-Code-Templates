//这里其实是将1-10的电位器部分用代码呈现出来
//和数字信号控制的一模一样
//另外新学：等比映射函数map

#include <Arduino.h>

const int analogled-9;//不写也行，其实写上是为了方便回看，不写不影响端口初始化

void setup()
{
  Serial.begin(9600);      //启动串口
  pinMode(9,OUTPUT);
}

void loop()
{
  int analongval=analogRead(analogled);     //和数字一样的步骤

  int lightness=map(analogval,0,1023,0,255);//使用map函数规范化，没有应该也行

  analogWrite(9,lightness);

  Serial.println(analogval);

}
