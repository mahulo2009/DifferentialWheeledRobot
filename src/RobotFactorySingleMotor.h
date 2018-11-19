#ifndef Robot_Factory_Single_Motor_H
#define Robot_Factory_Single_Motor_H

#include "RobotFactory.h"
#include "Pid.h"
#include "Encoder.h"
#include "WheelEncoder.h"
#include "ArduinoDutySingleMotorHardwareController.h"
#include "DifferentialWheeledRobot.h"

class RobotFactorySingleMotor : public RobotFactory {

  	public:

        RobotFactorySingleMotor();

        virtual RobotBase * buildRobot();

        virtual WheelBase * buildWheel();

	protected:

  	private:
};
#endif
