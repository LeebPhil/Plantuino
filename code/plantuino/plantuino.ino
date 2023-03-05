#include <LiquidCrystal.h> 
 int Contrast = 0;
 int sensorVal = 0;
 int oldSensorVal = -1;
 String sensorDis = "Sensor in %: ";
 String sensorValString = "Sensor-Wert: ";
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 int dry = 587;
 int wet = 303;
 int percentage = 0;
 int oldPercentage = -1;

  void setup()
  {
    Serial.begin(9600);
    analogWrite(6,Contrast);
    lcd.begin(16, 2);
  } 
  
  void printSensorValue(int sensorVal)
  {
    lcd.setCursor(0, 0);
    lcd.print(sensorValString + sensorVal);
  }

  void printSensorPercentage(int percentage)
  {
    lcd.setCursor(0, 1);
    lcd.print(sensorDis + percentage);
  }

  void loop()
  { 
    sensorVal = analogRead(0); 
    if (oldSensorVal != sensorVal) {
      lcd.clear();
      oldSensorVal = sensorVal;
      printSensorValue(sensorVal);
      percentage = map(sensorVal, dry, wet, 0, 100);
      oldPercentage = percentage;
      printSensorPercentage(percentage);
    }
    delay(1000);
  }

  