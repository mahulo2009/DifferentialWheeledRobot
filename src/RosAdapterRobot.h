#ifndef Ros_Robot_Adapter_H
#define Ros_Robot_Adapter_H

#include <ros.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>
#include <sensor_msgs/Range.h>
#include <nav_msgs/Odometry.h>

#include <RosNodeBase.h>
#include <RobotBase.h>

class RosAdapterRobot  : public RosNodeBase {

  	public:

            RosAdapterRobot();

            virtual void init(ros::NodeHandle &nh);
            virtual void update(ros::Time &current_time,tf::TransformBroadcaster &broadcaster);
            
            void cmd_velocity_callback(const geometry_msgs::Twist& CVel);            
            
            void attachRobot(RobotBase * robot) {
                this->robot_=robot;
            }
                    
	protected:

  	private:
            
            ros::Subscriber<geometry_msgs::Twist, RosAdapterRobot> cmd_velocity_sub_;            
            ros::Publisher odom_pub_;
            nav_msgs::Odometry odom_nav_msg_;
            geometry_msgs::TransformStamped odom_trans_;                                                  
            
            RobotBase * robot_;
};
#endif