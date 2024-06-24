#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10 
#define RST_PIN 9
#define Buzzer 2
#define led1 7
#define led2 8

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  Serial.println("Please Input Card..");
  SPI.begin();
  rfid.PCD_Init();
  pinMode(Buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if(! rfid.PICC_IsNewCardPresent() || ! rfid.PICC_ReadCardSerial()) return;

  Serial.print("NUID tag is :");
  digitalWrite(led1, HIGH);
  tone(Buzzer, 700);
  delay(200);
  digitalWrite(led1, LOW);
  noTone(Buzzer);
  String ID = "";

  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
    ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    ID.concat(String(rfid.uid.uidByte[i], HEX));
    delay(300);
  }

  Serial.println();
  ID.toUpperCase();

  if(ID.substring(1) == "89 45 FE 17") {
    delay(300);
    digitalWrite(led1, HIGH);
    tone(Buzzer, 440);
    Serial.println("Benar.");
    delay(300);
    digitalWrite(led1, LOW);
    noTone(Buzzer);
    delay(300);
  } else {
    delay(300);
    digitalWrite(led2, HIGH);
    tone(Buzzer, 240);
    Serial.println("Salah!");
    delay(300);
    digitalWrite(led2, LOW);
    noTone(Buzzer);
    delay(300);
  }
}
