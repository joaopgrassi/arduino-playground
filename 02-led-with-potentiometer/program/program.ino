
// Pins set up
int potPin = A0;
int redLedPin = 5;

// holds the value read from the potentiometer
int potReadValue;

// value from 0 - 5
float arduinoVoltage;

// value from 0 - 255
float ledVoltage = 0;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {

  potReadValue = analogRead(potPin);
  Serial.print("The value read from the Potentiometer is: ");
  Serial.println(potReadValue);  

  delay(250);

  arduinoVoltage = calculateArduinoVoltageFromPotentiometer(potReadValue);
  Serial.print("The value read from the Potentiometer in 'Arduino Voltage' is: ");
  Serial.println(arduinoVoltage);

  ledVoltage = calculateLedVoltageFromPotentiometer(potReadValue);

  Serial.print("The value about to be set on the LED is: ");
  Serial.println(ledVoltage);

  analogWrite(redLedPin, ledVoltage);  
}

float calculateArduinoVoltageFromPotentiometer(int value) {
  return ((float)5/1023) * value;
}

float calculateLedVoltageFromPotentiometer(int value) {
  return ((float)255/1023) * value;
}
