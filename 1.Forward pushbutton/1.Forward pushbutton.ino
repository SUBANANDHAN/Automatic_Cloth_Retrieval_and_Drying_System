#define STEPPER_PIN_1 4
#define STEPPER_PIN_2 5
#define STEPPER_PIN_3 6
#define STEPPER_PIN_4 7
#define STEPPER_PIN_5 8
#define STEPPER_PIN_6 9
#define STEPPER_PIN_7 10
#define STEPPER_PIN_8 11
int step_number=0;
int count1=0;
int count2=0;
void MotorOff();
void Motor1(int dir);
const int fbuttonPin = 12;
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
  pinMode(fbuttonPin, INPUT_PULLUP);
}

void loop() {
  int fwddval = digitalRead(fbuttonPin);
  Motor1(fwddval);
  /*Serial.print("count1:");*/
  Serial.println(count1);
}

void Motor1(int dir) {
  if (dir == 1) {
    switch (step_number) {
      case 0:
        digitalWrite(STEPPER_PIN_1, HIGH);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        digitalWrite(STEPPER_PIN_5, HIGH);
        digitalWrite(STEPPER_PIN_6, LOW);
        digitalWrite(STEPPER_PIN_7, LOW);
        digitalWrite(STEPPER_PIN_8, LOW);
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        digitalWrite(STEPPER_PIN_5, LOW);
        digitalWrite(STEPPER_PIN_6, HIGH);
        digitalWrite(STEPPER_PIN_7, LOW);
        digitalWrite(STEPPER_PIN_8, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        digitalWrite(STEPPER_PIN_5, LOW);
        digitalWrite(STEPPER_PIN_6, LOW);
        digitalWrite(STEPPER_PIN_7, HIGH);
        digitalWrite(STEPPER_PIN_8, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);
        digitalWrite(STEPPER_PIN_5, LOW);
        digitalWrite(STEPPER_PIN_6, LOW);
        digitalWrite(STEPPER_PIN_7, LOW);
        digitalWrite(STEPPER_PIN_8, HIGH);
        break;
    }
    count1++;
  } else if (dir == 0) {
    MotorOff();
  }
  step_number++;
  if (step_number > 3) {
    step_number = 0;
  }
  if(count1>14000){
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
