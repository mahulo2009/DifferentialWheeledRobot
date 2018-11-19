#ifndef Robot_Factory_Single_Motor_H
#define Robot_Factory_Single_Motor_H

#include "RobotFactory.h"
#include "Wheel.h"
#include "ArduinoDutyDualMotorHardwareController.h"
#include "DifferentialWheeledRobot.h"

struct params_t {
      float robot_wheel_separation,robot_wheel_radious;
      int pin_direction_1,pin_direction_2;
      int pin_power;
      float max_speed;
      int power_min,power_max;
};

class RobotFactoryDualMotor : public RobotFactory {

  	public:

        RobotFactoryDualMotor(params_t  params);

        virtual RobotBase * buildRobot();

        virtual WheelBase * buildWheel();

	protected:

  	private:
            params_t  params_;
};
#endif
