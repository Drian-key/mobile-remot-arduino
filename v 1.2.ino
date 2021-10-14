//, . ;
//@key_chans 

#include <Arduino.h>

#define IN1 2 //kanan depan
#define IN2 3 //kanan depan
#define IN3 4 //kiri depan
#define IN4 5 //kiri depan
#define IN11 6 //belakang kiri
#define IN21 7 //belakang kiri
#define IN31 8 //belakang kanan
#define IN41 9 //belakang kanan


#define PWMKAD 3
#define PWMKID 5
#define PWMKIB 6
#define PWMKAB 10

const int IN_A0 = A3; // analog input 1
const int IN_D0 = 11; // digital input 2 kiri
const int IN_A01 = A4; // analog input 1
const int IN_D02 = 12; // digital input 2 kanan

int value_A0;
bool value_D0;
int value_A01;
bool value_D02;

void maju(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(IN11, HIGH);
    digitalWrite(IN21, LOW);
    digitalWrite(IN31, HIGH);
    digitalWrite(IN41, LOW);
    analogWrite(PWMKAD, 150);
    analogWrite(PWMKID, 150);
    analogWrite(PWMKIB, 150);
    analogWrite(PWMKAB, 150);
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
    analogWrite(PWMKAD, 150);
    analogWrite(PWMKID, 150);
    analogWrite(PWMKIB, 150);
    analogWrite(PWMKAB, 150);
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
    analogWrite(PWMKAD, 150);
    analogWrite(PWMKID, 150);
    analogWrite(PWMKIB, 150);
    analogWrite(PWMKAB, 150);
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
    analogWrite(PWMKAD, 150);
    analogWrite(PWMKID, 150);
    analogWrite(PWMKIB, 150);
    analogWrite(PWMKAB, 150);
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

    pinMode(PWMKAD, OUTPUT);
    pinMode(PWMKID, OUTPUT);
    pinMode(PWMKIB, OUTPUT);
    pinMode(PWMKAB, OUTPUT);
    
    pinMode(IN_A0, INPUT);
    pinMode(IN_D0, INPUT);
    pinMode(IN_A01, INPUT);
    pinMode(IN_D02, INPUT);
}
//------------//
void loop() {
    value_A0 = analogRead(IN_A0); // reads the analog input from the IR distance sensor
    value_D0 = digitalRead(IN_D0);// reads the digital input from the IR distance sensor
    value_A01 = analogRead(IN_A01); // reads the analog input from the IR distance sensor
    value_D02 = digitalRead(IN_D02);// reads the digital input from the IR distance sensor

    Serial.print(" Analogue = "); 
    Serial.print(value_A0);
    Serial.print("\t Digital ="); 
    Serial.println(value_D0);
    Serial.print(" Analogue 2 = "); 
    Serial.print(value_A01);
    Serial.print("\t Digital 2 ="); 
    Serial.println(value_D02);

    if(value_D0 == 0 && value_D02 == 0) {maju();}
    else if((value_D0 == 1) && (value_D02 == 0)) {kiri();}
    else if((value_D0 == 0) && (value_D02 == 1)) {kanan();}
    else if((value_D0 == 0) && (value_D02 == 0)) {berhenti();}
}
