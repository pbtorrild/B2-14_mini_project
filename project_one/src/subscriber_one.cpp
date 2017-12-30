
#include "ros/ros.h"
#include <ros/console.h>
//Header of Int32 standard message
#include "stdlib.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

#include <sstream>
#include <iostream>

//Callback of the topic /numbers
void number_callback(const std_msgs::Int32::ConstPtr& msg)
{
	ROS_INFO("Received  [%d]",msg->data);
}

int main(int argc, char **argv)
{

	//Initialising ROS node with a name of subscriber_one
	ros::init(argc, argv,"subscriber_one");
	//Created a nodehandle object
	ros::NodeHandle node_obj;
	//Create a ubscriber object
	ros::Subscriber number_subscriber = node_obj.subscribe("/numbers",10,number_callback);

	//Spinning the node
	ros::spin();
	return 0;
}
