#include <a_controller.hpp>

namespace a_controller
{
    A_Controller::A_Controller()
    {
        pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",100);
        sub = nh.subscribe<a_first::my_msg>("/second",100,&callbackPrev,this);
    }
    A_Controller::~A_Controller()
    {

    }
    void A_Controller::callbackPrev(const a_first::my_msg::ConstPtr &ptr)
    {
        msg.linear.x = ptr->rand_first.data;
        msg.linear.y = ptr->rand_second.data;
        msg.linear.z = 0.0;
        msg.angular.x = 0.0;
        msg.angular.y = 0.0;
        msg.angular.z = (rand()%100)/3.0;

        pub.publish(msg);
    }

}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"controller");
    a_controller::A_Controller cont;
    ros::spin();
}