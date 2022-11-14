#include <ros/ros.h>
#include <ros_pubsub_samenode/pubsub_samenode.h>
#include <std_msgs/Float64.h>

template<>
void PublisherSubscriber<std_msgs::Float64, std_msgs::Float64>::subscriberCallback(const std_msgs::Float64::ConstPtr& recievedMsg)
{
	ROS_INFO("I get : %f", recievedMsg->data);
	ROS_INFO("I send the recv msg to topic name 'echo'");
	std_msgs::Float64 echo_msg;
	echo_msg.data = recievedMsg->data;
	publisherObject.publish(echo_msg);
}

int main(int argc, char **argv)
{
	ros::init (argc,argv,"pubsubsamenode");
	PublisherSubscriber<std_msgs::Float64, std_msgs::Float64> whatevername("pub_topicname", "sub_topicname",1);
	ros::spin();
}