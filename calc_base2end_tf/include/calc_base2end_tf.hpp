#include <ros/ros.h>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <sensor_msgs/JointState.h>
//todo  -> rostopic type /joint_states
// position이 6개 즉 6개의 조인트에 대한 조인트 앵글 사용 

#define N_Joint 6
                                        
static constexpr double a_dh[N_Joint] = {0.00000, -0.42500, -0.39225, 0.00000, 0.00000, 0.00000};
static constexpr double d_dh[N_Joint] = {0.089159, 0.00000, 0.00000, 0.10915, 0.09465, 0.0823};
static constexpr double alpha_dh[N_Joint] = {1.570796327, 0, 0, 1.570796327, -1.570796327, 0};
static double joint_angle[N_Joint] = {0,0,0,0,0,0}; // 조인트앵글 6개 받기
namespace calc_base2end_TF
{
    class CalcBase2endTF
    {
        public:
            CalcBase2endTF();
            ~CalcBase2endTF();

            Eigen::Matrix4d RotZ(double rad);
            Eigen::Matrix4d TransZ(double d);
            Eigen::Matrix4d TransX(double a);
            Eigen::Matrix4d RotX(double rad);

            void callbackJointStates(const sensor_msgs::JointState::ConstPtr &ptr);

        private:
            ros::NodeHandle nh;
            
            ros::Subscriber joint_state_sub_;

    };
}