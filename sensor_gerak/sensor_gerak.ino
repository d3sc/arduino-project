const int trigPin = 12;
const int echoPin = 11;
const int buzzerPin = 2;

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
    tone(buzzerPin,340);
  } else if( distance <= 5) {
    tone(buzzerPin,440);
  } else {
    noTone(buzzerPin);
  }
}