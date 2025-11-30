//串口观察电位器控制led
//这里led变化由电位器引起，与代码无关，这部分代码只用于读取数值
//所以，这段代码其实和1-2没区别
//就当复习一下串口的调用
//这里需要明白电位器的原理（其实就是滑动变阻器）
#include <Arduino.h>

void setup()
{
  Serial.begin(9600;)
}

void loop()
{
  int analog=analogRead(A0);//将模拟信号传递给中间值
  Serial.println(analog);   //串口监视器读取中间值
}