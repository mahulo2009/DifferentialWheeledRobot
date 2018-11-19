#ifndef Robot_Factory_Dual_Motor_H
#define Robot_Factory_Dual_Motor_H

#include "RobotFactory.h"
#include "Wheel.h"
#include "ArduinoDutyDualMotorHardwareController.h"
#include "DifferentialWheeledRobot.h"


class RobotFactoryDualMotor : public RobotFactory {

  	public:

        RobotFactoryDualMotor();

        virtual RobotBase * buildRobot(const params_t & params_robot);

        virtual WheelBase * buildWheel(const params_t & params_robot,
                                          const params_t & params_wheel);

	protected:

  	
};
#endif
