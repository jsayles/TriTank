#include <AFMotor.h>

#define MOTOR1       1
#define MOTOR2       2
#define BUTTON_PIN  13

AF_DCMotor motor1(MOTOR1);
AF_DCMotor motor2(MOTOR2);


void forward(int time_ms) {
  Serial.print("forward(");
  Serial.print(time_ms);
  Serial.println(")");
  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(time_ms);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void backward(int time_ms) {
  Serial.print("backward(");
  Serial.print(time_ms);
  Serial.println(")");
  
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  delay(time_ms);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void left(int time_ms) {
  Serial.print("left(");
  Serial.print(time_ms);
  Serial.println(")");
    
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(time_ms);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void right(int time_ms) {
  Serial.print("right(");
  Serial.print(time_ms);
  Serial.println(")");
  
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(time_ms);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Motor test!");
  
  // Turn on motors
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

bool started = false;

void loop() {
  // Don't start until the button is pressed
  if(not started) {
    Serial.print("Waiting for button press to start.... ");
    while(digitalRead(BUTTON_PIN) == HIGH) {
      delay(400);
    }
    Serial.println("Starting!");
    started = true;
  }
  
  forward(3000);
  right(1000);
  forward(3000);
  left(1000);
}
