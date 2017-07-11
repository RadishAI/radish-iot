const int sensorPin= A0;
const float baseLineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

int sensorVal = analogRead(sensorPin);
Serial.print("sensorVal ");
Serial.println(sensorVal);
float voltage = (sensorVal/1024.0)*5.0;
float temperature = (voltage-0.5)*100;
Serial.print("Degrees C ");
Serial.println(temperature);
if(temperature>30.0)
digitalWrite(2,HIGH);
else
digitalWrite(2,LOW);

if(temperature<=30.0)
digitalWrite(5,HIGH);
else
digitalWrite(5,LOW);
delay(1000);
}
