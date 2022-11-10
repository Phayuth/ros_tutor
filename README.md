# ROS Tutorial Package 2
Additional ROS Package continuation from ros_tutor for more function such as action, ros_control, urdf, simulation, tf transform for intermediate to advance.[For Mom!]

### ROS Action
Create Package with Dependency
```
catkin_create_pkg actionlib_tutorials actionlib message_generation roscpp rospy std_msgs actionlib_msgs
```

### URDF
Necessary Command
```
check_urdf file.urdf
urdf_to_graphiz file.urdf
```

### References
- action_lib
  - http://wiki.ros.org/actionlib
  - http://wiki.ros.org/actionlib_tutorials
  - https://github.com/ros/common_tutorials
  - https://github.com/MariaC27/actionlib_grab
- ros_control
  - http://wiki.ros.org/ros_control
  - https://github.com/ros-controls/ros_control
  - https://roboticscasual.com/ros-tutorial-control-the-ur5-robot-with-ros_control-tuning-a-pid-controller/
  - https://github.com/jimohafeezco/manipulator
