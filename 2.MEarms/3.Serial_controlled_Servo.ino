#include <Arduino.h>//包含串口通讯
#include <Servo.h>  //包含舵机

Servo servo0;       //定义舵机
int angle;           //定义角度

void setup()
{

  servo0.attach(9);              //初始化舵机
  Serial.begin(9600);            //初始化串口
  Serial.println("请输入角度0~180°");  //输出一段文字

}

void loop()
{

  if(Serial.available()>0)    //available函数几乎只用于if判断，判断缓存中有无数值，有数值再做出反应，无数值则不动
  {

    angle=Serial.parseInt();                //将缓存中的数值赋给中间值（注意，如果用read，只会输出一个数字）
    if(angle>=0 && angle<=180)              //判断角度是否合理
    {
    servo0.write(angle);                    //write函数输出
    Serial.print("已经旋转至目标角度");      //相当于c的print函数，末尾加上ln表示换行符/n
    Serial.println(angle);                  //打印角度
    }
    else
    {
    Serial.println("Error");                //角度不符合要求时候的情况
    Serial.println("请输入符合要求的数值");  //就是打印一段话
    }


  }
  else
  {

  }
}



