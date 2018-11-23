#include "RobotFactoryDualMotor.h"

RobotFactoryDualMotor::RobotFactoryDualMotor(RosConfigArduinoDutyDualMotor * robot_confing) 
{  
    this->robot_confing = robot_confing;
}

RobotBase * RobotFactoryDualMotor::buildRobot()
{
    //Robot
    DifferentialWheeledRobot * robot = 
        new DifferentialWheeledRobot(robot_confing->robot_wheel_separation,robot_confing->robot_wheel_radious);
    return robot;
}

WheelBase * RobotFactoryDualMotor::buildWheel(int index)
{
    ArduinoDutyDualMotorHardwareController * controller = 
            new ArduinoDutyDualMotorHardwareController(robot_confing->max_speed,robot_confing->power_min,robot_confing->power_max);

    if ( index == 0 )  
    {
        controller->attachPower(robot_confing->pin_power_left);
        controller->attachDirection(robot_confing->pin_direction_left_1,robot_confing->pin_direction_left_2);
    } 
    else 
    {
        controller->attachPower(robot_confing->pin_power_right);
        controller->attachDirection(robot_confing->pin_direction_right_1,robot_confing->pin_direction_right_2);

    }

    //Wheel Left
    Wheel * wheel = new Wheel();
    wheel->attachController(controller);

    return wheel;
}
