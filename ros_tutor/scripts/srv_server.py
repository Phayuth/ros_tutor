#!/usr/bin/env python

import rospy 
from ros_tutor.srv import *

def srv_callback(req):
	rq_a = req.digit_1
	rq_b = req.digit_2
	rq_c = req.digit_3
	
	if rq_a == 2 and rq_b == 5 and rq_c == 5:
		return tutor_srvResponse("Accepted")
	else:
		return tutor_srvResponse("Deny")

def main():
	rospy.init_node("Service_ros")
	s = rospy.Service('password', tutor_srv, srv_callback)
	rospy.loginfo("Starting Service")

	rospy.spin()

if __name__ == "__main__":
	main()