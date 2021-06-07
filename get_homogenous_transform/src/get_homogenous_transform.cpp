#include <ros/ros.h>
#include <iostream>
#include <eigen3/Eigen/Dense>

#define PI 3.141592

Eigen::Matrix4d RotZ(double rad)
{
    Eigen::Matrix4d mat;
    mat << cos(rad), -sin(rad), 0, 0,
           sin(rad),  cos(rad), 0, 0,
           0,          0,       1, 0,
           0,          0,       0, 1;
    
    return mat;
}

Eigen::Matrix4d TransZ(double d)
{
    Eigen::Matrix4d mat;
    mat << 1, 0, 0, 0,
           0, 1, 0, 0,
           0, 0, 1, d,
           0, 0, 0, 1;
    
    return mat;
    
}

Eigen::Matrix4d TransX(double a)
{
     Eigen::Matrix4d mat;
     mat <<1, 0, 0, a,
           0, 1, 0, 0,
           0, 0, 1, 0,
           0, 0, 0, 1;
    
    return mat;
}
Eigen::Matrix4d RotX(double rad)
{
     Eigen::Matrix4d mat;
     mat <<1, 0, 0, 0,
           0, cos(rad), -sin(rad), 0,
           0, sin(rad), cos(rad), 0,
           0, 0, 0, 1;
    
    return mat;
}

double deg2rad(double degree)
{
    return degree/180.0 * PI;
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"get_homogenous_transform");
    ros::NodeHandle nh;

    double theta_degree = 60.0;
    double theta_radian = deg2rad(theta_degree);

    double alpha_degree = 90.0;
    double alpha_radian = deg2rad(alpha_degree);

    Eigen::Matrix4d result = RotZ(theta_radian) * TransZ(1) * TransX(0) * RotX(alpha_radian);

    std::cout << result << std::endl;

    Eigen::Vector4d p(0,0,0,1); // x,y,z,1
    Eigen::Vector4d transformed_p;
    Eigen::Vector4d transformed_p2;

    transformed_p = result * p; // 부모좌표계를 기준으로 자식좌표계가 어디에 위치하는가 
    transformed_p2 = result.inverse() * p; // 반대 

    std::cout << "child link tf origin's position on parent link tf" << std::endl;
    std::cout << "x : " << transformed_p[0] << std::endl;  //0
    std::cout << "y : " << transformed_p[1] << std::endl;  //0
    std::cout << "z : " << transformed_p[2] << std::endl;  //1 이 나오는데 부모기준으로 자식좌표계는 z축에서 1떨어진 위치에 위치

    std::cout << "parent link tf origin's position on child link tf" << std::endl;
    std::cout <<" x : " << transformed_p2[0] << std::endl;  //반대로 자식기준에서 부모가 어디에위치하는지
    std::cout <<" y : " << transformed_p2[1] << std::endl;  // y = -1 이 나오는데 즉 자식좌표계의 원점에서 자식좌표계y축에서 -1에 부모좌표계의 원점이 위치 
    std::cout <<" z : " << transformed_p2[2] << std::endl;

}