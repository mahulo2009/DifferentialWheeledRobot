#ifndef Differential_Wheeled_Robot_H
#define Differential_Wheeled_Robot_H

#define DIFFERENTIAL_WHEELED_ROBOT_DEBUG 1

#include "Arduino.h"
#include <Wheel.h>

class DifferentialWheeledRobot {
  	public:
	    DifferentialWheeledRobot(float wheel_separation,float wheel_radious);
		void attachLeftWheel(Wheel * wheelLeft);
		void attachRightWheel(Wheel * wheelRight);
		void move(float velocity_x, float velocity_theta);
		void stop();
		void update(float dt);
		float getX()  {return x_;};		
		float getY()  {return y_;};
		float getTheta()  {return theta_;};				
		float getVx() {return vx_;};
		float getVy() {return vy_;};
		float getVtheta() {return vtheta_;};
	protected:
	    float wheel_separation_;
	    float wheel_radious_;	
		Wheel * wheelLeft_;
		Wheel * wheelRight_;
  	private:
		float x_;
		float y_;
 		float theta_;
		float vx_;
		float vy_;
  		float vtheta_;
};
#endif