#ifndef Ros_Config_Arduino_Duty_Dual_Motor_H
#define Ros_Config_Arduino_Duty_Dual_Motor_H

#include <RosConfigBase.h>

class RosConfigArduinoDutyDualMotor : public RosConfigBase {

  	public:

            RosConfigArduinoDutyDualMotor();

            virtual void read(ros::NodeHandle &nh);

            float max_speed;
            int power_min;
            int power_max;

            int pin_power_right;
            int pin_direction_right_1;
            int pin_direction_right_2;

            int pin_power_left;
            int pin_direction_left_1;
            int pin_direction_left_2;

            float robot_wheel_separation;
            float robot_wheel_radious;            
            
	protected:

  	private:

          
};
#endif


      
      
      
      
      





