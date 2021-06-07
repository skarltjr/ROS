#include <bothController.hpp>

namespace bothController
{
    BothController::BothController()
    {
        publ = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",100);
        subs = nh.subscribe("/second",100,&BothController::callbackPrevMsg,this);

    }
    BothController::~BothController()
    {

    }
    void BothController::callbackPrevMsg(const bothFirst::my_msg::ConstPtr &ptr)
    {
        geometry_msgs::Twist msg;
        msg.linear.x = ptr->rand_first.data;
        msg.linear.y = ptr->rand_second.data;
        msg.linear.z = 0.0;
        msg.angular.x = 0.0;
        msg.angular.y = 0.0;
        msg.angular.z = (rand()%100)/100.0;
    }
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"bothCOn");
    bothController::BothController bc;
    ros::spin();
}