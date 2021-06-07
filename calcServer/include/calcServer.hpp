#include "ros/ros.h"
#include "calcServer/add_two_ints.h"

namespace calcServer
{
    class CalcServer
    {
        public:
            CalcServer();
            ~CalcServer();

            bool callbackAdd(calcServer::add_two_ints::Request &req, calcServer::add_two_ints::Response &res);

        private:

            ros::NodeHandle nh;

            ros::ServiceServer service;
    };
}