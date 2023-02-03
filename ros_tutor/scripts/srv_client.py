#!/usr/bin/env python

import sys
import os
import rospy
from ros_tutor.srv import *


def call_client(x, y, z):

	rospy.wait_for_service('password')
	
	try:
		srv = rospy.ServiceProxy('password', tutor_srv)

		# simplified style
		resp1 = srv(x, y, z)

		# formal style
		resp2 = srv.call(tutor_srvRequest(x, y, z))

		return resp1.status

	except rospy.ServiceException as e:
		print("Service call failed: %s"%e)

if __name__ == "__main__":
	
	argv = rospy.myargv()

	if len(argv) == 4:
		try:
			x = int(argv[1])
			y = int(argv[2])
			z = int(argv[3])
		except:
			sys.exit(1)
	else:
		sys.exit(1)

	print(call_client(x, y, z))