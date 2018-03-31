#include <homephone.h>

const int analogIn = A5;

#define SDA (12)
#define RST (9)
#define SCK (13)
#define CS (11)
#define A0 (10)

homephone lcd (SDA, SCK, A0, RST, CS);

int RawValue = 0;
float Voltage = 0;

void setup() {
  pinMode(analogIn, INPUT);
  lcd.begin();
  lcd.setContrast(0x10);
  lcd.clearDisplay();
}

void loop() {
  RawValue = analogRead(analogIn);
  Voltage = (RawValue * 5.0 ) / 1024.0; // scale the ADC
  lcd.setTextColor(black, white);
  lcd.setCursor(0, 15);
  lcd.print("Raw = ");
  lcd.print(RawValue);
  lcd.println("        ");
  lcd.print("Vol = ");
  lcd.print(Voltage, 5);
  lcd.println("        ");

  lcd.display();
  delay(200);   // 1/2 sec so your display doesnt't scroll too fast
}
