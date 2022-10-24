#define IR_SENSOR_RIGHT 11
#define IR_SENSOR_LEFT 12
#define MOTOR_SPEED 180



//Right motor
int enableRightMotor = 5;  //a
int rightMotorPin1 = 9;
int rightMotorPin2 = 10;



//Left motor
int enableLeftMotor = 6;  //b
int leftMotorPin1 = 7;
int leftMotorPin2 = 8;

void moveForward();
void moveLeft();
void moveRight();
void stop();
void followLine();

void setup() {

  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  stop();

  Serial.begin(9600);
}

void loop() {
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);
  // Serial.println(leftIRSensorValue);
  // Serial.println(rightIRSensorValue);
  // Serial.println("---------------");
  // delay(1000);
  followLine(rightIRSensorValue, leftIRSensorValue);
}

void followLine(int rightIRSensorValue, int leftIRSensorValue) {
  if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
    moveRight();
  } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
    moveLeft();
  } else if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
    moveForward();
  } else {
    stop();
  }
}


void moveForward() {
  setRightMotor(1, 0);
  setLeftMotor(1, 0);
}

void moveLeft() {
  setRightMotor(1, 0);
  setLeftMotor(0, 1);
}

void moveRight() {
  setRightMotor(0, 1);
  setLeftMotor(1, 0);
}

void stop() {
  setRightMotor(0, 0);
  setLeftMotor(0, 0);
}



void setRightMotor(int pin1, int pin2) {
  digitalWrite(rightMotorPin1, pin1);
  digitalWrite(rightMotorPin2, pin2);
  analogWrite(enableRightMotor, MOTOR_SPEED);
}

void setLeftMotor(int pin1, int pin2) {
  digitalWrite(leftMotorPin1, pin1);
  digitalWrite(leftMotorPin2, pin2);
  analogWrite(enableLeftMotor, MOTOR_SPEED);
}