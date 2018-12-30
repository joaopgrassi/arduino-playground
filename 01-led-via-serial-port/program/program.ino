

int redLedPin = 5;
int yellowLedPin = 6;

int redBlinkQty;
int yellowBlinkQty;

int blinkingDelay = 250;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  redBlinkQty = readFromUserInput("Red");  
  for(int i = 0; i < redBlinkQty; i++) {
    writeDigitalAndDelay(redLedPin, blinkingDelay, HIGH);
    writeDigitalAndDelay(redLedPin, blinkingDelay, LOW);
  }

  yellowBlinkQty = readFromUserInput("Yellow");  
  for(int i = 0; i < yellowBlinkQty; i++) {
    writeDigitalAndDelay(yellowLedPin, blinkingDelay, HIGH);
    writeDigitalAndDelay(yellowLedPin, blinkingDelay, LOW);
  }
}

void writeDigitalAndDelay(int pinNum, int delayMilleseconds, int voltageValue) {
  digitalWrite(pinNum, voltageValue);
  delay(delayMilleseconds);
}

int readFromUserInput(String LedUserFriendlyName) {
  Serial.print("Enter how many times you want to blink the ");
  Serial.print(LedUserFriendlyName);
  Serial.println(" LED");

  // wait for user input - need "No line ending" on Serial Monitor to prevent buffer left-over data
  while(Serial.available() == 0) { }
  return Serial.parseInt();
}
