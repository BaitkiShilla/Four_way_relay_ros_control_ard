#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{

	ros::init(argc, argv, "control_node");

	ros::NodeHandle nh;

	ros::Publisher control = nh.advertise<std_msgs::Int32>("control_top", 1000);

	ros::Rate loop_rate(0.5);

	while(ros::ok())
	{
		std_msgs::Int32 x;


		std::cout<<"input the relay number you want to toggle: ";
		std::cin>> x.data;
		
	
		
		ROS_INFO("\nUser I published %i", x.data);

		control.publish(x);

		ros::spinOnce();

	}

	return 0;
}
