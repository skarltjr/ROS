#include <calc_base2end_tf.hpp>

namespace calc_base2end_TF
{
    CalcBase2endTF::CalcBase2endTF()
    {
        joint_state_sub_ = nh.subscribe("/joint_states",1 , &CalcBase2endTF::callbackJointStates, this);
    }

    CalcBase2endTF::~CalcBase2endTF()
    {

    }

    void CalcBase2endTF::callbackJointStates(const sensor_msgs::JointState::ConstPtr &ptr)
    {
        Eigen::Matrix4d final_mat;
        final_mat << 1, 0, 0, 0,
                     0, 1, 0, 0,
                     0, 0, 1, 0,
                     0, 0, 0, 1;


        // get vector value hint
        for(size_t i = 0; i < ptr->position.size(); ++i)
        {
            joint_angle[i] = ptr->position[i]; // 갑ㅄ 받고
            std::cout << ptr->position[i] << std::endl; // compare rostopic echo /joint_states
        }
       // todo  final mat에 6-1번의 r을 구해서 곱해줘서 0frame 좌표계 구하기
        for(int i=0;i<6;i++)
        {   
            Eigen::Matrix4d result = RotZ(joint_angle[i]) * TransZ(d_dh[i]) * TransX(a_dh[i]) * RotX(alpha_dh[i]);
            final_mat = final_mat * result;
        }

        
        std::cout << "-------- Homogenous Matrix from base to end-effector using D-H parameters ---------" << std::endl;
        std::cout << final_mat << std::endl;

        std::cout << "-------- validation ---------" << std::endl;
        Eigen::Vector4d end_effector_origin(0, 0, 0, 1);
        Eigen::Vector4d transformed_origin_on_base;

        transformed_origin_on_base = final_mat * end_effector_origin;

        double x = transformed_origin_on_base[0];
        double y = transformed_origin_on_base[1];
        double z = transformed_origin_on_base[2];

        std::cout << "calc [ x, y, z ] : [ " << x << ", " << y << ", " << z << " ]" << std::endl; 
        // compare tool0 TF

    }

    double deg2rad(double degree)
    {
        return degree/180.0 * 3.141592;
    }


    Eigen::Matrix4d CalcBase2endTF::RotZ(double rad)
    {
        Eigen::Matrix4d mat;
        mat << cos(rad), -sin(rad), 0, 0,
               sin(rad),  cos(rad), 0, 0,
                0,          0,       1, 0,
                0,          0,       0, 1;
    
          return mat;
    }

    Eigen::Matrix4d CalcBase2endTF::TransZ(double d)
    {
        Eigen::Matrix4d mat;
      mat << 1, 0, 0, 0,
           0, 1, 0, 0,
           0, 0, 1, d,
           0, 0, 0, 1;
    
        return mat;
    }

    Eigen::Matrix4d CalcBase2endTF::TransX(double a)
    {
        Eigen::Matrix4d mat;
     mat <<1, 0, 0, a,
           0, 1, 0, 0,
           0, 0, 1, 0,
           0, 0, 0, 1;
    
        return mat;
    }

    Eigen::Matrix4d CalcBase2endTF::RotX(double rad)
    {
       Eigen::Matrix4d mat;
       mat <<1, 0, 0, 0,
             0, cos(rad), -sin(rad), 0,
             0, sin(rad), cos(rad), 0,
             0, 0, 0, 1;
    
        return mat;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "calc_base2end_TF");

    calc_base2end_TF::CalcBase2endTF CBT;

    ros::spin();
}