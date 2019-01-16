//定义左电机引脚
#define INA_1 12
#define INB_1 13
#define PWM_1 PC_6
//定义右电机引脚
#define INA_2 5
#define INB_2 6
#define PWM_2 PC_5
//声明函数
void move_forward();
void move_left();
void move_right();
void stop();
void move_backward();
void setup()    //将引脚设置为输出模式
{
  pinMode(INA_1,OUTPUT);
  pinMode(INB_1,OUTPUT);
  pinMode(PWM_1,OUTPUT);
  pinMode(INA_2,OUTPUT);
  pinMode(INB_2,OUTPUT);
  pinMode(PWM_2,OUTPUT);
}
void loop()
{
//前进五秒
move_forward();
delay(5000);       //停止一秒
stop();
delay(1000);
//后退五秒
move_backward();
delay(5000);       //停止一秒
stop();
delay(1000);
//向左五秒
move_left();
stop();
delay(1000);
move_forward();
delay(5000);
stop();
delay(1000);
//向右五秒
move_right();
stop();
delay(1000);
move_forward();
delay(5000);
stop();
delay(1000);
}
void move_forward()
{
//左电机顺时针转动
digitalWrite(INA_1,HIGH);
digitalWrite(INB_1,LOW);
analogWrite(PWM_1,255);//PWM控制速度 范围0~255 255指全速运动
//右电机逆时针转动
digitalWrite(INA_2,HIGH);
digitalWrite(INB_2,LOW);
analogWrite(PWM_2,255);
}
void move_left()
{
//左电机逆时针转动
digitalWrite(INA_1,LOW);
digitalWrite(INB_1,HIGH);
analogWrite(PWM_1,0);
//右电机逆时针转动
digitalWrite(INA_2,LOW);
digitalWrite(INB_2,HIGH);
analogWrite(PWM_2,255);
delay (5000);//此处为转向时间，根据电机转动速度以及实际转过的角度调试
}
void move_right()
{
//左电机顺时针转动
digitalWrite(INA_1,HIGH);
digitalWrite(INB_1,LOW);
analogWrite(PWM_1,255);
//右电机顺时针转动
digitalWrite(INA_2,HIGH);
digitalWrite(INB_2,LOW);
analogWrite(PWM_2,0);
delay (5000);
}
void stop()
{
//左电机制动
digitalWrite(INA_1,LOW);
digitalWrite(INB_1,LOW);
analogWrite(PWM_1,0);
//右电机制动
digitalWrite(INA_2,LOW);
digitalWrite(INB_2,LOW);
analogWrite(PWM_2,0);
}
void move_backward()
{
//左电机逆时针转动
digitalWrite(INA_1,LOW);
digitalWrite(INB_1,HIGH);
analogWrite(PWM_1,255);
//右电机顺时针转动
digitalWrite(INA_2,HIGH);
digitalWrite(INB_2,LOW);
analogWrite(PWM_2,255);
}
