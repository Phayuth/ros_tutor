#!/usr/bin/env python3

import math
from math import sin, cos, pi

import rospy
import tf
from geometry_msgs.msg import Point, Pose, Quaternion, PoseStamped


def main():
	rospy.init_node('sinwave')
	posetimepub = rospy.Publisher("/posetime", PoseStamped, queue_size=50)
	rospy.loginfo("Starting Pose Publisher")

	r = rospy.Rate(100)
	
	while not rospy.is_shutdown():
		# create message definition and filling data
		posetime = PoseStamped()
		posetime.header.seq += 1
		posetime.header.stamp = rospy.Time.now()
		posetime.header.frame_id = "sinwave"

		# position
		x = sin(posetime.header.stamp.to_sec())
		y = 0.0
		z = 0.0

		# orientation convert roll pitch yaw to quaternion
		roll = 0.0
		pitch = 0.0
		yaw = 0.0
		odom_quat = tf.transformations.quaternion_from_euler(0, 0, 0)

		posetime.pose = Pose(Point(x, y, z), Quaternion(*odom_quat))

		# publish the message
		posetimepub.publish(posetime)

		r.sleep()


if __name__ == '__main__':
	main()