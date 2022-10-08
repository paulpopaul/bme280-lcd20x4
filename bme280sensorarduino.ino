#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

byte degree[8] = 
{
  0b00011,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

Adafruit_BME280 bme;

LiquidCrystal_I2C lcd(0x27, 20,4);

void setup() {
  Serial.begin(9600);
  if (!bme.begin(0x76)) {
    Serial.println("No se pudo encontrar un sensor BME280 válido, verifique el cableado!");
    while (1);
  }
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.createChar(1, degree);
}
 
void loop() {
  Serial.print("Temperatura = ");
  Serial.print(bme.readTemperature());
  Serial.println("*C");
 
  Serial.print("Humedad = ");
  Serial.print(bme.readHumidity());
  Serial.println("%");
 
  Serial.print("Presion = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println("hPa");
 
  Serial.print("Altitud = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println("m");

  
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.print(bme.readTemperature());
  lcd.write(1);
  lcd.print("C");
 
  lcd.setCursor(0, 1);
  lcd.print("Humedad: ");
  lcd.print(bme.readHumidity());
  lcd.print("%");
 
  lcd.setCursor(0, 2);
  lcd.print("Presion: ");
  lcd.print(bme.readPressure() / 100.0F);
  lcd.print("hPa");
 
  lcd.setCursor(0, 3);
  lcd.print("Altitud: ");
  lcd.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  lcd.print("m");
  
  Serial.println();
  delay(1000);
  lcd.clear();
}
