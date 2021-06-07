cmake_minimum_required(VERSION 3.0.2)
project(calcServer)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    message_generation
)

add_service_files(
    DIRECTORY srv
    FILES
    add_two_ints.srv    
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

add_executable(calcServer
    src/calcServer.cpp
)
add_dependencies(calcServer ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(calcServer  
    ${catkin_LIBRARIES}
)
