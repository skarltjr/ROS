#include <a_pub.hpp>

namespace a_pub
{
    A_Pub::A_Pub()
    {
        intPub = nh.advertise<std_msgs::Int32>("/my_int",100);
        myPub = nh.advertise<a_pub::my_msg>("/my_msg",100);
        srand((unsigned)time(NULL));

    }
    A_Pub::~A_Pub()
    {

    }

    void A_Pub::run()
    {
        intMsg.data = makeRandInt();
        msg.float_data.data = makeRandFloat();
        msg.string_data.data = makeRandString();        

        intPub.publish(intMsg);
        myPub.publish(msg);
        std::cout <<intMsg.data << " / " <<msg.float_data.data << " / "<<msg.string_data.data << std::endl;
    }
    int A_Pub::makeRandInt()
    {
        int asd;
        asd = rand()%100;   
        return asd;
    }
    float A_Pub::makeRandFloat()
    {
        float asd;
        asd = (rand()%100)/7.0;
        return asd;
    }
    std::string A_Pub::makeRandString()
    {
        std::string asd;
        asd = "hello world";
        return asd;
    }
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"my_pub");
    a_pub::A_Pub pub;
    ros::Rate loop_rate(10);
    while(ros::ok()){
        pub.run();
        ros::spinOnce();
        loop_rate.sleep();
    }
}