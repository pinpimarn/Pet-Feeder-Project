#define MotorPin0 A0 
#define MotorPin1 A1 
#define MotorPin2 2
#define MotorPin3 3
#define ENB 10
#define ENA 9
void setup() {
 pinMode(MotorPin0, OUTPUT);
 pinMode(MotorPin1, OUTPUT);
 pinMode(MotorPin2, OUTPUT);
 pinMode(MotorPin3, OUTPUT);
 Serial.begin(9600);
}
int i;
void loop() 
{
char x;
if(Serial.available()>0)
{
  x = Serial.read();
  if(x=='1')
 {
  for(i=0;i<3;i++)
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
  delay(1825);
  digitalWrite(MotorPin0, LOW);
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, LOW);
  delay(500);
  }
 }
  else
  {
    digitalWrite(MotorPin0, LOW);
    digitalWrite(MotorPin1, LOW);
    digitalWrite(MotorPin2, LOW);
    digitalWrite(MotorPin3, LOW);
  }
}
}


    
