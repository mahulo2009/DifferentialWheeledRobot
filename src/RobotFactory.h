#ifndef Robot_Factory_H
#define Robot_Factory_H

#include "RobotBase.h"
#include "WheelBase.h"


//TODO CREATE AND PASS PARAMETERS

class RobotFactory {

  	public:

        RobotFactory();

        virtual RobotBase * assembly();

        virtual RobotBase * buildRobot() = 0;

        virtual WheelBase * buildWheel() = 0;

	protected:

  	private:
};
#endif
