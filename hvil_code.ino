
int ledPin = 2;
int s0Pin = 3;
int s1Pin = 4;
int s2Pin = 5;
int HVILPin = A2;

int volt = 0;



float nodeChecker() {
  int volt = analogRead(HVILPin);

  if (volt > 995 && volt <= 1023) {
    return 0;
  }
  if (volt > 837 && volt < 995) {
    return 1;
  }
  if (volt > 746 && volt < 837) {
    return 2;
  }
  if (volt > 674 && volt < 746) {
    return 3;
  }
  if (volt > 614 && volt < 674) {
    return 4;
  }
  if (volt > 564 && volt < 614) {
    return 5;
  }
  if (volt > 522 && volt < 564) {
    return 6;
  }
  if (volt > 0 && volt < 522) {
    return 7;
  }
}

int confChecker() {
  if (digitalRead(s2Pin) == 0 && digitalRead(s1Pin) == 0 && digitalRead(s0Pin) == 0) {
    return 0;
  }
  if (digitalRead(s2Pin) == 0 && digitalRead(s1Pin) == 0 && digitalRead(s0Pin) == 1) {
    return 1;
  }
  if (digitalRead(s2Pin) == 0 && digitalRead(s1Pin) == 1 && digitalRead(s0Pin) == 0) {
    return 2;
  }
  if (digitalRead(s2Pin) == 0 && digitalRead(s1Pin) == 1 && digitalRead(s0Pin) == 1) {
    return 3;
  }
  if (digitalRead(s2Pin) == 1 && digitalRead(s1Pin) == 0 && digitalRead(s0Pin) == 0) {
    return 4;
  }
  if (digitalRead(s2Pin) == 1 && digitalRead(s1Pin) == 0 && digitalRead(s0Pin) == 1) {
    return 5;
  }
  if (digitalRead(s2Pin) == 1 && digitalRead(s1Pin) == 1 && digitalRead(s0Pin) == 0) {
    return 6;
  }
  if (digitalRead(s2Pin) == 1 && digitalRead(s1Pin) == 1 && digitalRead(s0Pin) == 1) {
    return 7;
  }

}

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(s0Pin, INPUT_PULLUP);
  pinMode(s1Pin, INPUT_PULLUP);
  pinMode(s2Pin, INPUT_PULLUP);
  pinMode(HVILPin, INPUT);

  Serial.begin(9600);

}

void loop() {
  if ( confChecker() == int(nodeChecker())) {
    digitalWrite(ledPin, HIGH);

  }
  else {
    digitalWrite(ledPin, LOW);

  }


}
