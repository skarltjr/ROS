#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Int32.h>
#include <cstdlib>
#include <ctime>
#include <my_publisher_class/class_msg.h>

namespace my_publisher_class
{
    class MyPublisherClass
    {
        public:
             MyPublisherClass();
             ~MyPublisherClass();

            void run();
            int makeRandInt();
            float makeRandFloat();
            std::string makeString();

        private:
            ros::NodeHandle nh;
            ros::NodeHandle private_nh;

            ros::Publisher pub_rand_int_;
            ros::Publisher pub_class_msg;

            std_msgs::Int32 my_data_int_;
            my_publisher_class::class_msg class_msg_;

            // private_nh에서 사용하는 파라미터를 위한 변수들
            int param_int;
            float param_float;
            std::string param_string;

            // nh에서 사용하는 파라미터를 위한
            int param_int_nh;
            float param_float_nh;
            std::string param_string_nh;
    };
}