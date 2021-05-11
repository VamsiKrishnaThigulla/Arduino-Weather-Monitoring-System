#include <dht.h>
#include <LiquidCrystal.h> 

int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

dht DHT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int readData = DHT.read22(8);

  float t = DHT.temperature;
  float h = DHT.humidity;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature = ");
  lcd.print(t);
  lcd.print(" oC");
  lcd.setCursor(0,1);
  lcd.print("Relative Humidity = ");
  lcd.print(h);
  lcd.print("%");
 
  delay(2000);
}
