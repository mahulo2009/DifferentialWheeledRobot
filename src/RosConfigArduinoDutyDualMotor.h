#ifndef Ros_Config_Arduino_Duty_Dual_Motor_H
#define Ros_Config_Arduino_Duty_Dual_Motor_H

#include <RosConfigBase.h>


struct wheel_config_dual_t {
    int pin_power;    
    int pin_direction_1;
    int pin_direction_2;
};

class RosConfigArduinoDutyDualMotor : public RosConfigBase {

  	public:

            RosConfigArduinoDutyDualMotor();

            virtual void read(ros::NodeHandle &nh);

            float max_speed;
            int power_min;  //
            int power_max;
            float robot_wheel_separation;
            float robot_wheel_radious; 

            wheel_config_dual_t wheel_config[2];
            
	protected:

  	private:

          
};
#endif


      
      
      
      
      





