#include <ros/ros.h>
#include "ros_tutor/my_lib.h"
int main(int argc, char **argv)
{
    ros::init(argc, argv, "test_include_library");
    ros::NodeHandle nh;
    sayHello();
}