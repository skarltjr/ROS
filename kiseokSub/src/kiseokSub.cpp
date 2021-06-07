#include <kiseokSub.hpp>


namespace kiseokSub
{
    KiseokSub::KiseokSub()
    {
        subInt = nh.subscribe("/my_first_topic",100,&KiseokSub::callbackRandInt,this);
        subMymsg = nh.subscribe("/my_first_msg",100,&KiseokSub::callbackClassMsg,this);
    
    }
    KiseokSub::~KiseokSub()
    {

    }

    void KiseokSub::callbackRandInt(const std_msgs::Int32::ConstPtr &msg)
    {
        std::cout<<"kiseokSub node subs" << msg->data <<std::endl;
    
    }
    void KiseokSub::callbackClassMsg(const kiseokPub::my_msg::ConstPtr &msg)
    {
        std::cout <<"kiseokSub node subs" << msg->float_data.data << " , "<<msg->string_data.data << std::endl;
    }

}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"kiseokSub");
    kiseokSub::KiseokSub ksub;
    ros::spin();
}