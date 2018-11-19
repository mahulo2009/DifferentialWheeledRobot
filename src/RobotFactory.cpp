#include "RobotFactory.h"

RobotFactory::RobotFactory() 
{
}

RobotBase * RobotFactory::assembly(const params_t & params_robot,const params_t & params_left, const params_t & params_right)
{
    RobotBase * robot = buildRobot(params_robot);

    WheelBase * wheel_left = buildWheel(params_robot,params_left);
    robot->attachLeftWheel(wheel_left);       

    WheelBase * wheel_right = buildWheel(params_robot,params_right);
    robot->attachRightWheel(wheel_right); 
}