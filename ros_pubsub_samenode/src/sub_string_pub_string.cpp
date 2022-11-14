#include <ros/ros.h>
#include <ros_pubsub_samenode/pubsub_samenode.h>
#include <std_msgs/String.h>

template<>
void PublisherSubscriber<std_msgs::String, std_msgs::String>::subscriberCallback(const std_msgs::String::ConstPtr& recievedMsg)
{
	ROS_INFO("I get : %s", recievedMsg->data.c_str());
	ROS_INFO("I send the recv msg to topic name 'echo'");
	std_msgs::String echo_msg;
	echo_msg.data = recievedMsg->data;
	publisherObject.publish(echo_msg);
}

int main(int argc, char **argv)
{
	ros::init (argc,argv,"pubsubsamenode");
	PublisherSubscriber<std_msgs::String, std_msgs::String> whatevername("echo", "chatter",1);
	ros::spin();
}