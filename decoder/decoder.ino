#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int ascii = 0;
int i =0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void decode(int code) {
  if(code == 28) {
    Serial.write(31);
  }
  else {
    Serial.write(code+63);
    lcd.setCursor(i,0);
    lcd.print(char(code+63));
  }
  ascii = 0;
  i++;
}

void loop() {
  int light = analogRead(A0);
  
  if(light>900) {
    ascii++;
    delay(15);
  }
  else {  
    if(ascii>0) {
      decode(ascii);
    }
  }
}
