#ifndef Differential_Wheeled_Encoder_Robot_H
#define Differential_Wheeled_Encoder_Robot_H

#define DIFFERENTIAL_WHEELED_ENCODER_ROBOT_DEBUG 1

#include "Arduino.h"
#include <Encoder.h>
#include <DifferentialWheeledRobot.h>

class DifferentialWheeledEncoderRobot : public DifferentialWheeledRobot {
  public:
    DifferentialWheeledEncoderRobot(float wheel_separation,float wheel_radious);
		void update(float dt);
		float getX()  {return x_;};		
		float getY()  {return y_;};
		float getTheta()  {return theta_;};				
		float getVx() {return vx_;};
		float getVy() {return vy_;};
		float getVtheta() {return vtheta_;};
  private:
		float x_;
		float y_;
 		float theta_;
		float vx_;
		float vy_;
  	float vtheta_;
};
#endif

