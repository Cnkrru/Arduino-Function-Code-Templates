#include <Servo.h>

//整体使用其实和led模拟控制类似。
//可以把电机当作led的模拟模式
//可以和1-9对比着看，这里是加上了串口监视器的观察代码，去掉观察代码，几乎一模一样

Servo servo0;//相当于 数据类型+名称（注意：控制线要连接在pwm接口，另外两条，一条0V，一条5V
int pos =0;  //给旋转角度定义的变量

void setup()
{

  servo0.attach(9);//pinmode的电机版本
  Serial.begin(9600);    //串口观察变化,别忘记给参数 

}

void loop()
{

  for(pos=0;pos<=180;pos++)
  {
    servo0.write(pos);  //相当于led的digitalwrite（输出）
    delay(20);          //给电机旋转一个缓冲时间
    Serial.println;
  }

  for(pos=180;pos>=0;pos--)
  {
    servo0.write(pos);
    delay(20);
    Serial.println
  }
}