#include <a_first.hpp>


namespace a_first
{
    A_First::A_First()
    {
        pub = nh.advertise<a_first::my_msg>("/first",100);
        srand((unsigned)time(NULL));
    }
    A_First::~A_First()
    {

    }
    void A_First::run()
    {
        msg.rand_first.data = genFloat();
        pub.publish(msg);
    }
    float A_First::genFloat()
    {
        float asd;
        asd = (rand()%100)/3.0;
        return asd;
    }
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"first");
    a_first::A_First first;
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        first.run();
        ros::spinOnce();
        loop_rate.sleep();
    }
}