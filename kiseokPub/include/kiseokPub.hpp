#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Int32.h>
#include <cstdlib>
#include <ctime>
#include <kiseokPub/my_msg.h>

namespace kiseokPub
{
    class KiseokPub
    {
       public:
        KiseokPub();
        ~KiseokPub();

        void run();
        int makeRandInt();
        float makeRandFloat();
        std::string makeString();

       private:
       ros::NodeHandle nh;
       ros::NodeHandle private_nh;

       ros::Publisher intPub;
       ros::Publisher msgPub;

       std_msgs::Int32 intData;
       kiseokPub::my_msg my_msg;

       // param 이름 똑같이 해서 받아올 수 있음 launch랑
       int param_int;
       float param_float;
       std::string param_string;
    };
}