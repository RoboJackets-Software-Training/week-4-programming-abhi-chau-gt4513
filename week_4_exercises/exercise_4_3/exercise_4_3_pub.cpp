#include <iostream>
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <nav_msgs/Odometry.h>
#include <week_4_exercises/FloatWithHeader.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "custom_message_node_pub");
  ros::NodeHandle nh;

  ros::Publisher cos_pub = nh.advertise<week_4_exercises::FloatWithHeader>("cosine", 1);
  ros::Publisher sin_pub = nh.advertise<week_4_exercises::FloatWithHeader>("sine", 1);

  ros::Rate rate(20);
  while(ros::ok()) {
    ros::Time time = ros::Time::now();

    week_4_exercises::FloatWithHeader cos_msg;
    cos_msg.data = cos(time.toSec());
    cos_pub.publish(cos_msg);
    week_4_exercises::FloatWithHeader sin_msg;
    sin_msg.data = sin(time.toSec());
    sin_pub.publish(sin_msg);

    ros::spinOnce();
    rate.sleep();
  }
}
