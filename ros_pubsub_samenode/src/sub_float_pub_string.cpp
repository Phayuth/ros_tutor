#include <ros/ros.h>
#include <ros_pubsub_samenode/pubsub_samenode.h>
#include <std_msgs/String.h>
#include <std_msgs/Float64.h>

template<>
void PublisherSubscriber<std_msgs::String, std_msgs::Float64>::subscriberCallback(const std_msgs::Float64::ConstPtr& recievedMsg)
{
	std_msgs::String echo_msg;

	if ((recievedMsg->data)>0)
	{
		echo_msg.data = "The number is bigger than 0";
		publisherObject.publish(echo_msg);
	}
	else if ((recievedMsg->data)<0)
	{
		echo_msg.data = "The number is smaller than 0";
		publisherObject.publish(echo_msg);
	}
	else{
		echo_msg.data = "The number is  0";
		publisherObject.publish(echo_msg);
	}
	
}

int main(int argc, char **argv)
{
	ros::init (argc,argv,"pubsubsamenode");
	ROS_INFO("Starting -------");
	PublisherSubscriber<std_msgs::String, std_msgs::Float64> whatevername("echo", "chatter",1);
	ros::spin();
}