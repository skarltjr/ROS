#include <b_server.hpp>

namespace b_server
{
    B_Server::B_Server()
    {
        server = nh.advertiseService("/service",&B_Server::callbackMethod,this);
    }
    B_Server::~B_Server()
    {

    }
    bool B_Server::callbackMethod(b_server::add_two_ints::Request &req,
            b_server::add_two_ints::Response &res)
    {
        res.sum = req.a+req.b;
        return true;
    }
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"server");
    b_server::B_Server server;
    ros::spin();
}
