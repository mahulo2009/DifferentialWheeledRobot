#include "RobotFactory.h"

RobotFactory::RobotFactory() 
{

}

RobotBase * RobotFactory::assembly() 
{
    RobotBase * robot = buildRobot();

    robot->attachLeftWheel(buildWheel());       //TODO INCLUDE HERE PARAMS 
    robot->attachRightWheel(buildWheel()); 
}