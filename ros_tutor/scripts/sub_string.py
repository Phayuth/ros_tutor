#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def callback_func(msg):
	data = msg.data
	rospy.loginfo("I get data : " + data)

def main():
	rospy.loginfo("Starting String Subscriber")
	rospy.init_node("sub_string")
	rospy.Subscriber("/pub_string",String,callback_func)
	rospy.spin()

if __name__ == '__main__':
	main()