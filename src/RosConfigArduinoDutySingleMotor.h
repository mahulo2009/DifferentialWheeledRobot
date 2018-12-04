#ifndef Ros_Config_Arduino_Duty_Single_Motor_H
#define Ros_Config_Arduino_Duty_Single_Motor_H

#include <RosConfigBase.h>

struct wheel_config_single_t {
    int pin_power;
    int pin_encoder;
    int pin_direction;
};

class RosConfigArduinoDutySingleMotor : public RosConfigBase {

  	public:

            RosConfigArduinoDutySingleMotor();

            virtual void read(ros::NodeHandle &nh);

            float robot_wheel_separation;
            float robot_wheel_radious;
            float max_speed;
            int power_min;
            int power_max;
            float pid_kp;
            float pid_ki;
            float pid_kd;
            int encoder_ticks_per_revoloution;            
            wheel_config_single_t wheel_config[2];

	protected:

  	private:
                
};
#endif
