cmake_minimum_required(VERSION 3.0.2)
project(kiseokSub)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    kiseokPub
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
    kiseokPub
)

###########
## BUILD ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(kiseokSub
    src/kiseokSub.cpp
)
add_dependencies(kiseokSub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(kiseokSub  
    ${catkin_LIBRARIES}
)
