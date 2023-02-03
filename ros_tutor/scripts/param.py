import rospy

def main():
	# Set parameter
	rospy.set_param('list_of_floats', [1., 2., 3., 4.])
	rospy.set_param('bool_True', True)
	rospy.set_param('~private_bar', 1+2)

	while True:
		# Get parameter
		p1 = rospy.get_param("param_1")
		p2 = rospy.get_param("param_2")
		print p1
		print p2


if __name__ == '__main__':
	main()