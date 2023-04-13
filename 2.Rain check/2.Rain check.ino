#define STEPPER_PIN_1 4
#define STEPPER_PIN_2 5
#define STEPPER_PIN_3 6
#define STEPPER_PIN_4 7
#define STEPPER_PIN_5 8
#define STEPPER_PIN_6 9
#define STEPPER_PIN_7 10
#define STEPPER_PIN_8 11
int stepnum=0;
void MotorOff();
void Onestep(int z);
int count3=0;
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
  bool rain = digitalRead(A0);
  Onestep(rain);
  Serial.println(rain);
}

void Onestep(int z) {
  if(z==1){
    MotorOff();
  }
  else if (z == 0) {
    switch (stepnum) {
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
    count3++;
  }
  stepnum++;
  if (stepnum > 3) {
    stepnum = 0;
  }
  if(count3>5000){
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
