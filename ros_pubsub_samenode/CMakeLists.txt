cmake_minimum_required(VERSION 3.0.2)
project(ros_pubsub_samenode)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
 INCLUDE_DIRS include
 LIBRARIES ros_pubsub_samenode
 CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)


## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/ros_pubsub_samenode.cpp
# )


## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(sub_str_pub_str_node src/sub_string_pub_string.cpp)
target_link_libraries(sub_str_pub_str_node ${catkin_LIBRARIES})

add_executable(sub_flt_pub_flt_node src/sub_float_pub_float.cpp)
target_link_libraries(sub_flt_pub_flt_node ${catkin_LIBRARIES})

add_executable(sub_flt_pub_str_node src/sub_float_pub_string.cpp)
target_link_libraries(sub_flt_pub_str_node ${catkin_LIBRARIES})
