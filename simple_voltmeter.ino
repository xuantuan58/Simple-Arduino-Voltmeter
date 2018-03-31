const int analogIn = A5;

int RawValue = 0;
float Voltage = 0;

void setup() {
  pinMode(analogIn, INPUT);
  Serial.begin(9600);
}

void loop() {
  RawValue = analogRead(analogIn);
  Voltage = (RawValue * 5.0 ) / 1024.0; // scale the ADC
  Serial.print("Raw Value = " );  // shows pre-scaled value
  Serial.print(RawValue);
  Serial.print("\t Voltage = "); // shows the voltage measured
  Serial.println(Voltage, 5); //3 digits after decimal point
  delay(500);   // 1/2 sec so your display doesnt't scroll too fast
}
