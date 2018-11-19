#include "RobotFactorySingleMotor.h"

RobotFactorySingleMotor::RobotFactorySingleMotor() 
{
}

RobotBase * RobotFactorySingleMotor::buildRobot(const params_t & params_robot)
{
    //Robot
    RobotBase * robot = 
        new DifferentialWheeledRobot(params_robot.robot_wheel_separation,params_robot.robot_wheel_radious);
    return robot;
}

WheelBase * RobotFactorySingleMotor::buildWheel(const params_t & params_robot,
                                                    const params_t & params_wheel)
{
    //Pid
    Pid * pid = new Pid();
    //pid>setMaxWindup(max_speed); //TODO
    pid->setAlpha(1.0);
    pid->setKp(params_robot.pid_kp);
    pid->setKi(params_robot.pid_ki);
    pid->setKd(params_robot.pid_kd);

    //Encoder
    Encoder * encoder = new Encoder(params_robot.encoder_ticks_per_revoloution);
    encoder->attach(params_wheel.pin_encoder);

    //Controller
    ArduinoDutySingleMotorHardwareController * controller_left = 
        new ArduinoDutySingleMotorHardwareController(params_robot.max_speed,params_robot.power_min,params_robot.power_max);
    controller_left->attachPower(params_wheel.pin_power);
    controller_left->attachDirection(params_wheel.pin_direction);

    //Wheel
    WheelEncoder * wheel = new WheelEncoder();
    wheel->attachController(controller_left);
    wheel->attachEncoder(encoder);
    wheel->attachPid(pid);

    return wheel;
}
