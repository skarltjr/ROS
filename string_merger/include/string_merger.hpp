#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>

namespace string_merger
{
    class StringMerger
    {
        public:
            StringMerger();
            ~StringMerger();

            void callbackMajor(const std_msgs::String::ConstPtr &ptr);
            void callbackSubject(const std_msgs::String::ConstPtr &ptr);
            void callbackDepartmentNumber(const std_msgs::String::ConstPtr &ptr);
            void callbackName(const std_msgs::String::ConstPtr &ptr);
            
            void run();

        private:

            ros::NodeHandle nh;
            ros::Publisher pub_merge;
            ros::Subscriber sub_major;
            ros::Subscriber sub_department_number;
            ros::Subscriber sub_name;
            ros::Subscriber sub_subject;

            std::string department_number;
            std::string major;
            std::string name;
            std::string subject;

            bool major_ok_;
            bool subject_ok_;
            bool department_number_ok_;
            bool name_ok_;
    };
}