

#include <TimeLib.h>
#include <Time.h>

int sensorPin = A0;
int sensorPin1 = A1;// select the input pin for LDR
int sensorValue = 0;// variable to store the value coming from the sensor
int sensorValue1 = 0;
int count = 0;
int sv = 0;
int sv1 = 0;
int tstamp = 0;
int tstamp1 = 0;
int countin = 0;
int countout = 0;

void setup() {
  Serial.begin(9600); //sets serial port for communication
  delay(1000);
  sensorValue = analogRead(sensorPin);
  sensorValue1 = analogRead(sensorPin1);
  sv = sensorValue - 150;
  sv1 = sensorValue1 - 150;
  delay(1000);
}
void loop() {

  sensorValue = analogRead(sensorPin);// read the value from the sensor1
  sensorValue1 = analogRead(sensorPin1);// read the value from sensor2



  if (sensorValue > 200)
  {
    tstamp = now();
    if (countout == 1 && ((tstamp1 - tstamp) < 5))
    {
      count--;
      countout = 0;
    }
    else
    {
      countin = 1;
    }

  }

  if (sensorValue1 > 200)
  {
    tstamp1 = now();
    if (countin == 1 && ((tstamp - tstamp1) < 5))
    {
      count++;
      countin = 0;
    }
    else
    {
      countout = 1;
    }

  }

  Serial.println(count);//prints the values coming from the sensor on the screen
  
  delay(1000);
}
