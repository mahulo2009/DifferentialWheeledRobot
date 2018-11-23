#include <RosConfigArduinoDutyDualMotor.h>



RosConfigArduinoDutyDualMotor::RosConfigArduinoDutyDualMotor()
{

}

void RosConfigArduinoDutyDualMotor::read(ros::NodeHandle &nh)
{
    nh.getParam("/robomat/max_speed", &this->max_speed);
    nh.getParam("/robomat/power_min", &this->power_min);
    nh.getParam("/robomat/power_max", &this->power_max);
    
    nh.getParam("/robomat/pin_power_right", &this->pin_power_right);
    nh.getParam("/robomat/pin_direction_right_1", &this->pin_direction_right_1);
    nh.getParam("/robomat/pin_direction_right_2", &this->pin_direction_right_2);

    nh.getParam("/robomat/pin_power_left", &this->pin_power_left); 
    nh.getParam("/robomat/pin_direction_left_1", &this->pin_direction_left_1);
    nh.getParam("/robomat/pin_direction_left_2", &this->pin_direction_left_2);
    
    nh.getParam("/robomat/robot_wheel_separation", &this->robot_wheel_separation);
    nh.getParam("/robomat/robot_wheel_radious", &this->robot_wheel_radious);  
   
}
