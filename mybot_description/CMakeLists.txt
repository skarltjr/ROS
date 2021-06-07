cmake_minimum_required(VERSION 3.0.2)
project(mybot_description)

# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    rospy
    urdf
)

catkin_package(
    CATKIN_DEPENDS  
    roscpp
    rospy
    urdf
)

###########
## BUILD ##
###########

include_directories(
    #include
    ${catkin_INCLUDE_DIRS}
)