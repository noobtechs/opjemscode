#include <Wire.h>
#include <SparkFunMLX90614.h>

IRTherm therm;
#define relayPin 12 
#define buzzerPin 13 
#define obstaclePin 8
float targetTemp;
int hasObstacle = HIGH;
float predefinedTemp = 37.40;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(obstaclePin, INPUT);
  therm.begin(); 
  therm.setUnit(TEMP_C);  
}

void loop() {
  therm.sleep();
  hasObstacle = digitalRead(obstaclePin);
  if (hasObstacle == HIGH)
  {  
    therm.wake();
    targetTemp = therm.object();
    if (targetTemp <= predefinedTemp)
    { 
       digitalWrite(relayPin, HIGH);
       delay(6000);       
    }
    else
    {
      digitalWrite(buzzerPin, HIGH); 
      delay(3000);
    }
  }
}
