#include <a_sub.hpp>

namespace a_sub
{
    A_Sub::A_Sub()
    {
        intSub = nh.subscribe("/my_int",100,&A_Sub::callbackInt,this);
        msgSub = nh.subscribe("/my_msg",100,&A_Sub::callbackMsg,this);
    }
    A_Sub::~A_Sub()
    {

    }
    void A_Sub::callbackInt(const std_msgs::Int32::ConstPtr &ptr)
    {
        std::cout<<"int data = "<<ptr->data<<std::endl;
    }
    void A_Sub::callbackMsg(const a_pub::my_msg::ConstPtr &ptr)
    {
        std::cout<<"float data = "<<ptr->float_data.data<<" , string data = "<<ptr->string_data.data<<std::endl;
    }
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"my_sub");
    a_sub::A_Sub sub;
    ros::spin();
}