#include <kiseokPub.hpp>

namespace kiseokPub
{
    KiseokPub::KiseokPub() :private_nh("~")
    {
        if(!private_nh.getParam("/kiseokPub/param_int",param_int)) throw std::runtime_error("fail to get int paraam");
        if(!private_nh.getParam("/kiseokPub/param_float",param_float)) throw std::runtime_error("fail to get float paraam");
        if(!private_nh.getParam("/kiseokPub/param_string",param_string)) throw std::runtime_error("fail to get string paraam");
        
        //아래는 동일 위에는 파라미터쓸 때만 
        intPub = nh.advertise<std_msgs::Int32>("/my_first_topic",100);
        msgPub = nh.advertise<kiseokPub::my_msg>("/my_first_msg",100);

        srand((unsigned)time(NULL));
    }
    KiseokPub::~KiseokPub()
    {

    }

    void KiseokPub::run()
    {
        // intData.data = makeRandInt();
        // my_msg.float_data.data = makeRandFloat();
        // my_msg.string_data.data = makeString();
        
        // 파라미터 사용할 땐 
        intData.data = param_int;
        my_msg.float_data.data = param_float;
        my_msg.string_data.data = param_string;

        // 여기부터는 동일
        intPub.publish(intData);
        msgPub.publish(my_msg);

        std::cout<< " my publisher node pub [" << intData.data << "] and ["
        <<my_msg.float_data.data << " , " << my_msg.string_data.data << " ] "<<std::endl;

    }

    int KiseokPub::makeRandInt()
    {
        int randomInt;
        randomInt = rand()% 100;
        return randomInt;
    }
    float KiseokPub::makeRandFloat()
    {
        float randFloat;
        randFloat = (rand()%100)/7.0;
        return randFloat;
    }
    std::string KiseokPub::makeString()
    {
        std::string str;
        str = "hello hello hello";
        return str;
    }

}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"kiseokPub");
    kiseokPub::KiseokPub kpub;
    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        kpub.run();
        ros::spinOnce();
        loop_rate.sleep();
    }
}