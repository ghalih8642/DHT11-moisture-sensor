#include<Wire.h>
#include <DHT.h> // library DHT11
#include <LiquidCrystal_I2C.h> //library LCD
LiquidCrystal_I2C lcd (0x27, 16, 2 ); // inisialisai pin i2c lcd, lcd yg digunakan 16 koloam 2 baris scl A5, sda A4
DHT dht(4, DHT11); // pin digital, tipe DHT
const int MistMaker = 7; // pin digital mist maker 
int outputvalue;
const int pompa = 2; // pin digital pompa 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);// Serial komunikasi yang digunakan
  pinMode(pompa,OUTPUT);// inisialisasi pin pompa sebagai output
  pinMode(MistMaker,OUTPUT);// inisialisasi pin mistmaker sebagai output
  //digitalWrite(MistMaker,HIGH);
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.print("hay bos");
  lcd.setCursor(4,0);
  delay(1000);
  lcd.clear();
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  outputvalue = analogRead(A0);// inisialisasi data yg akan dideteksi oleh moisture sensor

  float value = map(outputvalue,1023,0,0,100); // mapping nilai sensor kelembaban tanah
  Serial.print("kelembaban tanah: ");
  Serial.println(value); // insialisasi cetak data diserial monitor;
  Serial.print(" ");

  lcd.setCursor (0,1); // tampilan sensor kelembaban tanah ke LCD
  lcd.print("tanah: ");
  lcd.print(value);

  
  if (value <= 3) // jika kelembapan lebih dari sama dengan 350 maka pompa akan menyala 
  {digitalWrite(pompa,LOW);} //semakin basah nilainya semakin kecil
  else if (value > 4) // jika kelembapan kurang dari sama dengan 300 maka pompa akan mati
  {digitalWrite(pompa,HIGH);}
  delay(1000);

   byte kelembaban = dht.readHumidity();  // data yang akan dideteksi oleh sensor DHT11

  Serial.print("kelembaban udara: ");
  Serial.println(kelembaban);
  Serial.print(" ");

  lcd.setCursor (0,0); // tampilan sensor kelembaban udara ke LCD
  lcd.print("udara: ");
  lcd.print(kelembaban);
  lcd.print((char)223);
  lcd.print("RH");
   
  if (kelembaban > 75) //jika nilai kelem > 75 mistmaker nyala
  {digitalWrite(MistMaker,LOW);}

  else if (kelembaban <= 85) //jika nilai kelem < 85 mistmaker mati
  {digitalWrite(MistMaker,HIGH);}
  delay(800);
}
// kelembaban udara 80-90
//Kering : > 700
//Normal : > 350 dan < 700
//Lembab : < 350 kurang dari 300 becek
