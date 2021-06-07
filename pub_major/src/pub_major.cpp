#include <pub_major.hpp>

namespace major
{
    Major::Major()
    {
        major_pub = nh.advertise<std_msgs::String>("/my_major",100);
      
    }
    Major::~Major()
    {

    }
    void Major::run()
    {
        std_msgs::String major_str;
        major_str.data = "system software";

        major_pub.publish(major_str);
    }

}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"pub_major");

    major::Major mj;
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        mj.run();

        ros::spinOnce();
        loop_rate.sleep();
    }
}