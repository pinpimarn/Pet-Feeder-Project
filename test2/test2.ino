void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void wait()
{
  delay(1000);    
  Serial.println("hi");
}
void loop() {
  // put your main code here, to run repeatedly:
  char x;
  
 if(Serial.available()>0)
  {
    x=Serial.read();
    if(x=='1')
  {
    wait();
  }
  }
}
