//读取人体红外传感器的变化，其实传感器貌似都差不多？

int irsenser=7;
int state;           //给一个中间值存储电位信息，其实不给也行

void setup()
{
  pinMode(irsensor,INPUT);   //设置读取模式
  Serial.begin(9600);
  Serial.println("sensor change")
}

void loop()
{
  state=digitalRead(irsensor);            //和1中的led的其实都一样
  if(state==1)
  {
    Serial.println("此时有人经过")
  }
  else
  {
    Serial.println("此时无人经过")
  }
}