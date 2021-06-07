#include <calcClient.hpp>

namespace calcClient
{
    CalcClient::CalcClient()
    {
        client = nh.serviceClient<calcServer::add_two_ints>("calcService");
        srand((unsigned)time(NULL));
    }
    CalcClient::~CalcClient()
    {

    }

    void CalcClient::setParam(int argc,char** argv)
    {
        argc_=argc;
        argv_=argv;
    }
    void CalcClient::run()
    {
        calcServer::add_two_ints ati;
        // 기호 까지 받을것 -> 4
        if(argc_ == 4)
        {
            std::cout<<"user mode" << std::endl;
            ati.request.a = atoi(argv_[1]);
            ati.request.b = atoi(argv_[3]);
            ati.request.sign = argv_[2];

            // !!!! call    
            if(client.call(ati))
            {
                std::cout<< "request calc :"<<ati.request.a  << ati.request.sign << ati.request.b<<std::endl;
                std::cout<< "receive from server : "<<ati.response.sum <<std::endl;
            }
        }
    }
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"calcClient");
    calcClient::CalcClient calc;
    calc.setParam(argc,argv);
    calc.run();
}