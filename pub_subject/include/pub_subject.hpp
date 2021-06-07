#include "ros/ros.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <std_msgs/String.h>

namespace subject
{
    class Subject
    {
        public:
             Subject();
             ~Subject();

            void run();


        private:
            ros::NodeHandle nh;
            ros::Publisher subject_pub;

    };
}