// เซนเซอร์สี
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
// มอเตอร์
#define MotorPin0 A0 
#define MotorPin1 A1 
#define MotorPin2 2
#define MotorPin3 3
#define ENB 10
#define ENA 9
// เซนเซอร์วัดระยะทาง
#define echo 12
#define trig 13   
#define buzzer 11

int frequency;
void setup() {
 // เซนเซอร์สี
 Serial.begin(9600);
 pinMode(S0, OUTPUT);
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);
 pinMode(sensorOut, INPUT);
 // frequency scaling 100%
 digitalWrite(S0, HIGH);
 digitalWrite(S1, HIGH);
 // มอเตอร์
 pinMode(MotorPin0, OUTPUT);
 pinMode(MotorPin1, OUTPUT);
 pinMode(MotorPin2, OUTPUT);
 pinMode(MotorPin3, OUTPUT);

 // เซนเซอร์วัดระยะทาง
 pinMode(echo, OUTPUT);
 pinMode(trig, INPUT);
 pinMode(buzzer, OUTPUT);
}
int microsecondsToCentimeters(int microseconds)
{
  // ความเร็วเสียงเดินทางในอากาศคือ 340 เมตร/วินาที หรือ 29 ไมโครวินาที ต่อเซนติเมตร
  // วัตถุอยู่มีระยะทางเท่ากับครึ่งหนึ่งของเวลาที่จับได้
  return microseconds / 29 / 2;
} 
void loop() 
{
// เซนเซอร์สี
 // สีแดง
 int red,green,blue;
 int duration, cm, i;
 digitalWrite(S2,LOW);
 digitalWrite(S3,LOW);
 frequency = pulseIn(sensorOut, LOW);
 red = frequency;
 Serial.print("R= ");//printing name
 Serial.print(red);//printing RED color frequency
 Serial.print("  ");
 delay(100);
 // สีเขียว
 digitalWrite(S2,HIGH);
 digitalWrite(S3,HIGH);
 frequency = pulseIn(sensorOut, LOW);
 green = frequency;
 Serial.print("G= ");//printing name
 Serial.print(green);//printing GREEN color frequency
 Serial.print("  ");
 delay(100);
 // สีน้ำเงิน
 digitalWrite(S2,LOW);
 digitalWrite(S3,HIGH);
 frequency = pulseIn(sensorOut, LOW);
 blue = frequency;
 Serial.print("B= ");//printing name
 Serial.print(blue);//printing BLUE color frequency
 Serial.println("  ");
 delay(100);
 // เซนเซอร์วัดระยะทง
  digitalWrite(buzzer, LOW);
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
 // มอเตอร์
 if(cm>=25)
  {
    for(i=0;i<5;i++)
    {
      tone(buzzer,200,500);
      delay(1000);
    }
    delay(5000); // หน่วงเวลาให้ส่งเสียงอีกครั้งหนึ่ง
  } 
 else if((red>=85&&red<=140)&&(green>=140&&green<=170)&&(blue>=39&&blue<=60))
 {
  Serial.println("RED");
  for(int i=0;i<2;i++)
  {
  digitalWrite(MotorPin0, HIGH);
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, HIGH);
  digitalWrite(MotorPin3, LOW);
  analogWrite(ENB,255);
  analogWrite(ENA,255);
  delay(1840); //ระยะเวลาการทำงานของมอเตอร์
  digitalWrite(MotorPin0, LOW);
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, LOW);
  delay(500);
  digitalWrite(MotorPin0, LOW);
  digitalWrite(MotorPin1, HIGH);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, HIGH);
  analogWrite(ENB,255);
  analogWrite(ENA,255);
  delay(1825);//ระยะเวลาการทำงานของมอเตอร์
  digitalWrite(MotorPin0, LOW);
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, LOW);
  delay(500);
  } 
  digitalWrite(MotorPin0, LOW);
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, LOW);
  delay(5000); //ไม่ให้อาหารหลังจากที่ให้ไปแล้ว 2นาที
 }
}
