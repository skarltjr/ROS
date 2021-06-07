#include <pub_subject.hpp>

namespace subject
{
    Subject::Subject()
    {
        subject_pub = nh.advertise<std_msgs::String>("/my_subject",100);
        
    }
    Subject::~Subject()
    {

    }

    void Subject::run()
    {
        std_msgs::String subject_str;
        subject_str.data = "sensor motion";

        subject_pub.publish(subject_str);
    }

}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"pub_subject");

    subject::Subject sbj;
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        sbj.run();

        ros::spinOnce();
        loop_rate.sleep();
    }
}