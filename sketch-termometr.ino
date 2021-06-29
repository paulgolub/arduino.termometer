/*
VSS -> GND
VDD -> +5v
V0 -> al potenziometr
RS -> Arduino D2
R/W -> GND
E -> Arduino D3
D0 -> N/C
D1 -> N/C
D2 -> N/C
D3 -> N/C
D4 -> Arduino D4
D5 -> Arduino D5
D6 -> Arduino D6
D7 -> Arduino D57
A -> Arduino A0
K -> GND*/

#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>
#define DHTPIN 9
#define DHTTYPE DHT21
float hum;
float temp;
float te;
DHT dht(DHTPIN, DHTTYPE);
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
 
void setup() {
  
  Serial.begin(9600);
  dht.begin();
  pinMode(A0, OUTPUT);
  lcd.begin(16, 2); 
}
 
void loop() {
  digitalWrite(A0, HIGH);

  hum = dht.readHumidity();
  temp= dht.readTemperature();
  te=temp-0.4*(temp-10)*(1-(hum/100));

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%,  Temperature: ");
  Serial.print(temp);
  Serial.println(" Celsius");

  // cursore position (col, row)
  lcd.setCursor(0, 0);
  lcd.print("H:");
  lcd.print(hum);
  lcd.print("%");
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("Feeling T:");
  lcd.print(te);
  lcd.print("C");

  delay(10000);
}
