#include <iostream>
#include <iomanip> 
#include <GeographicLib/UTMUPS.hpp>
#include <ros/ros.h>
#include <morai_msgs/ObjectStatusList.h>
#include <Eigen/Dense>
#include "gps.h"

using namespace std;

float offset[2] = {302459.942, 4122635.537};


// void kalmanFilter()
// {

// }


void getObjectData(const morai_msgs::ObjectStatusList::ConstPtr &msg)
{
	int npc_size = msg->npc_list.size();
	int index;
	double lat, lon;
	for (index = 0; index < npc_size; index++)
	{
		cout << fixed <<  setprecision(8) << endl;
		cout << "=======" << index + 1 << "번째 Object Info=======" << endl;
		cout << "Heading : " << msg->npc_list[index].heading << endl;
		cout << "X : " << msg->npc_list[index].position.x + offset[0] << endl;
		cout << "Y : " << msg->npc_list[index].position.y + offset[1] << endl;
        GeographicLib::UTMUPS::Reverse(52, true, msg->npc_list[index].position.x + offset[0], msg->npc_list[index].position.y + offset[1], lat, lon);
        cout << "Lat : " << lat << endl;
        cout << "Lon : " << lon << endl;
	}
	ENU enu = wgs84ToENU({lat, lon, 0});
	cout << "East : " << enu.East << endl;
	cout << "North : " << enu.North << endl;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "kalman");
	ros::NodeHandle node;

	ros::Subscriber egoData = node.subscribe<morai_msgs::ObjectStatusList>("/Object_topic", 1, getObjectData);
	ros::spin();

	return 0;
}