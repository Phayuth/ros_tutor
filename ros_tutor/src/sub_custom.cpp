#include <ros/ros.h>
#include <ros_tutor/custom.h>
#include <string>


std::string intdata;
std::string uintdata;
float floatdata;
std::string booldata;

void callback_func(const ros_tutor::custom::ConstPtr& msg)
{
	
	intdata = std::to_string(msg->int64_msg);
	uintdata = std::to_string(msg->uint64_msg);
	booldata = std::to_string(msg->bool_msg);
	
	// std::cout << "Int = " << intdata << "UInt = " << uintdata << " Bool = " << booldata << std::endl;
	ROS_INFO("I Heard : %s",msg->string_msg.c_str()); // for string we have to put .c_str()
	ROS_INFO("I Heard : %f",msg->float64_msg);
	ROS_INFO("I Heard : %ld",msg->int64_msg); // because int64 is the type of long int we can not just use single %d we have to add %l for long.
	ROS_INFO("I Heard : %ld",msg->uint64_msg);
	ROS_INFO("I Heard : %d",msg->bool_msg);
}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "sub_custom");

	ros::NodeHandle node;

	ros::Subscriber sub = node.subscribe("pub_custom", 1000, callback_func);

	ros::spin();

	return 0;
}