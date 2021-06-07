cmake_minimum_required(VERSION 3.0.2)
project(calcClient)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    calcServer
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

add_executable(calcClient
    src/calcClient.cpp
)
add_dependencies(calcClient ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(calcClient  
    ${catkin_LIBRARIES}
)
