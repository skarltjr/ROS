#include "ros/ros.h"
#include <cstdlib>
#include <ctime>
#include <b_server/add_two_ints.h>

namespace b_client
{
    class B_Client
    {
        public:
            B_Client();
            ~B_Client();

            void run();
            void setParam(int argc,char** argv);
        private:
            ros::NodeHandle nh;
            ros::ServiceClient client_;
            int argc_;
            char** argv_;
            b_server::add_two_ints srv;

    };
}