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

		virtual  void move(float velocity_x, float velocity_theta);
		virtual void stop();
        virtual void update(float dt);

		void attachLeftWheel(WheelBase * wheelLeft);
		void attachRightWheel(WheelBase * wheelRight);
		void attachSonar(Sonar * sonar);
					
		void sonarTo(int position);
		float getDistance();
		float getSonarAngle();
		
	protected:
	    float wheel_separation_;
	    float wheel_radious_;	
		WheelBase * wheelLeft_;
		WheelBase * wheelRight_;
		Sonar * sonar_;
};
#endif