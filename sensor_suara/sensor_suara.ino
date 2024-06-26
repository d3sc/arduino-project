#define suara A1
#define led1 2
float bacaSuara;
int total_suara = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(suara, INPUT);
  pinMode(led1, OUTPUT);
  Serial.println("mulai...");
}

void loop() {
  bacaSuara=analogRead(suara);
  bacaSuara = bacaSuara / 100;
  // Serial.println(bacaSuara);
  // int batas = 536;
  float batas = 5.40;

  if(bacaSuara >= batas) {
    delay(500);
    total_suara++;
    // Serial.println("lorem ipsum dolor sit amet suka makan bakso");
  }
  Serial.println(total_suara);

  if(total_suara % 2 == 0) {
    // Serial.println("lorem ipsum dolor sit amet suka makan bakso");
    digitalWrite(led1, LOW);
  } else {
    // Serial.println("lorem ipsum dolor sit amet suka makan bakso goreng pake tahu dan juga keju");
    digitalWrite(led1, HIGH);
  }
}