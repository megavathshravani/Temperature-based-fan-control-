#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int tempPin = A1;
int fan = 11;
int ledPin = 0;
int temp;
int tempMin = 30;
int tempMax = 60;
int fanSpeed;
int fanLCD;

int readTemp() {
  int analogValue = analogRead(tempPin);
  float voltage = analogValue * 5.0 / 1023.0;
  float temperatureC = (voltage - 0.5) * 100.0;
  return (int)temperatureC;
}

void setup() {
  pinMode(fan, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(tempPin, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  temp = readTemp();
  Serial.print(temp);

  if (temp < tempMin) {
    fanSpeed = 0;
    analogWrite(fan, fanSpeed);
    fanLCD = 0;
    digitalWrite(fan, LOW);
  } else {
    fanSpeed = map(temp, tempMin, tempMax, 0, 255);
    fanSpeed = constrain(fanSpeed, 0, 255);
    analogWrite(fan, fanSpeed);
    fanLCD = fanSpeed / 2.55;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Fan: ");
  lcd.print(fanLCD);
  lcd.print(" %");

  delay(1000);
}