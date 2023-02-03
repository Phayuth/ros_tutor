#include "ros/ros.h"
#include "ros_tutor/tutor_srv.h"
#include <cstdlib>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "Service_client");
  if (argc != 4)
  {
    ROS_INFO("Password 3 digit");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_tutor::tutor_srv>("password");
  ros_tutor::tutor_srv srv;

  srv.request.digit_1 = atoi(argv[1]);
  srv.request.digit_2 = atoi(argv[2]);
  srv.request.digit_3 = atoi(argv[3]);

  if (client.call(srv))
  {
    std::string ss = srv.response.status;
    ROS_INFO("Response: %s",ss.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
