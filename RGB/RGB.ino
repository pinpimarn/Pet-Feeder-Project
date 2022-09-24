#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define LED 13
int frequency = 0;
void setup() {
 pinMode(S0, OUTPUT);
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);
 pinMode(sensorOut, INPUT);
 pinMode(LED, OUTPUT);
 // Setting frequency-scaling to 100%
 digitalWrite(S0,HIGH);
 digitalWrite(S1,HIGH);
 Serial.begin(9600);
}
void loop() {
 // Setting red filtered photodiodes to be read
 int red,green,blue;
 char light;
 digitalWrite(S2,LOW);
 digitalWrite(S3,LOW);
 // Reading the output frequency
 frequency = pulseIn(sensorOut, LOW);
 red = frequency;
 // Printing the value on the serial monitor
 Serial.print("R= ");//printing name
 Serial.print(red);//printing RED color frequency
 Serial.print("  ");
 delay(100);
 // Setting Green filtered photodiodes to be read
 digitalWrite(S2,HIGH);
 digitalWrite(S3,HIGH);
 // Reading the output frequency
 frequency = pulseIn(sensorOut, LOW);
 green = frequency;
 // Printing the value on the serial monitor
 Serial.print("G= ");//printing name
 Serial.print(green);//printing RED color frequency
 Serial.print("  ");
 delay(100);
 // Setting Blue filtered photodiodes to be read
 digitalWrite(S2,LOW);
 digitalWrite(S3,HIGH);
 // Reading the output frequency
 frequency = pulseIn(sensorOut, LOW);
 blue = frequency;
 // Printing the value on the serial monitor
 Serial.print("B= ");//printing name
 Serial.print(blue);//printing RED color frequency
 Serial.println("  ");
 delay(100);
 if((red>=85&&red<=120)&&(green>=140&&green<=190)&&(blue>=39&&blue<=60))
  Serial.println("RED");
 if((red>=80&&red<=120)&&(green>=65&&green<=100)&&(blue>=25&&blue<=40))
  Serial.println("BLUE");
 if((red>=120&&red<=150)&&(green>=130&&green<=160)&&(blue>=50&&blue<=70))
  Serial.println("GREEN");
 if (Serial.available()>0)
 {
  light = Serial.read();
  if(light=='1')
    {
      Serial.println("LED ON");
      digitalWrite(LED,HIGH);
    }
  if(light=='0')
    {
      Serial.println("LED OFF");
      digitalWrite(LED,LOW); 
    }
 }
}
