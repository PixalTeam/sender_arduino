#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

#include <Wire.h>
#include "rgb_lcd.h" 

rgb_lcd lcd;

int colorR = 255;
int colorG = 0;
int colorB = 0;
  
String reponse;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);

  Wire.begin();

  dht.begin();

  lcd.setCursor(3, 0);
  lcd.print("Gumbraise.");
}

void loop() {
  if (Serial.available() > 0) {
    reponse = Serial.readString();
    
    if(reponse.substring(0,1)=="T")
    {
      Temp();
    }
    if(reponse.substring(0,1)=="H")
    {
      Hum();
    }
  }
}

void Temp() {
  float t = dht.readTemperature();
  Serial.println(t);

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("Temp.(*C):");
  lcd.setCursor(11, 1);
  lcd.print(t);
}
void Hum() {
  float h = dht.readHumidity();
  Serial.println(h);
  
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("Hum.(%):");
  lcd.setCursor(11, 1);
  lcd.print(h);
}
