#include <pub_name.hpp>

namespace name
{
    Name::Name()
    {
      name_pub = nh.advertise<std_msgs::String>("/my_name",100);
    }
    Name::~Name()
    {

    }

    void Name::run()
    {
        std_msgs::String name_str;
        name_str.data = "kiseok";

        name_pub.publish(name_str);
    }

}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"pub_name");

    name::Name nm;
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        nm.run();

        ros::spinOnce();
        loop_rate.sleep();
    }
}