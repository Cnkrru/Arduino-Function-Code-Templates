//在写这个代码过程中，建议封装函数

#include <Arduino.h>

int i;                 //这里使用for循环进行output的初始化（推荐）     标注：这里的i可以写成PINNUM（建议)
int key=13;

void clean()
{
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(500);
}

void setup()
{

for(i=1;i<8;i++)             //按习惯来说：for经常是从0开始，但这里要注意自己定义的第一个引脚是几号
{
  pinMode(i,OUTPUT);
}

  pinMode(key,INPUT_PULLUP); //初始化开关

}



//   1
//6     2
//   7
//5     3
//   4
 int laststate=HIGH;                  //解释为什么写这一段：
                                      //按下按钮前后是0/1两个状态
                                      //我们要用两个状态同时控制，才能实现按一次，倒计时一次。
                                      //按下之前，默认是HIGH，所以laststate是HIGH
                                      //如果不写。长时间按住按钮，会导致持续循环地倒计时
                                      //注意：中间不是==，==是比较运算符

void loop()
{
  int state=digitalRead(key);

 
  if(state==0 && laststate==HIGH)               //剩下的就是不断的复制粘贴
                           //注意：void loop不是说一定要用，当需要循环不断的过程才用
{//9
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    delay(500);

 clean();
//8
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    delay(500);

 clean();
//7
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH); 
    delay(500);

 clean();
//6
    digitalWrite(1,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(7,HIGH); 
    delay(500);

 clean();
//5
    digitalWrite(1,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    delay(500);

 clean();
//4
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    delay(500);

 clean();
//3
    digitalWrite(1,HIGH); 
    digitalWrite(2,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    delay(500);

 clean();
//2
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH); 
    delay(500);

 clean();
//1
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH); 
    delay(500);

 clean();
//0
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    delay(500);

 clean();

}
laststate=state;//配合loop开始阶段，相当于一次状态交换

else                //松开状态
{
digitalWrite(1,LOW);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);

}

}