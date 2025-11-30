#include <Arduino.h>

int i;

void setup()
{

  for(i=1;i<10;i++)
  {
    pinMode(i,OUTPUT);
  }

}

void loop()
{
//被注释掉的为基础版，后面有for简化的，另外，digital后面的字母要大写，一些W并未大写
// digitalWrite(1,HIGH);
// delay(500);
// digitalwrite(1,LOW);

// digitalWrite(2,HIGH);
// delay(500);
// digitalwrite(2,LOW);

// digitalWrite(3,HIGH);
// delay(500);
// digitalwrite(3,LOW);

// digitalWrite(4,HIGH);
// delay(500);
// digitalwrite(4,LOW);

// digitalWrite(5,HIGH);
// delay(500);
// digitalwrite(5,LOW);

// digitalWrite(6,HIGH);
// delay(500);
// digitalwrite(6,LOW);

// digitalWrite(7,HIGH);
// delay(500);
// digitalwrite(7,LOW);

// digitalWrite(8,HIGH);
// delay(500);
// digitalwrite(8,LOW);

// digitalWrite(9,HIGH);
// delay(500);
// digitalwrite(9,LOW);

//for循环精简
int j;
for(j=1;j<10;j++)
{
digitalWrite(j,HIGH);
delay(500);
digitalWrite(j,LOW);
}


}