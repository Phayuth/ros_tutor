#!/usr/bin/env python

import rospy
import tf
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3


def callback_func(msg):
	x = msg.pose.pose.position.x
	y = msg.pose.pose.position.y
	z = msg.pose.pose.position.z
	rospy.loginfo("I heard : x = %f , y = %f , z = %f"%(x,y,z))

def main():
	rospy.init_node('sub_odom')
	odom_pub = rospy.Subscriber("/odom", Odometry, callback_func)
	rospy.loginfo("Starting Odometry Subscriber")
	rospy.spin()

if __name__ == '__main__':
	main()