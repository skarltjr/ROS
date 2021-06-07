#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Float64.h>
#include <cstdlib>
#include <ctime>
#include <bothFirst/my_msg.h>

namespace bothSecond
{
    class BothSecond
    {
        public:
            BothSecond();
            ~BothSecond();

            void callbackPrevMsg(const bothFirst::my_msg::ConstPtr &ptr);
            float genSecond();
        private:

            ros::NodeHandle nh;

            ros::Publisher pubSecond;
            ros::Subscriber subFirst;

            bothFirst::my_msg prev_msg;
    };
}