#ifndef Robot_Factory_Single_Motor_H
#define Robot_Factory_Single_Motor_H

#include "RobotFactory.h"
#include "Pid.h"
#include "Encoder.h"
#include "WheelEncoder.h"
#include "ArduinoDutySingleMotorHardwareController.h"
#include "DifferentialWheeledRobot.h"
#include "RosConfigArduinoDutySingleMotor.h"

class RobotFactorySingleMotor : public RobotFactory {

  	public:

            RobotFactorySingleMotor(RosConfigArduinoDutySingleMotor  * robot_confing);

            virtual RobotBase * buildRobot();

            virtual WheelBase * buildWheel(int index);

	protected:

  	private:

            RosConfigArduinoDutySingleMotor * robot_confing;
};
#endif
