#include "RobotFactorySingleMotor.h"

RobotFactorySingleMotor::RobotFactorySingleMotor(RosConfigArduinoDutySingleMotor  * robot_confing) 
{
    this->robot_confing = robot_confing;
}

RobotBase * RobotFactorySingleMotor::buildRobot()
{
    //Robot
    RobotBase * robot = 
        new DifferentialWheeledRobot(robot_confing->robot_wheel_separation,robot_confing->robot_wheel_radious);
    return robot;
}

WheelBase * RobotFactorySingleMotor::buildWheel(int index)
{
    //Pid
    Pid * pid = new Pid();
    //pid>setMaxWindup(max_speed); //TODO
    pid->setAlpha(1.0);
    pid->setKp(robot_confing->pid_kp);
    pid->setKi(robot_confing->pid_ki);
    pid->setKd(robot_confing->pid_kd);

    //Encoder
    Encoder * encoder = new Encoder(robot_confing->encoder_ticks_per_revoloution);
    encoder->attach(robot_confing->pin_encoder);

    //Controller
    ArduinoDutySingleMotorHardwareController * controller_left = 
        new ArduinoDutySingleMotorHardwareController(robot_confing->max_speed,robot_confing->power_min,robot_confing->power_max);
    controller_left->attachPower(robot_confing->pin_power);
    controller_left->attachDirection(robot_confing->pin_direction);

    //Wheel
    WheelEncoder * wheel = new WheelEncoder();
    wheel->attachController(controller_left);
    wheel->attachEncoder(encoder);
    wheel->attachPid(pid);

    return wheel;
}
