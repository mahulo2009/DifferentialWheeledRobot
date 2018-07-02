#include "DifferentialWheeledEncoderRobot.h"

DifferentialWheeledEncoderRobot::DifferentialWheeledEncoderRobot(float wheel_separation, float wheel_radious):
		DifferentialWheeledRobot(wheel_separation,wheel_radious), 
															x_(0),y_(0),theta_(0),
															vx_(0),vy_(0),vtheta_(0)
{

}

void DifferentialWheeledEncoderRobot::update(float dt)
{
	double velocity_1  = wheelLeft_->getVelocity(dt);
  double velocity_2  = wheelRight_->getVelocity(dt);

	#ifdef DIFFERENTIAL_WHEELED_ENCODER_ROBOT_DEBUG
	Serial.print("DifferentialWheeledEncoderRobot::update:");
  Serial.print("\t");
  Serial.print(velocity_1);
  Serial.print("\t");
  Serial.print(velocity_2);
  Serial.print("\n");
	#endif

	vx_ = ( wheel_radious_ * ( velocity_1 + velocity_2 ) ) / 2.;
	vy_ = 0;
  vtheta_ = ( ( wheel_radious_ * ( velocity_1 - velocity_2 ) ) /  ( wheel_separation_ ) ) ;

	#ifdef DIFFERENTIAL_WHEELED_ENCODER_ROBOT_DEBUG
	Serial.print("DifferentialWheeledEncoderRobot::update:");
  Serial.print("\t");
  Serial.print(vx_);
  Serial.print("\t");
  Serial.print(vtheta_);
  Serial.print("\n");
	#endif

	x_ +=  vx_ * cos(theta_) * dt;
	y_ +=  vx_ * sin(theta_) * dt;
  theta_+= vtheta_ * dt;

	#ifdef DIFFERENTIAL_WHEELED_ENCODER_ROBOT_DEBUG
	Serial.print("DifferentialWheeledEncoderRobot::update:");
  Serial.print("\t");
  Serial.print(x_);
  Serial.print("\t");
  Serial.print(y_);
  Serial.print("\t");
  Serial.print(theta_);
  Serial.print("\n");
	#endif
}

