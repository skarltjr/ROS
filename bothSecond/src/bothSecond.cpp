#include <bothSecond.hpp>

namespace bothSecond
{
    BothSecond::BothSecond()
    {
        pubSecond = nh.advertise<bothFirst::my_msg>("/second",100);
        subFirst = nh.subscribe<bothFirst::my_msg>("/first",100,&BothSecond::callbackPrevMsg,this);

    }
    BothSecond::~BothSecond()
    {
        
    }

    void BothSecond::callbackPrevMsg(const bothFirst::my_msg::ConstPtr &ptr)
    {
        bothFirst::my_msg msg;
        msg.rand_first.data = ptr->rand_first.data;
        msg.rand_second.data = genSecond();

        pubSecond.publish(msg);
    }

    float BothSecond::genSecond()
    {
        float result;
        result = (rand()%300)/100.0;
        return result;
    }
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"bothSecond");
    bothSecond::BothSecond bs;
    ros::spin();
}