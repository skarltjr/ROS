#include <a_second.hpp>

namespace a_second
{
    A_Second::A_Second()
    {
        pub = nh.advertise<a_first::my_msg>("/second",100);
        sub = nh.subscribe<a_first::my_msg>("/first",100,&A_Second::callbackPrev,this);
    }
    A_Second::~A_Second()
    {

    }
    void A_Second::callbackPrev(const a_first::my_msg::ConstPtr &ptr)
    {
        msg.rand_first.data = ptr->rand_first.data;
        msg.rand_second.data = genFloat();
        pub.publish(msg);   
    }
    float A_Second::genFloat()
    {
        float asd;
        asd = (rand()%100)/5.0;
        return asd;
    }
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"second");
    a_second::A_Second sec;
    ros::spin();
}