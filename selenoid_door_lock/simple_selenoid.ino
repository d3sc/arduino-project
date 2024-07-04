int selenoid=4;

void setup() {
  Serial.begin(9600);
  // relay off
  pinMode(selenoid, OUTPUT);
  digitalWrite(selenoid, HIGH);
}

void loop() {
  delay(3000)
  digitalWrite(selenoid, LOW);
  delay(3000)
  digitalWrite(selenoid, HIGH);
}
