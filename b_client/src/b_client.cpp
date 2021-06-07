#include <b_client.hpp>

namespace b_client
{
    B_Client::B_Client()
    {
        client_ = nh.serviceClient<b_server::add_two_ints>("service");
        srand((unsigned)time(NULL));
    }
    B_Client::~B_Client()
    {

    }
    void B_Client::run()
    {
        
        if(argc_ == 3)
        {
            
            srv.request.a = atoi(argv_[1]);
            srv.request.b = atoi(argv_[2]);
            if(client_.call(srv))
            {
              std::cout<< "request " <<srv.request.a << " ; "<<srv.request.b<<std::endl;
              // 서버에서 call로 받아왔으니
              std::cout << "response "<< srv.response.sum << std::endl;
            }
        }
        else
        {
            // random
            std::cout <<"hello";
        }
        

    }
    void B_Client::setParam(int argc,char** argv)
    {
        argc_ = argc;
        argv_ = argv;
    }
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"clinet");
    b_client::B_Client client;
    client.setParam(argc,argv);
    client.run();
}