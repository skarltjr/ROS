#include <bothFirst.hpp>

namespace bothFirst
{
    BothFirst::BothFirst()
    {
        pubFirst = nh.advertise<bothFirst::my_msg>("/first",100);
        srand((unsigned)time(NULL));
    }
    BothFirst::~BothFirst()
    {

    }

    void BothFirst::run()
    {
        bothFirst::my_msg msg;
        msg.rand_first.data = genFirst();

        pubFirst.publish(msg);
    }
    float BothFirst::genFirst()
    {
        float result;
        result = (rand()%100)/100.0;
        return result;
    }

}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"pubFirst");
    bothFirst::BothFirst bf;

    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        bf.run();
        ros::spinOnce();
        loop_rate.sleep();
    }
}