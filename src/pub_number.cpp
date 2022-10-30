#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "pub_number");

	ros::NodeHandle n;

	ros::Publisher chatter_pub = n.advertise<std_msgs::Float64>("pub_number", 1000);

	ros::Rate loop_rate(100);

	while (ros::ok())
	{
		std_msgs::Float64 msg;

		msg.data = 1006;

		chatter_pub.publish(msg);

		ros::spinOnce();

		loop_rate.sleep();
	}
}