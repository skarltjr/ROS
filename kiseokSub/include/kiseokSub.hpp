#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Int32.h>
#include <kiseokPub/my_msg.h>

namespace kiseokSub
{
    class KiseokSub
    {
        public:
            KiseokSub();
            ~KiseokSub();

            void callbackRandInt(const std_msgs::Int32::ConstPtr &msg);
            void callbackClassMsg(const kiseokPub::my_msg::ConstPtr &msg);
            void run();

        private:
            ros::NodeHandle nh;

            ros::Subscriber subInt;
            ros::Subscriber subMymsg;
    };
}