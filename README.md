# bme280-lcd20x4
#include <Wire.h>
<br>
#include <LiquidCrystal_I2C.h>
<br>
#include <Adafruit_Sensor.h>
<br>
#include <Adafruit_BME280.h>
<br>

#define SEALEVELPRESSURE_HPA (1013.25)
<br>
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
<br>
Adafruit_BME280 bme;
<br>
LiquidCrystal_I2C lcd(0x27, 20,4);
<br>
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
<br>
void loop() {
  Serial.print("Temperatura = ");
  Serial.print(bme.readTemperature());
  Serial.println("*C");
  <br>
  Serial.print("Humedad = ");
  Serial.print(bme.readHumidity());
  Serial.println("%");
  <br>
  Serial.print("Presion = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println("hPa");
  <br>
  Serial.print("Altitud = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println("m");
  <br>

  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.print(bme.readTemperature());
  lcd.write(1);
  lcd.print("C");
  <br>

  lcd.setCursor(0, 1);
  lcd.print("Humedad: ");
  lcd.print(bme.readHumidity());
  lcd.print("%");
  <br>
  
  lcd.setCursor(0, 2);
  lcd.print("Presion: ");
  lcd.print(bme.readPressure() / 100.0F);
  lcd.print("hPa");
   <br>

  lcd.setCursor(0, 3);
  lcd.print("Altitud: ");
  lcd.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  lcd.print("m");
    <br>

  Serial.println();
  delay(1000);
  lcd.clear();
}
