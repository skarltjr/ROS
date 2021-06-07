#include "ros/ros.h"
#include "b_server/add_two_ints.h"

namespace b_server
{
    class B_Server
    {
        public:
            B_Server();
            ~B_Server();

            bool callbackMethod(b_server::add_two_ints::Request &req,
            b_server::add_two_ints::Response &res);
        private:
            ros::NodeHandle nh;
            ros::ServiceServer server;
    };
}