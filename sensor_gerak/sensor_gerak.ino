const int trigPin = 12;
const int echoPin = 11;
const int buzzerPin = 2;
const int ledPin = 4;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  if(distance <= 10 && distance > 5) {
    delay(500);
    tone(buzzerPin,340);
    digitalWrite(ledPin, HIGH);
    delay(500);
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
  } else if( distance <= 5) {
    tone(buzzerPin,440);
    digitalWrite(ledPin, HIGH);
  } else {
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
  }
}