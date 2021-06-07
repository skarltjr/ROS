cmake_minimum_required(VERSION 3.0.2)
project(a_sub)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    a_pub
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
    a_pub
)

###########
## BUILD ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(a_sub
    src/a_sub.cpp
)
add_dependencies(a_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(a_sub  
    ${catkin_LIBRARIES}
)
