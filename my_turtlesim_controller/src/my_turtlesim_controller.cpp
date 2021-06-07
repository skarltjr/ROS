#include "ros/ros.h"
#include <iostream>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    ros::init(argc,argv,"my_turtlesim_controller");

    ros::NodeHandle nh;

    ros::Publisher pub_controller = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",100);

    ros::Rate loop_rate(10); // 1초에 10번

    while(ros::ok()) // ros가 꺼질 때 까지
    {
        geometry_msgs::Twist twist; // twist 객체만들어서 
        twist.linear.x = 2.0;
        twist.linear.y = 0.0;
        twist.linear.z = 0.0;
        twist.angular.x = 0.0;
        twist.angular.y = 0.0;
        twist.angular.z = -1.8;

        pub_controller.publish(twist); // publish . 보낸다 

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}