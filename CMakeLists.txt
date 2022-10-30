cmake_minimum_required(VERSION 3.0.2)
project(ros_tutor)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  # DEFAULT PACKAGE
  roscpp
  rospy
  std_msgs

  # START ADDING MORE BECAUSE OF CPP FILE DEPEND ON IT
  tf
  nav_msgs

  # ADD THIS FOR CUSTOM MSG
  message_generation
)

#  ADD THIS FOR CUSTOM MSG
add_message_files(
  FILES
  custom.msg
)
#  ADD THIS FOR CUSTOM MSG
generate_messages(
   DEPENDENCIES
   std_msgs  # Or other packages containing msgs
)

#  ADD THIS FOR CUSTOM MSG
catkin_package(
  CATKIN_DEPENDS message_runtime
)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


# FOR ROS PYTHON
# This makes sure the python script gets installed properly, 
# and uses the right python interpreter. 
catkin_install_python(PROGRAMS scripts/pub_string.py
                               scripts/sub_string.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)



# FOR ROS CPP COMPILE FILE 
add_executable(pub_string src/pub_string.cpp)
target_link_libraries(pub_string ${catkin_LIBRARIES})

add_executable(sub_string src/sub_string.cpp)
target_link_libraries(sub_string ${catkin_LIBRARIES})

add_executable(pub_number src/pub_number.cpp)
target_link_libraries(pub_number ${catkin_LIBRARIES})

add_executable(pub_odom src/pub_odom.cpp)
target_link_libraries(pub_odom ${catkin_LIBRARIES})

add_executable(sub_odom src/sub_odom.cpp)
target_link_libraries(sub_odom ${catkin_LIBRARIES})

add_executable(pub_custom src/pub_custom.cpp)
target_link_libraries(pub_custom ${catkin_LIBRARIES})

add_executable(sub_custom src/sub_custom.cpp)
target_link_libraries(sub_custom ${catkin_LIBRARIES})