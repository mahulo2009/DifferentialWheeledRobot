#include "RobotBase.h"

RobotBase::RobotBase() 	:   x_(0),y_(0),theta_(0),
						    vx_(0),vy_(0),vtheta_(0)

{
}

void RobotBase::attachLeftWheel(WheelBase * wheelLeft)
{
	this->wheelLeft_= wheelLeft;
}

void RobotBase::attachRightWheel(WheelBase * wheelRight)
{
    this->wheelRight_= wheelRight;
}