#include <ros/ros.h>
#include <morai_msgs/NpcGhostCmd.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>  // sqrt, pow 사용

// using namespace std;

// struct NPCData {
//     int index;
//     double heading;
//     double x;
//     double y;
//     double velocity;
// };

// ros::Publisher npc_pub;

// vector<NPCData> loadAllNPCData(int num_npcs) {
//     vector<NPCData> all_npc_data;
//     for (int i = 1; i <= num_npcs; i++) {
//         string filename = "npc_info" + to_string(i) + ".csv";
//         ifstream file(filename);

//         if (!file.is_open()) {
//             cerr << "파일을 열 수 없습니다: " << filename << endl;
//             continue;
//         }

//         string line;
//         getline(file, line);
//         NPCData prev_npc;
//         bool first_data = true;

//         while (getline(file, line)) {
//             stringstream ss(line);
//             NPCData npc;
//             string value;

//             getline(ss, value, ','); npc.index = stoi(value);
//             getline(ss, value, ','); npc.heading = stod(value);
//             getline(ss, value, ','); npc.x = stod(value);
//             getline(ss, value, ','); npc.y = stod(value);

//             if (first_data) {
//                 npc.velocity = 0.0;
//                 first_data = false;
//             } else {
//                 double distance = sqrt(pow(npc.x - prev_npc.x, 2) + pow(npc.y - prev_npc.y, 2));
//                 double time_interval = 0.1; 
//                 npc.velocity = distance / time_interval;
//             }

//             all_npc_data.push_back(npc);
//             prev_npc = npc;
//         }
//         file.close();
//     }

//     return all_npc_data;
// }



// void publishAllNPCs(const vector<NPCData>& npc_list) {
//     ros::Rate loop_rate(10); 

//     while (ros::ok()) {
//         for (const auto& npc : npc_list) {
//             morai_msgs::NpcGhostCmd npc_msg;
//             npc_msg.unique_id = npc.index; 
//             npc_msg.position.x = npc.x;
//             npc_msg.position.y = npc.y;
//             npc_msg.heading = npc.heading;
//             npc_msg.velocity = npc.velocity;

//             npc_pub.publish(npc_msg);
//             ROS_INFO("NPC %d 이동 -> X: %.3f, Y: %.3f, Heading: %.3f, Velocity: %.2f",
//                      npc.index, npc.x, npc.y, npc.heading, npc.velocity);
//         }
//         loop_rate.sleep();
//     }
// }

int main(int argc, char **argv) {
    ros::init(argc, argv, "npc_loader");
    ros::NodeHandle node;

    // npc_pub = node.advertise<morai_msgs::NpcGhostCmd>("/npc_cmd", 10);
    // ros::Duration(1.0).sleep(); 

    // int num_npcs = 3; 
    // vector<NPCData> npc_list = loadAllNPCData(num_npcs);

    // if (npc_list.empty()) {
    //     ROS_ERROR("NPC 데이터를 불러오지 못했습니다.");
    //     return -1;
    // }

    // publishAllNPCs(npc_list);

    ros::spin();
    return 0;
}
