#include "RobotFactorySingleMotor.h"

RobotFactorySingleMotor::RobotFactorySingleMotor() 
{
}

RobotBase * RobotFactorySingleMotor::buildRobot()
{
    float robot_wheel_separation,robot_wheel_radious;
    //Robot
    RobotBase * robot = new DifferentialWheeledRobot(robot_wheel_separation,robot_wheel_radious);
    return robot;
}

WheelBase * RobotFactorySingleMotor::buildWheel()
{
    float pid_kp, pid_ki, pid_kd;
    float max_speed;
    int encoder_ticks_per_revoloution;
    int pin_encoder;
    int pin_power;
    int pin_direction;
    int power_min,power_max;

    //Pid Left
    Pid * pid = new Pid();
    //pid>setMaxWindup(max_speed); //TODO
    pid->setAlpha(1.0);
    pid->setKp(pid_kp);
    pid->setKi(pid_ki);
    pid->setKd(pid_kd);

    //Encoder Left
    Encoder * encoder = new Encoder(encoder_ticks_per_revoloution);
    encoder->attach(pin_encoder);

    ArduinoDutySingleMotorHardwareController * controller_left = new ArduinoDutySingleMotorHardwareController(max_speed,power_min,power_max);
    controller_left->attachPower(pin_power);
    controller_left->attachDirection(pin_direction);

    //Wheel Left
    WheelEncoder * wheel = new WheelEncoder();
    wheel->attachController(controller_left);
    wheel->attachEncoder(encoder);
    wheel->attachPid(pid);

    return wheel;
}
