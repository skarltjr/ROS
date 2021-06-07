#include <random_turtlesim_controller.hpp>

namespace random_turtlesim_controller
{
    RandomTurtlesimController::RandomTurtlesimController()
    {
        pub_cmd_vel_ = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",100);
        sub_prev_msg_ = nh.subscribe("/third",100,&RandomTurtlesimController::callbackPrevMsg,this);

    }
    RandomTurtlesimController::~RandomTurtlesimController()
    {

    }

    void RandomTurtlesimController::callbackPrevMsg(const random_gen_x::control_msg::ConstPtr &ptr)
    {
        geometry_msgs::Twist control_msg;

       
        control_msg.linear.x = ptr->rand_x.data;
        control_msg.linear.y = 0.0;
        control_msg.linear.z = 0.0;
        control_msg.angular.x = 0.0;
        control_msg.angular.y = 0.0;
        control_msg.angular.z = ptr->rand_yaw.data;

        pub_cmd_vel_.publish(control_msg);
    }

}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"random_gen_controller");

    random_turtlesim_controller::RandomTurtlesimController RTC;
    ros::spin();
   
}