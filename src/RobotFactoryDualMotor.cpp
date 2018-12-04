#include "RobotFactoryDualMotor.h"

RobotFactoryDualMotor::RobotFactoryDualMotor(RosConfigArduinoDutyDualMotor * robot_confing) 
{  
    this->robot_confing = robot_confing;
}

RobotBase * RobotFactoryDualMotor::buildRobot()
{
    //Robot
    RobotBase * robot = 
        new DifferentialWheeledRobot(robot_confing->robot_wheel_separation,robot_confing->robot_wheel_radious);
    return robot;
}

WheelBase * RobotFactoryDualMotor::buildWheel(int index)
{    
    //Controller
    ArduinoDutyDualMotorHardwareController * controller = 
            new ArduinoDutyDualMotorHardwareController(robot_confing->max_speed,robot_confing->power_min,robot_confing->power_max);

    controller->attachPower(robot_confing->wheel_config[index].pin_power);
    controller->attachDirection(robot_confing->wheel_config[index].pin_direction_1,robot_confing->wheel_config[index].pin_direction_2);

    //Wheel
    WheelBase * wheel = new Wheel();
    wheel->attachController(controller);

    return wheel;
}
