#include <DifferentialWheeledRobot.h>

#define MAX_SPEED 10.471975511965978
#define POWER_MIN 256
#define POWER_MAX 1023
#define PIN_POWER_LEFT 4
#define PIN_DIRECTION_LEFT 2
#define PIN_ENCODER_LEFT 12
#define PIN_POWER_RIGHT 5
#define PIN_DIRECTION_RIGHT 0
#define ROBOT_WHEEL_SEPARATION 0.135
#define ROBOT_WHEEL_RADIOUS 0.0325
#define PIN_SONAR_TRIGGER 16
#define PIN_SONAR_ECHO 15

Sonar * sonar = new Sonar();
Wheel * wheelLeft = new Wheel(MAX_SPEED);
Wheel * wheelRight = new Wheel(MAX_SPEED);
DifferentialWheeledRobot robot(ROBOT_WHEEL_SEPARATION,ROBOT_WHEEL_RADIOUS);

void setup() {
  //Setup Serial line.
  Serial.begin(115200);
  
  wheelLeft->attachPower(PIN_POWER_LEFT,POWER_MIN,POWER_MAX);
  wheelLeft->attachDirection(PIN_DIRECTION_LEFT);
  
  wheelRight->attachPower(PIN_POWER_RIGHT,POWER_MIN,POWER_MAX);
  wheelRight->attachDirection(PIN_DIRECTION_RIGHT);

  sonar->attachTrigger(PIN_SONAR_TRIGGER);
  sonar->attachEcho(PIN_SONAR_ECHO);

  robot.attachLeftWheel(wheelLeft);
  robot.attachRightWheel(wheelRight);
}

void loop() {
  robot.move(0.25,0);
  delay(2500);
  robot.move(-0.25,0);
  delay(2500);
}

