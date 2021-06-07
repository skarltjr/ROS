#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Int32.h>
#include <cstdlib>
#include <ctime>
#include <a_pub/my_msg.h>

namespace a_pub
{
    class A_Pub
    {
        public:
            A_Pub();
            ~A_Pub();
            void run();
            int makeRandInt();
            float makeRandFloat();
            std::string makeRandString();
    
        private:
            ros::NodeHandle nh;
            ros::Publisher intPub;
            ros::Publisher myPub;
            a_pub::my_msg msg;
            std_msgs::Int32 intMsg;

    
    };  
}