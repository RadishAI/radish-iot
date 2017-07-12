#include <Ethernet.h>

EthernetClient client;

byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x01 }; // RESERVED MAC ADDRESS

const int sensorPin= A0;
const float baseLineTemp = 20.0;
long previousMillis = 0;
unsigned long currentMillis = 0;
long interval = 250000; // READING INTERVAL
String data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP"); 
  }
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
digitalWrite(4,HIGH);
else
digitalWrite(4,LOW);


  currentMillis = millis();
  if(currentMillis - previousMillis > interval) { // READ ONLY ONCE PER INTERVAL
    previousMillis = currentMillis;
  }

  data = "temp1=" + String((int)temperature) + String("&hum1=0");
Serial.println(data);
  if (client.connect("www.radishai.com",80)) { // REPLACE WITH YOUR SERVER ADDRESS
    client.println("POST /add.php HTTP/1.1"); 
    client.println("Host: www.radishai.com"); // SERVER ADDRESS HERE TOO
    client.println("Content-Type: application/x-www-form-urlencoded"); 
    client.print("Content-Length: "); 
    client.println(data.length()); 
    client.println(); 
    client.print(data); 
  } 

  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }

  delay(60000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN

  
}
