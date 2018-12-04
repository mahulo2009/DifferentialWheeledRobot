#include "RosConfigArduinoDutySingleMotor.h"

RosConfigArduinoDutySingleMotor::RosConfigArduinoDutySingleMotor()
{

}

void RosConfigArduinoDutySingleMotor::read(ros::NodeHandle &nh)
{
    nh.getParam("/robomat/max_speed", &this->max_speed);
    nh.getParam("/robomat/pin_power_left", &this->wheel_config[0].pin_power); 
    nh.getParam("/robomat/pin_power_right", &this->wheel_config[1].pin_power);
    nh.getParam("/robomat/power_min", &this->power_min);
    nh.getParam("/robomat/power_max", &this->power_max);
    nh.getParam("/robomat/robot_wheel_separation", &this->robot_wheel_separation);
    nh.getParam("/robomat/robot_wheel_radious", &this->robot_wheel_radious);
    nh.getParam("/robomat/pid_kp", &this->pid_kp);
    nh.getParam("/robomat/pid_ki", &this->pid_ki);
    nh.getParam("/robomat/pid_kd", &this->pid_kd);
    nh.getParam("/robomat/encoder_ticks_per_revoloution", &this->encoder_ticks_per_revoloution);
    nh.getParam("/robomat/pin_encoder_left", &this->wheel_config[0].pin_encoder);
    nh.getParam("/robomat/pin_encoder_right", &this->wheel_config[1].pin_encoder);
    nh.getParam("/robomat/pin_direction_left", &this->wheel_config[0].pin_direction);
    nh.getParam("/robomat/pin_direction_right", &this->wheel_config[1].pin_direction);        
}
