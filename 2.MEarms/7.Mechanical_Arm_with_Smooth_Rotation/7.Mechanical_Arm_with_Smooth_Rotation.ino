#include <Arduino.h>
#include <Servo.h>

//定义舵机
Servo a_arm;
Servo b_arm;
Servo c_arm;
Servo d_arm;


//调试角度结果
const int jiaodu1MIN=45;
const int jiaodu1MAX=180;
const int jiaodu2MIN=45;
const int jiaodu2MAX=180;
const int jiaodu3MIN=45;
const int jiaodu3MAX=180;
const int jiaodu4MIN=45;
const int jiaodu4MAX=180;

//后续要用的变量
int beginangle;//初始角度
int endangle;  //结果角度
int i;         //（递增）初始角度中间值
int j;         //（递减）初始角度中间值
int angle=90;     //角度初值，也用于存放parseInt中间值

//平滑旋转的模板函数
void angle_a()
{
  //给初始/结果角度赋值
  beginangle=a_arm.read();//新函数servo的read函数，读取当前舵机位置
  endangle=angle;         //parseInt中的值赋给结果值
  if(beginangle<=endangle)//判断应该往哪个方向转
  {

    for(i=beginangle;i<=endangle;i++)//递增函数实现平滑旋转（！注意要延时，延时才能平滑）
    {
    a_arm.write(i);
    delay(15);
    }

  }
  else                                //递减部分
  {
    for(j=beginangle;j>=endangle;j--)
    {
    a_arm.write(j);
    delay(15);
    }
  }
}
//剩下的几个复制粘贴，改一下即可

//b舵机函数部分
  void angle_b()
{
  beginangle=b_arm.read();
  endangle=angle;
  if(beginangle<=endangle)
  {

    for(int i=beginangle;i<=endangle;i++)
    {
    b_arm.write(i);
    delay(15);
    }
  }
  else
  {
    for(int j=beginangle;j>=endangle;j--)
    {
    b_arm.write(j);
    delay(15);
    }
  }
}
//c舵机函数部分
  void angle_c()
{
  beginangle=c_arm.read();
  endangle=angle;
  if(beginangle<=endangle)
  {

    for(int i=beginangle;i<=endangle;i++)
    {
    c_arm.write(i);
    delay(15);
    }
  }
  else
  {
    for(int j=beginangle;j>=endangle;j--)
    {
    c_arm.write(j);
    delay(15);
    }
  }
}

//d舵机函数部分
  void angle_d()
{
  beginangle=d_arm.read();
  endangle=angle;
  if(beginangle<=endangle)
  {

    for(int i=beginangle;i<=endangle;i++)
    {
    d_arm.write(i);
    delay(15);
    }
  }
  else
  {
    for(int j=beginangle;j>=endangle;j--)
    {
    d_arm.write(j);
    delay(15);
    }
  }

}

void setup()
{
//初始化
  a_arm.attach(11);
  b_arm.attach(9);
  c_arm.attach(7);
  d_arm.attach(5);
  Serial.begin(9600);

}

void loop()
{
  if(Serial.available()>0)//if常规判断缓存中有没有数值
{
  char arm=Serial.read();//将舵机编号读取走
  Serial.print("旋转的舵机为");
  Serial.println(arm);

  angle=Serial.parseInt();

  switch(arm)
  {
    case 'a':
    angle_a();//调用平滑旋转函数
    break;

    case 'b':
    angle_b();
    break;

    case 'c':
    angle_c();
    break;

    case 'd':
    angle_d();
    break;
  }

}
else
{

}
}