#include "ros/ros.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <a_first/my_msg.h>

namespace a_first
{
    class A_First
    {
        public:
            A_First();
            ~A_First();

            void run();
            float genFloat();
        private:
            ros::NodeHandle nh;
            ros::Publisher pub;
            a_first::my_msg msg;
    };
}