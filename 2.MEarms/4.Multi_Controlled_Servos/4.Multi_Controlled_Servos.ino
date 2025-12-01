#include <Arduino.h>
#include <Servo.h>

Servo a_arm;//定义四个舵机
Servo b_arm;//abcd
Servo c_arm;
Servo d_arm;

int angle;//给角度一个变量

void setup()
{

  Serial.begin(9600);//启用串口
  a_arm.attach(11);//初始化舵机
  b_arm.attach(9);
  c_arm.attach(7);
  d_arm.attach(5);

}

void loop()
{

 if(Serial.available()>0)                //判断缓存是否>0
 {
  char servo=Serial.read();              //取走舵机编号
  Serial.print("旋转的舵机的编号为");     //打印出选择的舵机情况
  Serial.println(servo);

  int servonum=Serial.parseInt();        //取走舵机旋转角度

  if(servonum<=180 && servonum>=0)      //根据数值判断角度是否合理
  {         
  Serial.print("舵机旋转的角度为");      //打印旋转角度
  Serial.println(servonum);
  switch(servo)                        //根据旋转的舵机编号进行判断
{
    case 'a':                         //模板：选择对应舵机输出相应角度，再给出答复
    a_arm.write(angle);
    Serial.print("已旋转");
    Serial.println(angle);
    break;

    case 'b':
    b_arm.write(angle);
    Serial.print("已旋转");
    Serial.println(angle);
    break;

    case 'c':
    c_arm.write(angle);
    Serial.print("已旋转");
    Serial.println(angle);
    break;
    
    case 'd':
    d_arm.write(angle);
    Serial.print("已旋转");
    Serial.println(angle);
  }


  
 }
 else
 {
  Serial.println("请输入正确的角度");//角度不正确时的反馈
 }
  
}