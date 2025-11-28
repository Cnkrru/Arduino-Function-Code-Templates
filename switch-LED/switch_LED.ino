#include<Arduino.h>

const int key =9; //给开关分配一个引脚
const int LED =13;//给led分配一个引脚

void setup()
{
  pinMode(key,INPUT_PULLUP);//将开关端口初始化为上拉输入模式
  pinMode(LED,OUTPUT);      //将led端口初始化为输出模式
}
void loop()
{
  int state =digitalRead(key);//把开关状态传递给一个变量
if(state==0)                  //通过该变量来决定led的状态
{
  digitalWrite(LED,HIGH);
}
else
{
  digitalWrite(LED,LOW);
}
/*解释为什么state为0（低电位）为led亮
这是上拉电阻模式下的开关控制模块
引脚出来后，默认与5V（含上拉电阻）相连
此时开关未闭合，read函数得到1
而我们要将read函数值传给write函数
我们的设计目标是：开关断开：熄灭
所以，read=1，write=0
上拉电阻板块：read与write相反
*/
//实际接线过程中，开关初始连接，一端连引脚，对称一端连上拉电阻+5V，不对称一端连GND




//另一种写法（推荐）
// ********************************************************************************
// bool state;                 // 相当于提前给开关定义中间bool值（推荐）
// const int PINLED1=6;
// const int key1=13;

// void setup()
// {
// pinMode(key1,INPUT_PULLUP);
// pinMode(PINLED1,OUTPUT);
// }

// void loop()
// {
//   state=digitalRead(key1);//将read结果传给中间bool值
//   if(!state)              //使用！更改输出结果（使其相反）（推荐）
//   {                       //也可以改下面代码中的HIGH和LOW
//     digitalWrite(PINLED1,LOW);
//   }
//   else
//   {
//     digitalWrite(PINLED1,HIGH);
//   }
// }
//**************************************************************************************