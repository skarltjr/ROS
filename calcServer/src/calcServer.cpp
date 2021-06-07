#include <calcServer.hpp>

namespace calcServer
{
    CalcServer::CalcServer()
    {
        service = nh.advertiseService("calcService", &CalcServer::callbackAdd,this);
    
    }
    CalcServer::~CalcServer()
    {

    }
   bool CalcServer::callbackAdd(calcServer::add_two_ints::Request &req, calcServer::add_two_ints::Response &res)
   {
       if(req.sign == "+")
       {
           res.sum = req.a+req.b;
           std::cout<< "request : "<<req.a << " , "<<req.b << std::endl;
           std::cout<<"send : "<<res.sum << std::endl;

           ROS_INFO("request :x=%d, y=%d",req.a,req.b);
           ROS_INFO("sending back response : [%d}",res.sum);
           return true;
       }else if(req.sign =="-")
       {
            res.sum = req.a-req.b;
           std::cout<< "request : "<<req.a << " , "<<req.b << std::endl;
           std::cout<<"send : "<<res.sum << std::endl;

           ROS_INFO("request :x=%d, y=%d",req.a,req.b);
           ROS_INFO("sending back response : [%d}",res.sum);
           return true;

       }else if(req.sign == "/")
       {
            res.sum = (float)req.a/req.b;
           std::cout<< "request : "<<req.a << " , "<<req.b << std::endl;
           std::cout<<"send : "<<res.sum << std::endl;

           ROS_INFO("request :x=%d, y=%d",req.a,req.b);
           ROS_INFO("sending back response : [%d}",res.sum);
           return true;

       }else if(req.sign == "x")
       {
            res.sum = req.a*req.b;
           std::cout<< "request : "<<req.a << " , "<<req.b << std::endl;
           std::cout<<"send : "<<res.sum << std::endl;
           std::cout<< "qweqwe" << req.sign << std::endl;

           ROS_INFO("request :x=%d, y=%d",req.a,req.b);
           ROS_INFO("sending back response : [%d}",res.sum);
           return true;
       }
       return false;
   }

}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"calcServer");
    calcServer::CalcServer calc;
    ros::spin();
}