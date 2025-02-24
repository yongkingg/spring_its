#include <ros/ros.h>
#include <morai_msgs/ObjectStatusList.h>
#include <GeographicLib/UTMUPS.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "gps.h"

using namespace std;

struct NPCData {
    int index;
    double X;
    double Y;
    double East;
    double North;
    double heading;
    double velocity;
};

// CSV 파일에 NPC 데이터를 저장하는 함수
void saveNPCData(const NPCData &npc) {
    // 파일명: npc_list1.csv, npc_list2.csv, npc_list3.csv
    string filename = "npc_list" + to_string(npc.index) + ".csv";
    ofstream file;

    // 기존 데이터 유지 및 새 데이터 추가 모드
    file.open(filename, ios::app);

    if (!file.is_open()) {
        cerr << "파일을 생성할 수 없습니다: " << filename << endl;
        return;
    }

    // 파일이 비어 있다면 헤더 추가
    if (file.tellp() == 0) {
        file << "Index, Heading, X, Y, East, North, Velocity\n";
    }

    // NPC 정보 저장
    file << npc.index << ", "
         << npc.heading << ", "
         << npc.X << ", "
         << npc.Y << ", "
         << npc.East << ", "
         << npc.North << ", "
         << npc.velocity << "\n";

    file.close();
    cout << "NPC 데이터가 저장되었습니다: " << filename << endl;
}

// /Object_topic에서 데이터를 Subscribe하여 처리하는 콜백 함수
void objectCallback(const morai_msgs::ObjectStatusList::ConstPtr &msg) {
    int npc_size = msg->npc_list.size();
    double lat, lon;
    for (int i = 0; i < npc_size; i++) {
        NPCData npc;
        npc.index = i + 1;  
        npc.heading = msg->npc_list[i].heading;
        
        npc.X = msg->npc_list[i].position.x;
        npc.Y = msg->npc_list[i].position.y;


        GeographicLib::UTMUPS::Reverse(52, true, msg->npc_list[i].position.x + offset[0], msg->npc_list[i].position.y + offset[1], lat, lon);
        ENU enu = wgs84ToENU({lat, lon, 0});
        npc.East = enu.East;
        npc.North = enu.North;
        npc.velocity = sqrt(pow((msg->npc_list[i].velocity.x), 2) + pow((msg->npc_list[i].velocity.y), 2) + pow((msg->npc_list[i].velocity.z), 2));
        // CSV로 저장
        cout << npc.X << " " << npc.Y << " " << npc.East << " " << npc.North << endl;

        saveNPCData(npc);
    }
}


int main(int argc, char **argv) {
    ros::init(argc, argv, "object_subscriber");
    ros::NodeHandle nh;

    // /Object_topic을 Subscribe
    ros::Subscriber object_sub = nh.subscribe("/Object_topic", 1, objectCallback);
    ros::spin();
    return 0;
}
