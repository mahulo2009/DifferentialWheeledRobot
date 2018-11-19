#ifndef Robot_Factory_H
#define Robot_Factory_H

#include "RobotBase.h"
#include "WheelBase.h"

//TODO Improve the way to get the configuration
struct params_t {
      float robot_wheel_separation,robot_wheel_radious;
      int pin_direction_1,pin_direction_2;
      int pin_power;
      float max_speed;
      int power_min,power_max;
      float pid_kp, pid_ki, pid_kd;
      int encoder_ticks_per_revoloution;
      int pin_encoder;
      int pin_direction;
};

class RobotFactory {

  	public:

        RobotFactory();

        virtual RobotBase * assembly(const params_t & params_robot,
                                          const params_t & params_left, 
                                          const params_t & params_right
                                          );

        virtual RobotBase * buildRobot(const params_t & params_robot) = 0;

        virtual WheelBase * buildWheel(const params_t & params_robot,
                                          const params_t & params_wheel) = 0;

	protected:

  	private:
};
#endif
