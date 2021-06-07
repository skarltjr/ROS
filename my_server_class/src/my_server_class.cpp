#include <my_server_class.hpp>

namespace my_server_class
{

    MyServerClass::MyServerClass()
    {
        service_=nh.advertiseService("my_class_service",&MyServerClass::callbackAdd,this);
    }
    MyServerClass::~MyServerClass()
    {

    }


    bool MyServerClass::callbackAdd(my_server_class::add_two_ints::Request &req,my_server_class::add_two_ints::Response &res)
    {
         res.sum = req.a + req.b;
        std::cout<<"request : " << req.a << " , " <<req.b << std::endl;
        std::cout<< "send   : " << res.sum <<std::endl;

        ROS_INFO("request :x=&d, y=&d",req.a,req.b);
        ROS_INFO("sending back reponse : [&d]",res.sum);
        return true;
    }
}






int main(int argc,char **argv)
{
    ros::init(argc,argv,"my_server");
    my_server_class::MyServerClass MSC;
   
    ros::spin();
}