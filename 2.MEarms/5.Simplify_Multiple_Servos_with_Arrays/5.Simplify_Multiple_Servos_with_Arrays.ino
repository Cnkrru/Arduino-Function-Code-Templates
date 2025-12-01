//对于存在很多相同类型元素的代码，可以用数组进行简化
#include <Arduino.h>
#include <Servo.h>

Servo a_arm;//定义舵机
Servo b_arm;
Servo c_arm;
Servo d_arm;
int i;//for循环的变量，要牢记，经常忘记定义

int data[4][5]=
{
{0,45,90,135,180},//定义舵机旋转角度的数组
{45,90,135,180,0},//格式要规范
{90,135,180,0,45},
{135,180,0,45,90}
};

void setup()
{
  a_arm.attach(11);//初始化舵机
  b_arm.attach(9);//要记得分配引脚，经常忘记
  c_arm.attach(7);
  d_arm.attach(5);
}


void loop()
{
  for(i=0;i<5;i++)
  {
    a_arm.write(data[0][i]);//for循环简化步骤
    b_arm.write(data[1][i]);//注意复制粘贴完改一下
    c_arm.write(data[2][i]);
    d_arm.write(data[3][i]);
    delay(500);              //!!!一定不要忘记给延时，要不然机器坏了
  }

  for(i=4;i>=0;i--)
  {
    a_arm.write(data[0][i]);
    b_arm.write(data[1][i]);
    c_arm.write(data[2][i]);
    d_arm.write(data[3][i]);  
    delay(500);
  }
}
