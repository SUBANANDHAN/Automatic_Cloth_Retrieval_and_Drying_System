#define STEPPER_PIN_1 4
#define STEPPER_PIN_2 5
#define STEPPER_PIN_3 6
#define STEPPER_PIN_4 7
#define STEPPER_PIN_5 8
#define STEPPER_PIN_6 9
#define STEPPER_PIN_7 10
#define STEPPER_PIN_8 11
int stepnumb=0;
int count5=0;
void MotorOff();
void Temp(int temp);
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
  int adctemp = analogRead(A2);
  float voltage = adctemp * (5.0 / 1024.0);
  float temp = voltage * 100;
  Temp(temp);
  Serial.println(temp);
  /*Serial.println("count5:");
  Serial.print(count5);*/
}

void Temp(int temp) {
  if (temp <= 22) {
    switch (stepnumb) {
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
    count5++;
  } else if (temp >= 33) {
    MotorOff();
  }
  stepnumb++;
  if (stepnumb > 3) {
    stepnumb = 0;
  }
  if(count5>5000){
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
