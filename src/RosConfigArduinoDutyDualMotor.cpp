#include <RosConfigArduinoDutyDualMotor.h>



RosConfigArduinoDutyDualMotor::RosConfigArduinoDutyDualMotor()
{

}

void RosConfigArduinoDutyDualMotor::read(ros::NodeHandle &nh)
{
    nh.getParam("/robomat/max_speed", &this->max_speed);
    nh.getParam("/robomat/power_min", &this->power_min);
    nh.getParam("/robomat/power_max", &this->power_max);
    nh.getParam("/robomat/pin_power_left", &this->wheel_config[0].pin_power); 
    nh.getParam("/robomat/pin_direction_left_1", &this->wheel_config[0].pin_direction_1);
    nh.getParam("/robomat/pin_direction_left_2", &this->wheel_config[0].pin_direction_2);
    nh.getParam("/robomat/pin_power_right", &this->wheel_config[1].pin_power); 
    nh.getParam("/robomat/pin_direction_right_1", &this->wheel_config[1].pin_direction_1);
    nh.getParam("/robomat/pin_direction_right_2", &this->wheel_config[1].pin_direction_2);
    nh.getParam("/robomat/robot_wheel_separation", &this->robot_wheel_separation);
    nh.getParam("/robomat/robot_wheel_radious", &this->robot_wheel_radious);  
   
}
