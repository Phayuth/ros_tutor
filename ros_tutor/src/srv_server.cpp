#include "ros/ros.h"
#include "ros_tutor/tutor_srv.h"
#include <string>

bool srv_callback(ros_tutor::tutor_srv::Request  &req,
				  ros_tutor::tutor_srv::Response &res )
{
	// int result = req.digit_1 + req.digit_2 + req.digit_3;
	// res.status = std::to_string(result);
	// std::cout << result << std::endl;

	if (req.digit_1 == 2 and req.digit_2 == 5 and req.digit_3 == 5)
	{
		res.status = "Accepted";
	}
	else{
		res.status = "Deny";
	}
	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Service_ros");
	ros::NodeHandle n;

	ros::ServiceServer service = n.advertiseService("password", srv_callback);

	ros::spin();

	return 0;
}
