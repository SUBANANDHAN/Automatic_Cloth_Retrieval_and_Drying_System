#define STEPPER_PIN_1 4
#define STEPPER_PIN_2 5
#define STEPPER_PIN_3 6
#define STEPPER_PIN_4 7
#define STEPPER_PIN_5 8
#define STEPPER_PIN_6 9
#define STEPPER_PIN_7 10
#define STEPPER_PIN_8 11
int stepno=0;
int count4=0;
void MotorOff();
void ldr(int l);
void setup() {
  Serial.begin(9600);
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
  pinMode(STEPPER_PIN_5, OUTPUT);
  pinMode(STEPPER_PIN_6, OUTPUT);
  pinMode(STEPPER_PIN_7, OUTPUT);
  pinMode(STEPPER_PIN_8, OUTPUT);
}

void loop() {
  unsigned int LDR = analogRead(A1);
  ldr(LDR);
  Serial.println(LDR);
  /*Serial.println("count4:");*/
  Serial.println(count4);
}

void ldr(int l) {
  if (l >= 500) {
    switch (stepno) {
      case 0:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);
        digitalWrite(STEPPER_PIN_5, LOW);
        digitalWrite(STEPPER_PIN_6, LOW);
        digitalWrite(STEPPER_PIN_7, LOW);
        digitalWrite(STEPPER_PIN_8, HIGH);
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        digitalWrite(STEPPER_PIN_5, LOW);
        digitalWrite(STEPPER_PIN_6, LOW);
        digitalWrite(STEPPER_PIN_7, HIGH);
        digitalWrite(STEPPER_PIN_8, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        digitalWrite(STEPPER_PIN_5, LOW);
        digitalWrite(STEPPER_PIN_6, HIGH);
        digitalWrite(STEPPER_PIN_7, LOW);
        digitalWrite(STEPPER_PIN_8, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, HIGH);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        digitalWrite(STEPPER_PIN_5, HIGH);
        digitalWrite(STEPPER_PIN_6, LOW);
        digitalWrite(STEPPER_PIN_7, LOW);
        digitalWrite(STEPPER_PIN_8, LOW);
        break;
    }
    count4++;
  } else if (l <= 300) {
    MotorOff();
  }
  stepno++;
  if (stepno > 3) {
    stepno = 0;
  }
  if(count4>5000){
      MotorOff();    
  }
}

void MotorOff(){
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        digitalWrite(STEPPER_PIN_5, LOW);
        digitalWrite(STEPPER_PIN_6, LOW);
        digitalWrite(STEPPER_PIN_7, LOW);
        digitalWrite(STEPPER_PIN_8, LOW);
}
