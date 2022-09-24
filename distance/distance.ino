#define echo 12
#define trig 13   
#define buzzer 11
void setup() 
{ 
  pinMode(echo, OUTPUT);
  pinMode(trig, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int duration, cm, i;
  digitalWrite(buzzer,LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(echo, HIGH);
  delayMicroseconds(5);
  digitalWrite(echo, LOW);
  duration = pulseIn(trig, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();
  delay(100);
  /*if(cm>=21)
  {
    for(i=0;i<5;i++)
    {
      tone(buzzer,600,500);
      delay(1000);
    }
    delay(5000);
  }*/
}
int microsecondsToCentimeters(int microseconds)
{
  // ความเร็วเสียงเดินทางในอากาศคือ 340 เมตร/วินาที หรือ 29 ไมโครวินาที ต่อเซนติเมตร
  // วัตถุอยู่มีระยะทางเท่ากับครึ่งหนึ่งของเวลาที่จับได้
  return microseconds / 29 / 2;
}
