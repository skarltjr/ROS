cmake_minimum_required(VERSION 3.0.2)
project(a_controller)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    geometry_msgs
    a_first
)
catkin_package(
    CATKIN_DEPENDS
    roscpp
    a_first
)

###########
## BUILD ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(a_controller
    src/a_controller.cpp
)
add_dependencies(a_controller ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(a_controller  
    ${catkin_LIBRARIES}
)
