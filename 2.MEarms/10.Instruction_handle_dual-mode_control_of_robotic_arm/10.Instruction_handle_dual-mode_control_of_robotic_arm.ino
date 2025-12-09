//2-10是给机械臂增加一种工作状态：手柄模式
//直接把2-9的代码复制了过来并增添新的模式
#include<Arduino.h>
#include<Servo.h>

Servo a_arm;
Servo b_arm;
Servo c_arm;
Servo d_arm;
Servo Servo0;                     //定义一个舵机中间变量  

const int a_armMAX=180;
const int b_armMAX=180;
const int c_armMAX=180;
const int d_armMAX=180;
const int a_armMIN=45;
const int b_armMIN=45;
const int c_armMIN=45;
const int d_armMIN=45;

//int ti=15;定义舵机旋转速度的时间,这里没用上，看个人习惯，我习惯void无参数函数，你可以给参数，把这个用上

//************************************************//setup前定义的全局变量
    int jiaodu_a;
    int jiaodu_b;
    int jiaodu_c;
    int jiaodu_d; 
     //以上是读取舵机当前状态所需变量 ，用于case o的读取
//***********************************************//

//**********************************************//  增加手柄模式
bool mode=1;
//当mode=1，指令模式
//当mode=0，手柄模式
int padstep=3;//手柄模式每次移动角度
int zhiling;  //定义手柄模式的编号
//*********************************************//

void setup()
{
  //初始化舵机
  a_arm.attach(11);
  delay(200);
  b_arm.attach(9);
  delay(200); 
  c_arm.attach(7);
  delay(200);
  d_arm.attach(5);
  delay(200);
  //初始化舵机位置
  a_arm.write(90);
  delay(20);
  b_arm.write(90);
  delay(20);
  c_arm.write(90);
  delay(20);
  d_arm.write(90);
  delay(20);
  //加延时是为了稳定

  Serial.begin(9600);
  Serial.println("欢迎使用机械臂");

}
  //**************************************************//    全局变量定义板块
    char bianhao;                   //机械臂舵机编号
    int jiaodu1;                    //舵机旋转终止角度
  //**************************************************************//上面是Serial.available判断阶段所需变量
  //                                                                 其中jiaodu1也用于读取终止角度

    int jiaodu0;                    //舵机旋转初始角度
    int i;                          //for语句中间量
  //***************************************************************//以上是舵机平滑旋转所需变量
    char worry;                     //存储错误编号
    int worrynum;                   //存储错误角度数值
  //**************************************************************//以上是错误缓存清除所需变量

