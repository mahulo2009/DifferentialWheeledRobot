#include "RosAdapterRobot.h"

RosAdapterRobot::RosAdapterRobot() : 
    cmd_velocity_sub_("/car/cmd_vel", &RosAdapterRobot::cmd_velocity_callback,this),
    odom_pub_("/car/odom", &odom_nav_msg_)   
{   
}

void RosAdapterRobot::init(ros::NodeHandle &nh)
{
    nh.subscribe(cmd_velocity_sub_);
    nh.advertise(odom_pub_);
}

void RosAdapterRobot::cmd_velocity_callback(const geometry_msgs::Twist& CVel)
{
    if (robot_ != 0 ) {
        robot_->move(CVel.linear.x,CVel.angular.z);  
    }
}

void RosAdapterRobot::update(ros::Time &current_time,tf::TransformBroadcaster &broadcaster)
{
    //robot_->update(dt); //TODO CHECK IF ROBOT IS NOT 0
  
    // tf odom->base_link
    odom_trans_.header.stamp = current_time;
    odom_trans_.header.frame_id = "/odom";
    odom_trans_.child_frame_id = "/base_link";
    odom_trans_.transform.translation.x = robot_->getX();
    odom_trans_.transform.translation.y = robot_->getY();
    odom_trans_.transform.translation.z = 0.0;
    odom_trans_.transform.rotation = tf::createQuaternionFromYaw(robot_->getTheta()); //TODO REVIEW THIS THE ANGLE IS NOT CORRECT
    broadcaster.sendTransform(odom_trans_);

    //BEGIN odometry  
    odom_nav_msg_.header.stamp = current_time;
    odom_nav_msg_.header.frame_id = "/odom";
    //set the position
    odom_nav_msg_.pose.pose.position.x = robot_->getX();
    odom_nav_msg_.pose.pose.position.y = robot_->getY();
    odom_nav_msg_.pose.pose.position.z = 0.0;
    odom_nav_msg_.pose.pose.orientation = tf::createQuaternionFromYaw(robot_->getTheta()); //TODO REVIEW THIS THE ANGLE IS NOT CORRECT
    //set the velocity
    odom_nav_msg_.child_frame_id = "/base_link";
    odom_nav_msg_.twist.twist.linear.x = robot_->getVx();
    odom_nav_msg_.twist.twist.linear.y = robot_->getVy();
    odom_nav_msg_.twist.twist.angular.z = robot_->getVtheta();
    odom_pub_.publish(&odom_nav_msg_);
    //END odometry  
}