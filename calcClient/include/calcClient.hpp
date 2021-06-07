#include "ros/ros.h"
#include <cstdlib>
#include <ctime>
#include <calcServer/add_two_ints.h>

namespace calcClient
{
    class CalcClient 
    {
        public: 
            CalcClient();
            ~CalcClient();
            
            // 클라이언트가 요청보내고 응답을 받아서 run
            void run();
            void setParam(int argc,char** argv);

        private:
        ros::NodeHandle nh;
        ros::ServiceClient client;

        int argc_;
        char** argv_;
    };

}