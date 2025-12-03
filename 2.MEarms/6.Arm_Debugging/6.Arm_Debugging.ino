//这其实是对2-3的补充，添加一个限制角度，不过貌似还没实现限制的功能
//2-4和2-5是固定角度循环运动，不受人控制。
//学会舵机使用，可以制作机械臂和小车

#include <Arduino.h>//不要忘记头文件
#include <Servo.h>

//定义舵机
Servo a_arm;
Servo b_arm;
Servo c_arm;
Servo d_arm;

//舵机初始角度值
int jiaodu1=90;
int jiaodu2=90;
int jiaodu3=90;
int jiaodu4=90;


//调试部分，确定舵机最大旋转角度
const int a_anglemin=45;
const int a_anglemax=180;
const int b_anglemin=45;
const int b_anglemax=180;
const int c_anglemin=45;
const int c_anglemax=180;
const int d_anglemin=45;
const int d_anglemax=180;

//定义舵机旋转角度的函数，写好一个，其他复制粘贴就好
void angle_a()
{
  jiaodu1=Serial.parseInt();
  a_arm.write(jiaodu1);
  delay(20); 
  Serial.print("已选择");
  Serial.println(jiaodu1);
}
void angle_b()
{
  jiaodu2=Serial.parseInt();
  b_arm.write(jiaodu2);
  delay(20); 
  Serial.print("已选择");
  Serial.println(jiaodu2);
}
void angle_c()
{
  jiaodu3=Serial.parseInt();
  c_arm.write(jiaodu3);
  delay(20);                        //不要忘记给延时！！！
  Serial.print("已选择");
  Serial.println(jiaodu3);
}
void angle_d()
{
  jiaodu4=Serial.parseInt();
  d_arm.write(jiaodu4);
  delay(20); 
  Serial.print("已选择");
  Serial.println(jiaodu4);
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
//一定要记得写if，这是判断缓存中有没有值，一定要有，这个函数的功能，基本上就是个判断
  if(Serial.available()>0)
  {
    char arm=Serial.read();
    Serial.print("机械臂编号为");
    Serial.println(arm);

    switch(arm)
    {
      case 'a':
      angle_a();
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
  //缓存没有数值，没反应
  else
  {

  } 
}