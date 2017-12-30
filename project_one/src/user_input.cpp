//roscpp Core header
#include "ros/ros.h"
#include <ros/console.h>
//Header of Int32 standard message
#include "stdlib.h"
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>

int main(int argc, char **argv)

{

	//set ROS node with a name of user_input
	ros::init(argc, argv,"user_input");

	//Created a node handle
	ros::NodeHandle input_handle;

	//Created a publisher object
	ros::Publisher input_publisher = input_handle.advertise<std_msgs::String>("/input",1000);

	//Created a rate object
	ros::Rate loop_rate(1);

	//To initiate the string used for dereming up or down
	std::string up_down;

	//While loop for sending the user data
	while (ros::ok()&& up_down != "stop")
	{
		ROS_INFO("count (up) or (down)"); 		/* Prints the instruction 					*/
		std::cin >> up_down;									/* sace the user input 							*/
		std_msgs::String msg;             		/* create int ROS message 					*/
		std::stringstream ss;									/* Initialising a string stream 		*/
    ss << up_down;												/* Put input into the stringstream 	*/
 		msg.data = ss.str();									/* set msg data as the content of
		 																				 the srting stringstream					*/

		input_publisher.publish(msg);  				/* Send the msg to the topic 				*/
		ros::spinOnce();               				/* Update all ros topics						*/
		loop_rate.sleep();              			/*  delay to set f to 10 Hz					*/

	}

	return 0;
}
