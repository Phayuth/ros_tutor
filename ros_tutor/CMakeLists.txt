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

  # # ADD THIS FOR IMPORT OUR LIBRARY
  # ros_tutor
)

#  ADD THIS FOR CUSTOM MSG --------------------------------------------------
add_message_files(
  FILES
  custom.msg
)
#----------------------------------------------------------------------------


#  ADD THIS FOR SERVICE MSG -------------------------------------------------
add_service_files(
  FILES
  tutor_srv.srv
  )
#----------------------------------------------------------------------------


#  ADD THIS FOR CUSTOM MSG --------------------------------------------------
generate_messages(
   DEPENDENCIES
   std_msgs  # Or other packages containing msgs
)
#----------------------------------------------------------------------------


#  ADD message_runtime FOR CUSTOM MSG ---------------------------------------
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS message_runtime roscpp
)
#----------------------------------------------------------------------------


## Specify additional locations of header files -----------------------------
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
#----------------------------------------------------------------------------


# Adding library source files for later used of header file -----------------
# in include folder of the project 
add_library(${PROJECT_NAME}_my_lib src/libsrc/my_lib.cpp)
target_link_libraries(${PROJECT_NAME}_my_lib ${catkin_LIBRARIES})
#----------------------------------------------------------------------------


# install(
#   TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )
# install(
#   DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
# )
# for installing our library for other package but now there are
# some bug to fix
#----------------------------------------------------------------------------


# FOR ROS PYTHON ------------------------------------------------------------
# This makes sure the python script gets installed properly, 
# and uses the right python interpreter. 
catkin_install_python(PROGRAMS scripts/pub_string.py
                               scripts/sub_string.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
#----------------------------------------------------------------------------


# FOR USING OUR LIBRARY -----------------------------------------------------
# from compiled file of library we will get exe name (${PROJECT_NAME}_my_lib)
# to use the library we compiled exe with its own source file and library file
# then we link the newly created exe to all library exe such as catkin and ${PROJECT_NAME}_my_lib
add_executable(apply_lib_${PROJECT_NAME} src/apply_lib.cpp src/libsrc/my_lib.cpp)
target_link_libraries(apply_lib_${PROJECT_NAME} ${catkin_LIBRARIES} ${PROJECT_NAME}_my_lib)
#----------------------------------------------------------------------------


# FOR ROS CPP COMPILE FILE --------------------------------------------------
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

add_executable(param src/param.cpp)
target_link_libraries(param ${catkin_LIBRARIES})
#-----------------------------------------------------------------------------


# FOR CPP with CUSTOM MSG and SRV --------------------------------------------
# In this section, CPP file need the MSG and SRV file to compile first. 
# If we compile at the same time for the first time it give error.
# To work around comment these out first, then compile , then uncomment , then compile.
# https://answers.ros.org/question/73048/first-compile-with-messages-messages-not-found/
# to make sure the msg and srv is compile first,
# which is the reason we use : 
# add_dependencies({name_of_exe} {name_of_package}_generate_messages_cpp) at follow. finally, I know why.

add_executable(pub_custom src/pub_custom.cpp)
target_link_libraries(pub_custom ${catkin_LIBRARIES})
add_dependencies(pub_custom ros_tutor_generate_messages_cpp)

add_executable(sub_custom src/sub_custom.cpp)
target_link_libraries(sub_custom ${catkin_LIBRARIES})
add_dependencies(sub_custom ros_tutor_generate_messages_cpp)

add_executable(srv_server src/srv_server.cpp)
target_link_libraries(srv_server ${catkin_LIBRARIES})
add_dependencies(srv_server ros_tutor_generate_messages_cpp)

add_executable(srv_client src/srv_client.cpp)
target_link_libraries(srv_client ${catkin_LIBRARIES})
add_dependencies(srv_client ros_tutor_generate_messages_cpp)
#------------------------------------------------------------------------------