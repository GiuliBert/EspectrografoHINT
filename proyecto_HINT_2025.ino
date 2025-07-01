#include <Servo.h>

Servo miServo;
int velocidad = 500; // Más alto = más lento
const int servoPin = 7;


const int LEDPin = LED_BUILTIN;
const int LDRPin = A0;

const int potenciometroPin = A1;
int medir = 0;

int angulo;

void setup() {
  miServo.attach(servoPin);       // Pin de señal del servo
  Serial.begin(9600);      // Iniciar comunicación serial
  pinMode(LEDPin, OUTPUT);
  pinMode(LDRPin, INPUT);
  pinMode(potenciometroPin, INPUT);
  
}

void loop() {
   // Mover de 0 a 180 grados
   
  medir = analogRead(potenciometroPin);
  if(medir >= 500){
    
    //digitalWrite(LEDPin, LOW);
    for (angulo = 0; angulo <= 130; angulo++) {
      miServo.write(angulo);
      Serial.print("Ángulo actual: ");
      Serial.println(angulo);
      delay(velocidad);

      int input = analogRead(LDRPin);
      Serial.println(input);
    }
  }
  
  digitalWrite(LEDPin, LOW);
  delay(1000); // Pausa al llegar a 0
  
}