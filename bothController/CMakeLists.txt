cmake_minimum_required(VERSION 3.0.2)
project(bothController)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    geometry_msgs
    bothFirst
)
catkin_package(
    CATKIN_DEPENDS
    roscpp
    bothFirst
)

###########
## BUILD ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(bothController
    src/bothController.cpp
)
add_dependencies(bothController ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(bothController  
    ${catkin_LIBRARIES}
)
