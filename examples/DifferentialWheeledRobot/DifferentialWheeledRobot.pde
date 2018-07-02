#include <DifferentialWheeledRobot.h>


#define MAX_SPEED 9.42477796076938
#define POWER_MIN 0
#define POWER_MAX 1023
#define PIN_POWER_LEFT 4
#define PIN_DIRECTION_LEFT 2
#define PIN_ENCODER_LEFT 12
#define PIN_POWER_RIGHT 5
#define PIN_DIRECTION_RIGHT 0
#define ROBOT_WHEEL_SEPARATION 0.135
#define ROBOT_WHEEL_RADIOUS 0.0325

Wheel wheelLeft(MAX_SPEED);
Wheel wheelRight(MAX_SPEED);
DifferentialWheeledRobot robot(ROBOT_WHEEL_SEPARATION,ROBOT_WHEEL_RADIOUS);

void setup() {
  //Setup Serial line.
  Serial.begin(115200);
  wheelLeft.attachPower(PIN_POWER_LEFT,POWER_MIN,POWER_MAX);
  wheelLeft.attachDirection(PIN_DIRECTION_LEFT);
	robot.attachLeftWheel(wheelLeft);
  wheelRight.attachPower(PIN_POWER_RIGHT,POWER_MIN,POWER_MAX);
  wheelRight.attachDirection(PIN_DIRECTION_RIGHT);
	robot.attachRightWheel(wheelRight);
}

void loop() {
  robot.move(0.25,0);
  delay(2500);
  robot.move(-0.25,0);
  delay(2500);
}
