#include <DifferentialWheeledRobot.h>
#include <WheelEncoder.h>

#define MAX_SPEED 10.471975511965978
#define POWER_MIN 256
#define POWER_MAX 1023
#define PIN_POWER_LEFT 4
#define PIN_DIRECTION_LEFT 2
#define PIN_ENCODER_LEFT 12
#define PIN_POWER_RIGHT 5
#define PIN_DIRECTION_RIGHT 0
#define PIN_ENCODER_RIGHT 14

#define ENCODER_TICKS_PER_REVOLUTION 21

#define ROBOT_WHEEL_SEPARATION 0.135
#define ROBOT_WHEEL_RADIOUS 0.0325


//Encoders
Encoder * encoderLeft = new Encoder(ENCODER_TICKS_PER_REVOLUTION);
Encoder * encoderRight = new Encoder(ENCODER_TICKS_PER_REVOLUTION);
//Motors
WheelEncoder * wheelLeft = new WheelEncoder(MAX_SPEED);
WheelEncoder * wheelRight = new WheelEncoder(MAX_SPEED);
//Robot
DifferentialWheeledRobot robot(ROBOT_WHEEL_SEPARATION,ROBOT_WHEEL_RADIOUS);

void setup() {
  //Setup Serial line.
  Serial.begin(115200);
	//Attach Wheel Left
  wheelLeft->attachPower(PIN_POWER_LEFT,POWER_MIN,POWER_MAX);
  wheelLeft->attachDirection(PIN_DIRECTION_LEFT);
	encoderLeft->attach(PIN_ENCODER_LEFT);
	wheelLeft->attachEncoder(encoderLeft);
	robot.attachLeftWheel(wheelLeft);	
	//Attach Wheel Right
  wheelRight->attachPower(PIN_POWER_RIGHT,POWER_MIN,POWER_MAX);
  wheelRight->attachDirection(PIN_DIRECTION_RIGHT);
	encoderRight->attach(PIN_ENCODER_RIGHT);
	wheelRight->attachEncoder(encoderRight);
	robot.attachRightWheel(wheelRight);
}

void loop() {
	robot.update(0.250);
	Serial.print("Robot:");
  Serial.print("\t");
  Serial.print(robot.getVx());
  Serial.print("\t");
  Serial.print(robot.getVtheta());
  Serial.print("\n");
  robot.move(0.25,0);
  delay(2500);
  robot.move(-0.25,0);
  delay(2500);
}
