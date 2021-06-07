#include "ros/ros.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <std_msgs/String.h>

namespace name
{
    class Name
    {
        public:
             Name();
             ~Name();

            void run();


        private:
            ros::NodeHandle nh;
            ros::Publisher name_pub;

    };
}