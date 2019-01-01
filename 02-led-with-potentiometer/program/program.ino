
// Pins set up
int potPin = A0;
int redLedPin = 5;

// holds the value read from the potentiometer
int potReadValue;

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

  ledVoltage = map(potReadValue, 0, 1023, 0, 255);
  Serial.print("The value about to be set on the LED is: ");
  Serial.println(ledVoltage);

  analogWrite(redLedPin, ledVoltage);  
}
