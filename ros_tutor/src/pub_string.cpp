#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
	
	ros::init(argc, argv, "pub_string");

	ros::NodeHandle n;

	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("pub_string", 1000);

	ros::Rate loop_rate(10);

	while (ros::ok())
	{
		/**
		 * This is a message object. You stuff it with data, and then publish it.
		 */
		std_msgs::String msg;

		// std::stringstream ss;
		// ss << "hello world ";
		// msg.data = ss.str();

		msg.data = "hello world ";

		chatter_pub.publish(msg);

		ros::spinOnce();

		loop_rate.sleep();
	}


	return 0;
}