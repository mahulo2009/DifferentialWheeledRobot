#ifndef Differential_Wheeled_Robot_H
#define Differential_Wheeled_Robot_H

//#define DIFFERENTIAL_WHEELED_ROBOT_DEBUG 1

#include "Arduino.h"
#include <WheelBase.h>
#include <Sonar.h>
#include "RobotBase.h"

class DifferentialWheeledRobot : public RobotBase {
  	public:
	    DifferentialWheeledRobot(float wheel_separation,float wheel_radious);

		virtual void move(float velocity_x, float velocity_theta);
		virtual void stop();
        virtual void update(float dt);
		
	protected:
	    float wheel_separation_;
	    float wheel_radious_;	
		Sonar * sonar_;
};
#endif