//********************************************************************//        第二层函数  选择舵机
void ArmServer()
{
  //*****************************************************************//   A舵机
switch(bianhao)
{
  case 'a':
  jiaodu_a=a_arm.read();
  jiaodu0=a_arm.read();
  Servo0=a_arm;
  if(jiaodu1<=a_armMAX && jiaodu1>=a_armMIN)
  {
    ARMGO();
  }
  else
  {
    BAOCUO();
  }
  break;
//*****************************************************//         B舵机
  case 'b':
  jiaodu_b=b_arm.read();
  jiaodu0=b_arm.read();
  Servo0=b_arm;
  if(jiaodu1<=b_armMAX && jiaodu1>=b_armMIN)
  {
    ARMGO();
  }
  else
  {
    BAOCUO();
  }
  break;
//****************************************************//          C舵机
  case 'c':
  jiaodu_c=c_arm.read();
  jiaodu0=c_arm.read();
  Servo0=c_arm;
  if(jiaodu1<=c_armMAX && jiaodu1>=c_armMIN)
  {
    ARMGO();
  }
  else
  {
    BAOCUO();
  }
  break;
//*************************************************//         D舵机
  case 'd':
  jiaodu_d=d_arm.read();
  jiaodu0=d_arm.read();
  Servo0=d_arm;
  if(jiaodu1<=d_armMAX && jiaodu1>=d_armMIN)
  {
    ARMGO();
  }
  else
  {
    BAOCUO();
  }
  break;
}
//**************************************************//

//*************************************************//         第三层函数（舵机运行）
void ARMGO()
{
if(jiaodu0<jiaodu1)
      {
        for(int i=jiaodu0;i<=jiaodu1;i++)
        {
          Servo0.write(i);
          delay(10);
        }
      }
      else
      {
        for(int i=jiaodu0;i>=jiaodu1;i--)
        {
          Servo0.write(i);
          delay(10);
        }
      }  
}
//***************************************************//

//***************************************************//         第三层函数(舵机报错)
void BAOCUO()
{
  Serial.println("Warning:请输入正确角度,角度错误！！！");
}
//**************************************************//

//****************************************************************************//恢复函数（第二层函数）
    void armbegin()
  {
  a_arm.write(90);
  delay(20);
  b_arm.write(90);
  delay(20);
  c_arm.write(90);
  delay(20);
  d_arm.write(90);
  delay(20);    
  }
//*******************************************************************//

//*******************************************************************//状态函数（第二层函数）显示当前状态
void state()
{
     Serial.println("此时机械臂的状态为：");
     Serial.print("A_arm:");   
     Serial.println(jiaodu_a);
     Serial.print("B_arm:");   
     Serial.println(jiaodu_b);
     Serial.print("C_arm:");   
     Serial.println(jiaodu_c);
     Serial.print("D_arm:");   
     Serial.println(jiaodu_d);
}
//*******************************************************************//          第一层函数（指令模式编号区分层）
  void Server()
  {
    if(bianhao=='a' || bianhao=='b' || bianhao=='c' || bianhao=='d')      //根据输入的字母，判断三种情况
    {
       Serial.println("该舵机即将运行");
       ArmServer();                                                                       //调用舵机运行函数
    }
    else if(bianhao==8 || bianhao==4 || bianhao==5 || bianhao==6 || bianhao==1 || bianhao==2 || bianhao==3 || bianhao==0)
    {
      Serial.println("warning:机械臂正处于指令模式,请输入正确指令");   //对两模式指令混输进行区分
      delay(100);
      while(Serial.available()>0)
      worry=Serial.read();
      return;
    }
    else if(bianhao=='o')
    {
          state();                                                      //调用状态函数
    }
    else if(bianhao=='y')
    {
      armbegin();                                   //调用复原函数
    }
      //*******************手柄模式********************//
    else if(bianhao=='m')
    {
      mode=0;
      Serial.println("已切换至手柄模式");
    }
      //********************************************//
    else
    {
      Serial.println("请输入正确信息");
    }
  }
//***********************************************************************//

//**********************************************************************//        第一层函数 （手柄模式）
void pad()
{
  if(bianhao=='a' || bianhao=='b' || bianhao=='c' || bianhao=='d')      //手柄模式错误指令的反馈
    {
       Serial.println("机械臂正处于手柄模式,请输入正确指令");
       //******************清除错误指令****************//    
       while(Serial.available()>0)
       worry=Serial.read();
       worrynum=Serial.parseInt();
       return;                   //返回，不继续进行判断（貌似没必要）
    }
  else
  {
  switch(zhiling)
  {
    //**********************************************上升模块*********************************//
    case 8:
    bianhao='a';                                  //按下8，对应编号a舵机，
    jiaodu0=a_arm.read();                         //这里是为了给舵机运动函数初始角度数值
    jiaodu1=jiaodu0+padstep;                      //结尾角度数值
    ArmServer();                                  //调用运动函数
    break;

    case 4:
    bianhao='b';
    jiaodu0=b_arm.read();
    jiaodu1=jiaodu0+padstep;
    ArmServer();
    break;

    case 5:
    bianhao='c';
    jiaodu0=c_arm.read();
    jiaodu1=jiaodu0+padstep;
    ArmServer();
    break;

    case 6:
    bianhao='d';
    jiaodu0=d_arm.read();
    jiaodu1=jiaodu0+padstep;
    ArmServer();
    break;
     //*************************************下降模块*****************************//
    case 0:
    bianhao='a';
    jiaodu0=a_arm.read();
    jiaodu1=jiaodu0-padstep;
    ArmServer();
    break;

    case 1:
    bianhao='b';
    jiaodu0=b_arm.read();
    jiaodu1=jiaodu0-padstep;
    ArmServer();
    break;

    case 2:
    bianhao='c';
    jiaodu0=c_arm.read();
    jiaodu1=jiaodu0-padstep;
    ArmServer();
    break;

    case 3:
    bianhao='d';
    jiaodu0=d_arm.read();
    jiaodu1=jiaodu0-padstep;
    ArmServer();
    break;
     //*******************************************************************//
    case 'm':                                   //切换回指令模式
    mode=1;
    Serial.println("已切换至指令模式");
    break;
     //******************************************************************//
    case 'o':                                 //显示当前状态
    state();
    break;
  }
  }
}

void loop()
{
 if(Serial.available()>0)
 {
    if(mode==1)                     //指令模式
    {
       bianhao=Serial.read();
       jiaodu1=Serial.parseInt();
    Server();
    Serial.println("现在为指令模式");   //（指令模式）调用舵机判断函数
    }
     else
     {
      zhiling=Serial.read();
      pad();                              //手柄模式函数
      Serial.println("现在为手柄模式");     
     } 
  }
}