String voice;
#define IN1 2 //kanan depan
#define IN2 3 //kanan depan
#define IN3 4 //kiri depan
#define IN4 5 //kiri depan
#define IN11 6 //belakang kiri
#define IN21 7 //belakang kiri
#define IN31 8 //belakang kanan
#define IN41 9 //belakang kanan


void maju(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(IN11, HIGH);
    digitalWrite(IN21, LOW);
    digitalWrite(IN31, HIGH);
    digitalWrite(IN41, LOW);
}
void mundur(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN11, LOW);
    digitalWrite(IN21, HIGH);
    digitalWrite(IN31, LOW);
    digitalWrite(IN41, HIGH);
}
void kanan(){
    digitalWrite(IN1, HIGH);
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
    digitalWrite(IN11, HIGH);
     digitalWrite(IN21, LOW);
     digitalWrite(IN31, HIGH);
     digitalWrite(IN41, HIGH);
}
void kiri(){
    digitalWrite(IN1, HIGH);
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, HIGH);
    digitalWrite(IN11, HIGH);
     digitalWrite(IN21, HIGH);
     digitalWrite(IN31, HIGH);
     digitalWrite(IN41, LOW);
}
void berhenti(){
  digitalWrite(IN1, LOW);
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
  digitalWrite(IN11, LOW);
     digitalWrite(IN21, LOW);
     digitalWrite(IN31, LOW);
     digitalWrite(IN41, LOW);
}
//------------//
void setup() {
Serial.begin(9600);
pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
pinMode(IN11, OUTPUT);
  pinMode(IN21, OUTPUT);
  pinMode(IN31, OUTPUT);
  pinMode(IN41, OUTPUT);
}
//------------//
void loop() {
while (Serial.available()){  //serial monitor check
delay(10); //10mS
char c = Serial.read();
if (c == '#') {break;} //Keluar dari looping while saat ada karakter #
voice += c; //
}
if (voice.length() > 0) {
//Serial.println(voice);
//-----------------------------------------------------------------------//

if(voice == "maju") {maju();}  //memanggil fungsi hidup semua
else if(voice == "mundur"){mundur();} //memanggil fungsi mati semua
else if(voice == "kanan"){kanan();} //memanggil fungsi mati semua

else if(voice == "kiri"){kiri();} //memanggil fungsi mati semua
else if(voice == "berhenti"){berhenti();} //memanggil fungsi mati semua
////----------matikan setiap led dengan perintah----------//
//else if(voice == "true 1") {digitalWrite(led1, HIGH);}
//else if(voice == "true 2") {digitalWrite(led2, HIGH);}
//else if(voice == "true 3") {digitalWrite(led3, HIGH);}
//else if(voice == "true 4") {digitalWrite(led4, HIGH);}
////----------Matikan led dengan perintah----------//
//else if(voice == "false 1") {digitalWrite(led1, LOW);}
//else if(voice == "false 2") {digitalWrite(led2, LOW);}
//else if(voice == "false 3") {digitalWrite(led3, LOW);}
//else if(voice == "false 4") {digitalWrite(led4, LOW);}
//-----------------------------------------------------------------------//
voice="";}}

//Alpha_robotik
