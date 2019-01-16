//定义编码器引脚
#define Left_Encoder_CA 31
#define Left_Encoder_CB 32
volatile long CPRL = 0;//定义并初始化存放左编码器计数次数的变量
#define Right_Encoder_CA 33
#define Right_Encoder_CB 34
volatile long CPRR = 0;//定义并初始化存放右编码器计数次数的变量
bool LeftEncoderSet;
bool RightEncoderSet;
void SetupEncoders();//声明函数
void do_Left_Encoder();
void do_Right_Encoder();
void Update_Encoders();
void setup()
{
  Serial.begin(115200);//初始化波特率
  SetupEncoders();//设置引脚输入输出的函数，引脚初始化
}
void loop()
{
  Update_Encoders();
}
void SetupEncoders()
{
  //设置左编码器引脚模式
  pinMode(Left_Encoder_CA,INPUT_PULLUP);
  pinMode(Left_Encoder_CA,INPUT_PULLUP);
  attachInterrupt(Left_Encoder_CA,do_Left_Encoder,RISING);//设置左编码器中断输入引脚A通道引脚
  //设置右编码器引脚
  pinMode(Right_Encoder_CA,INPUT_PULLUP);
  pinMode(Right_Encoder_CB,INPUT_PULLUP);
  attachInterrupt(Right_Encoder_CA,do_Right_Encoder,RISING);//设置右编码器中断输入引脚B通道引脚
}
void do_Left_Encoder()
{
  LeftEncoderSet = digitalRead(Left_Encoder_CB);
  CPRL -= LeftEncoderSet ? -1 : +1;//逻辑语句
}
void do_Right_Encoder()
{
   RightEncoderSet = digitalRead(Right_Encoder_CB);
   CPRR -= RightEncoderSet ? -1 : +1;
}
void Update_Encoders()
{
  Serial.print("e");
  Serial.print("/t");
  Serial.print(CPRL);
  Serial.print("/t");
  Serial.print(CPRR);
  Serial.print("/n");
}
