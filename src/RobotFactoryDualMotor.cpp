#include "RobotFactoryDualMotor.h"

RobotFactoryDualMotor::RobotFactoryDualMotor(params_t params)
{
    this->params_ = params;
}

RobotBase * RobotFactoryDualMotor::buildRobot()
{
    //Robot
    DifferentialWheeledRobot * robot = new DifferentialWheeledRobot(params_.robot_wheel_separation,params_.robot_wheel_radious);
    return robot;
}

WheelBase * RobotFactoryDualMotor::buildWheel()
{
    ArduinoDutyDualMotorHardwareController * controller = 
            new ArduinoDutyDualMotorHardwareController(params_.max_speed,params_.power_min,params_.power_max);
    controller->attachPower(params_.pin_power);
    controller->attachDirection(params_.pin_direction_1,params_.pin_direction_2);

    //Wheel Left
    Wheel * wheel = new Wheel();
    wheel->attachController(controller);

    return wheel;
}
