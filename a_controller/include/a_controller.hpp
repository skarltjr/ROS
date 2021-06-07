#include "ros/ros.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <a_first/my_msg.h>
#include <geometry_msgs/Twist.h>

namespace a_controller
{
    class A_Controller
    {
        public:
        A_Controller();
        ~A_Controller();
        void callbackPrev(const a_first::my_msg::ConstPtr &ptr);
        private:
        ros::NodeHandle nh;
        ros::Subscriber sub;
        ros::Publisher pub;
        geometry_msgs::Twist msg;
    };
}