// https://www.youtube.com/watch?v=1Qndq5OV_XE
#include <DHT.h> // library DHT11
#include <LiquidCrystal_I2C.h> //library LCD
LiquidCrystal_I2C lcd (0x23, 16, 2 ); // inisialisai pin i2c lcd, lcd yg digunakan 16 koloam 2 baris
DHT dht(4, DHT11); // pin, tipe DHT
#define MistMaker 3 // pin mist maker 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Serial komunikasi yang digunakan 
  pinMode(MistMaker,OUTPUT);// inisialisasi pin mistmaker sebagai output
  digitalWrite(MistMaker,HIGH);
  lcd.begin();
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  byte kelembaban = dht.readHumidity(); // data yang akan dideteksi oleh sensor DHT11

  Serial.print("kelembaban: ");
  Serial.println(kelembaban);
  Serial.print(" ");

  lcd.setCursor (0,0);
  lcd.print("kelembaban : ");
  lcd.print(kelembaban);
  lcd.print((char)223);
  lcd.print("RH");

  if (kelembaban >= 70)
  digitalWrite(MistMaker,HIGH);

  else if (kelembaban <= 80)
  digitalWrite(MistMaker,LOW);
  
}
