#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Float64.h>
#include <cstdlib>
#include <ctime>
#include <bothFirst/my_msg.h>
#include <geometry_msgs/Twist.h>

namespace bothController
{
    class BothController
    {
        public:
            BothController();
            ~BothController();

            void callbackPrevMsg(const bothFirst::my_msg::ConstPtr &ptr);

        private:
        ros::NodeHandle nh;

        ros::Publisher publ;
        ros::Subscriber subs;
    };
}