#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>
#include <cstdlib>
#include <ctime>


namespace major
{
    class Major
    {
        public:
             Major();
             ~Major();

             void run();
            

        private:
            ros::NodeHandle nh;
            ros::Publisher major_pub;
    };
}