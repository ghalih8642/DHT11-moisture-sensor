
// https://duwiarsana.com/membuat-penyiram-tanaman-otomatis/
int pompa = 2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pompa,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int NilaiSensor = analogRead(A0); // inisialisasi pin moisture sensor di pin A0
  Serial.println(NilaiSensor);
  if (NilaiSensor >= 350)
  digitalWrite(pompa,HIGH);
  else if (NilaiSensor <= 300) 
  digitalWrite(pompa,LOW);
  delay(1000);
}
