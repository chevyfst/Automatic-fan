#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//i2c pins
LiquidCrystal_I2C lcd(0x27, 16, 2);
int temp = A0; // the output pin of TMP36
int tempin=23;
int cel;
int relay = 7;
void setup() {
  lcd.begin(16,2);
lcd.backlight();//Power on the back light
//lcd.backlight(); Power off the back light

  pinMode(temp, INPUT);
  pinMode(relay, OUTPUT);

}

void loop() {
  temp = analogRead(temp);
  cel = temp * 0.48828125/20;
  Serial.print(cel);
  Serial.println();
  
  if (cel > tempin) {
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.print(cel); // display the temperature
    lcd.print("C ");
    lcd.setCursor(0, 1);// move cursor to next line
    lcd.print("Fan STATUS:");
    lcd.print("ON"); // display the temperature
    digitalWrite(relay, HIGH);
    delay(3000);
  }



  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.print(cel); // display the temperature
    lcd.print("C ");
    lcd.setCursor(0, 1);// move cursor to next line
    lcd.print("Fan STATUS:");
    lcd.print("OFF"); // display the temperature
    digitalWrite(relay, LOW);
    delay(3000);
  }


}
