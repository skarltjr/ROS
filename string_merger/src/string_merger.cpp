#include <string_merger.hpp>

namespace string_merger
{
    StringMerger::StringMerger()
    {
        pub_merge = nh.advertise<std_msgs::String>("/my_infomation",100);

        sub_department_number = nh.subscribe("/my_department_number",1,&StringMerger::callbackDepartmentNumber,this);
        sub_name = nh.subscribe("/my_name",1,&StringMerger::callbackName,this);
        sub_major = nh.subscribe("/my_major",1,&StringMerger::callbackMajor,this);
        sub_subject = nh.subscribe("/my_subject",1,&StringMerger::callbackSubject,this);

        major_ok_ = false;
        subject_ok_ = false;
        department_number_ok_ = false;
        name_ok_ = false;
    }

    StringMerger::~StringMerger()
    {   

    }

    void StringMerger::callbackDepartmentNumber(const std_msgs::String::ConstPtr &ptr)
    {
        department_number = ptr->data;  
        department_number_ok_ = true;
    }

    void StringMerger::callbackMajor(const std_msgs::String::ConstPtr &ptr)
    {
        major=ptr->data;
        major_ok_ = true;
    }

    void StringMerger::callbackName(const std_msgs::String::ConstPtr &ptr)
    {
        name=ptr->data;
        name_ok_ = true;
    }

    void StringMerger::callbackSubject(const std_msgs::String::ConstPtr &ptr)
    {
        subject=ptr->data;
        subject_ok_ = true;
    }

    void StringMerger::run()
    {
        if( !(department_number_ok_ && major_ok_ && name_ok_ && subject_ok_) ) return;

        std_msgs::String merge;
        merge.data = major+ " / "+subject+" / "+department_number+" / "+name;
        pub_merge.publish(merge);
        std::cout<<merge.data<<std::endl;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "string_merger");

    string_merger::StringMerger SM;

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        SM.run();
        ros::spinOnce();
        loop_rate.sleep();
    }
}