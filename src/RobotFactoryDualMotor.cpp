#include "RobotFactoryDualMotor.h"

RobotFactoryDualMotor::RobotFactoryDualMotor()
{  
}

RobotBase * RobotFactoryDualMotor::buildRobot(const params_t & params_robot)
{
    //Robot
    DifferentialWheeledRobot * robot = 
        new DifferentialWheeledRobot(params_robot.robot_wheel_separation,params_robot.robot_wheel_radious);
    return robot;
}

WheelBase * RobotFactoryDualMotor::buildWheel(const params_t & params_robot,
                                                    const params_t & params_wheel)
{
    ArduinoDutyDualMotorHardwareController * controller = 
            new ArduinoDutyDualMotorHardwareController(params_robot.max_speed,params_robot.power_min,params_robot.power_max);
    controller->attachPower(params_wheel.pin_power);
    controller->attachDirection(params_wheel.pin_direction_1,params_wheel.pin_direction_2);

    //Wheel Left
    Wheel * wheel = new Wheel();
    wheel->attachController(controller);

    return wheel;
}
