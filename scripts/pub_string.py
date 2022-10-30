#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def main():
	rospy.init_node("pub_string")
	pub_string = rospy.Publisher("/pub_string",String,queue_size=1)
	data = String()
	rate = rospy.Rate(10)
	rospy.loginfo("Starting String Publisher")
	while not rospy.is_shutdown():
		data.data = "Hi"
		pub_string.publish(data)
		rate.sleep()

if __name__ == '__main__':
	main()