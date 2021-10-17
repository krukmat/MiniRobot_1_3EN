 // Definition
 // Programacion de mano robotica. Integracion con Blynk
#include <ESP32Servo.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "3TV32jiY9AhezmEoP5aImV4NB0pChbMm";

const char* ssid = "MIWIFI_2G_2jJ5";
const char* pass = "xvFYmqRv";

Servo servo_4;
Servo servo_1;
Servo servo_2;
Servo servo_3;


// arrays
int SensVal[4]; // sensor value

void setup()
{
  Blynk.begin(auth, ssid, pass);
  pinMode(2, OUTPUT);  // sets the digital pin 13 as outtput
  pinMode(4, OUTPUT);  // sets the digital pin 13 as outtput
  pinMode(12, OUTPUT);  // sets the digital pin 13 as outtput
  pinMode(13, OUTPUT);  // sets the digital pin 13 as outtput


  
  servo_1.attach(4); //mano
  servo_2.attach(12); //muñeca
  servo_3.attach(13); //base
  servo_4.attach(2); //antebrazo
  
  Serial.begin(9600); // Baudrate have to be same on the IDE
  Serial.println("mini robot ready...");     
}

void loop() // here we go!
{
  Blynk.run();
}

BLYNK_WRITE(V1) //antebrazo
{
  SensVal[0] = param.asInt();
  servo_4.write(SensVal[0]); 
  delay(25);
}

BLYNK_WRITE(V2) //muñeca
{
  SensVal[1] = param.asInt();
  servo_2.write(SensVal[1]); 
  delay(25);
}

BLYNK_WRITE(V3) //mano
{
  SensVal[2] = param.asInt(); 
  servo_1.write(SensVal[2]); 
  delay(25);
}

BLYNK_WRITE(V4) //base
{
  SensVal[3] = param.asInt();
  servo_3.write(SensVal[3]); 
  delay(25);
}
