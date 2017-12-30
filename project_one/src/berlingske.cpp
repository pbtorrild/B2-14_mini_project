
#include "ros/ros.h"
#include <ros/console.h>
//Header of Int32 standard message
#include "stdlib.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

#include <sstream>
#include <iostream>

//determin if numbers shoild go up or down
		void up_down(const std_msgs::String::ConstPtr& msg)
		{
			std::string down ("down");
			std::string up ("up");

			ros::NodeHandle node_obj; 							/*Created a node handle								*/
			//Created a publisher object
			ros::Publisher number_publisher = node_obj.advertise<std_msgs::Int32>("/numbers",10);
			ros::Rate loop_rate(10); 								/*Created a rate object								*/
			int number_count=0; 										/* Set start number 									*/

			while (msg->data.c_str() ==up) {
						std_msgs::Int32 msg;            	/* create int ROS message 						*/
						msg.data = number_count;        	/* name for the msg object 						*/
						ROS_INFO("sending %d",msg.data);  /* Prints the data 										*/
						number_publisher.publish(msg);  	/* Send the msg to the topic /numbers	*/
						ros::spinOnce();                	/* Update all ros topics							*/
						loop_rate.sleep();             		/*  delay to set f to 10 Hz						*/
						++ number_count;
					}

				while (msg->data.c_str() ==down) {
					std_msgs::Int32 msg;            		/* create int ROS message 						*/
					msg.data = number_count;        		/* name for the msg object 						*/
					ROS_INFO("sending %d",msg.data);  	/* Prints the data 										*/
					number_publisher.publish(msg);  		/* Send the msg to the topic /numbers	*/
					ros::spinOnce();                		/* Update all ros topics							*/
					loop_rate.sleep();             			/*  delay to set f to 10 Hz						*/
					-- number_count;
					}
		}

int main(int argc, char **argv)
{
		//Initialising ROS node with a name of berlingske
		ros::init(argc, argv,"berlingske");
		//Created a nodehandle object
		ros::NodeHandle input_handle;
		//Create a subscriber object
		ros::Subscriber input_subscriber = input_handle.subscribe("/input",10,up_down);
		//Spinning the node
		ros::spin();
		return 0;
}
