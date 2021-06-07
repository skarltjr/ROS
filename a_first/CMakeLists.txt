cmake_minimum_required(VERSION 3.0.2)
project(a_first)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    message_generation
)

add_message_files(
    DIRECTORY msg
    FILES
    my_msg.msg
)

generate_messages(
    DEPENDENCIES
    std_msgs
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
)

###########
## BUILD ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(a_first
    src/a_first.cpp
)
add_dependencies(a_first ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(a_first  
    ${catkin_LIBRARIES}
)
