
#include <iostream>
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <week_4_exercises/FloatWithHeader.h>

double cosine = 0;
double sine = 0;
ros::Publisher sum_pub;

void cosineCallback(week_4_exercises::FloatWithHeader cos_msg) {
  cosine = cos_msg.data;
  std::cout << cos_msg.data << std::endl;
}

void sineCallback(week_4_exercises::FloatWithHeader sin_msg) {
  sine = sin_msg.data;
  //std::cout << sin_msg.data << std::endl;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "custom_message_node_sub");
  ros::NodeHandle nh;

  ros::Subscriber cos_sub = nh.subscribe("cosine", 1, cosineCallback);
  ros::Subscriber sin_sub = nh.subscribe("sine", 1, sineCallback);

  sum_pub = nh.advertise<std_msgs::Float64>("output", 1);

  //ros::Subscriber custom_sub = nh.subscribe("cosine_sine", 1, customCallback);

  //ros::spin();
  ros::Rate rate(20);
  while(ros::ok()) {
    week_4_exercises::FloatWithHeader pub_msg;
    pub_msg.data = std::max(cosine, sine);

    sum_pub.publish(pub_msg);

    ros::spinOnce();
    rate.sleep();
  }
}
