#!/usr/bin/env python

import rospy
from ros_tutor.msg import custom

def callback_func(msg):
	st = msg.string_msg
	it = msg.int64_msg
	ut = msg.uint64_msg
	fl = msg.float64_msg
	bl = msg.bool_msg
	rospy.loginfo("I get data : %s , %d , %d, %f , %s"%(st,it,ut,fl,bl))


def main():
	rospy.init_node("sub_custom_msg")
	rospy.loginfo("Start subscribing to custom msg")
	rospy.Subscriber("/custom_msg",custom,callback_func)
	rospy.spin()

if __name__ == '__main__':
	main()