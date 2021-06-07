#include "ros/ros.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <a_first/my_msg.h>

namespace a_second
{
    class A_Second
    {

        public:
         A_Second();
         ~A_Second();
         void callbackPrev(const a_first::my_msg::ConstPtr &ptr);
         float genFloat();
        private:
            ros::NodeHandle nh;
            ros::Subscriber sub;
            ros::Publisher pub;
            a_first::my_msg msg;
    };
}