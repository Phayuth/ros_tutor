#include <ros/ros.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "parameters");
	ros::NodeHandle n;

	n.setParam("set_param", "hello there");

	std::string s;
	if (n.getParam("param_1", s))
	{
		ROS_INFO("Got param: %s", s.c_str());
	}
	else
	{
		ROS_ERROR("Failed to get param 'param_1'");
	}
	
}