#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Int32.h>
#include <a_pub/my_msg.h>

namespace a_sub
{
    class A_Sub
    {
        public:
         A_Sub();
         ~A_Sub();  
         void callbackInt(const std_msgs::Int32::ConstPtr &ptr);
         void callbackMsg(const a_pub::my_msg::ConstPtr &ptr);

        private:
            ros::NodeHandle nh;
            ros::Subscriber intSub;
            ros::Subscriber msgSub;  
    };
}