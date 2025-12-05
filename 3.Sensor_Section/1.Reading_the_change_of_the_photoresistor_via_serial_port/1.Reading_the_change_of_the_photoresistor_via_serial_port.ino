//光敏电阻实际上是个自动电位器，我们这里只是读取光敏电阻给电路带来的变化，和1-10完全一样
#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("该光强等级为");
  Serial.println(analogWrite(A0));//直接读取A0的数值，也可以用中间值，以前都是用中间值读取
  delay(10);//延时！！！这个经常忘记，建议写个文档来提醒自己
}