#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

namespace my_tf_practice
{
    class MyTfPractice
    {
        public:
          MyTfPractice();
          ~MyTfPractice();

          void pubTF();

          private:
            ros::NodeHandle nh;

            ros::Time last;

            tf::TransformBroadcaster br;

            double pi;
            double angular_velocity;
            double current_theta;
            double yaw;
    };
}