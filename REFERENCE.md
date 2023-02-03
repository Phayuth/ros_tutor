# Installation
create catkin_ws on home directory
```
$ mkdir -p ws_catkin/src 
$ cd ws_catkin
$ catkin_make
$ echo "source ~/ws_catkin/devel/setup.bash" >> ~/.bashrc
```

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


# Reference Link
### action_lib
- http://wiki.ros.org/actionlib_tutorials
- https://github.com/ros/common_tutorials
- https://github.com/MariaC27/actionlib_grab

### ros_control
- http://wiki.ros.org/ros_control
- https://github.com/jimohafeezco/manipulator

### Publisher and Subscriber in the same node 
- https://www.youtube.com/watch?v=lR3cK9ZoAF8

### UR5 control using ros_control
- https://roboticscasual.com/ros-tutorial-control-the-ur5-robot-with-ros_control-tuning-a-pid-controller/
- https://github.com/ros-simulation/gazebo_ros_demos

### Calculate Inertia
- https://www.omnicalculator.com/physics/mass-moment-of-inertia
- https://amesweb.info/inertia/mass-moment-of-inertia-calculator.aspx

### Add Library and Header file
- https://roboticsbackend.com/ros-include-cpp-header-from-another-package/

### Why we have to use add_dependencies
- https://answers.ros.org/question/73048/first-compile-with-messages-messages-not-found/

### ROS Tip
- https://sites.google.com/view/phayuth-robotics/ros

### ROS Tutorial Official
- https://github.com/ros/ros_tutorials
- http://wiki.ros.org/ROS/Tutorials

### ROBOTIS Tutorial
- https://github.com/ROBOTIS-GIT/ros_tutorials

### ROS Note
- https://github.com/Fasermaler/coding-notes-1/tree/master/Robot%20Operating%20System%20(ROS)