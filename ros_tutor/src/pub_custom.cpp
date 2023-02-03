#include <ros/ros.h>
#include <ros_tutor/custom.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "pub_custom");

	ros::NodeHandle n;

	ros::Publisher pub = n.advertise<ros_tutor::custom>("pub_custom" , 1000);

	ros::Rate loop_rate(100);

	ROS_INFO("Starting Publisher Custom MSG");

	while (ros::ok())
	{
		ros_tutor::custom data;

		data.string_msg = "stringing";
		data.int64_msg = -323;
		data.uint64_msg = 23;
		data.float64_msg = -25.52;
		data.bool_msg = true;

		pub.publish(data);

		ros::spinOnce();

		loop_rate.sleep();
	}
}