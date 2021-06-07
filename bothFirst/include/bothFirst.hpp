#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Float64.h>
#include <cstdlib>
#include <ctime>
#include <bothFirst/my_msg.h>

namespace bothFirst
{
    class BothFirst
    {
        public:
         BothFirst();
         ~BothFirst();

         void run();
         float genFirst();

        private:
            ros::NodeHandle nh;


            ros::Publisher pubFirst;

    };
}