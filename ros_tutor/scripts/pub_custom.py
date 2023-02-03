#!/usr/bin/env python

import rospy
from ros_tutor.msg import custom 


def main():
	rospy.init_node("pub_custom_msg")
	rospy.loginfo("Start custom msg publisher")
	pub = rospy.Publisher("/custom_msg",custom,queue_size=1)
	data = custom()
	while not rospy.is_shutdown():
		data.string_msg = "HI"
		data.int64_msg = -1524
		data.uint64_msg = 142
		data.float64_msg = 54.25
		data.bool_msg = True

		pub.publish(data)

if __name__ == '__main__':
	main()