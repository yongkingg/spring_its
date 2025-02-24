#include <iostream>
#include <ros/ros.h>
#include <morai_msgs/GPSMessage.h>
#include <visualization_msgs/Marker.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include "gps.h"

using namespace std;

double degToRad(double deg) { return deg / 180 * M_PI; }

// 기준 WGS84 좌표
WGS84 ref_WGS = {37.238838359501933, 126.772902206454901, 0.000000000000000};
float offset[2] = {302459.942, 4122635.537};
float a = 6378137.0;
float f = 1.0 / 298.257223563;
float e2 = 2 * f - pow(f, 2);
float ref_phi = sqrt(1 - e2 * pow(sin(degToRad(ref_WGS.latitude)), 2));
float ref_q = (a / ref_phi + ref_WGS.altitude) * cos(degToRad(ref_WGS.latitude));
float ref_x = ref_q * cos(degToRad(ref_WGS.longitude));
float ref_y = ref_q * sin(degToRad(ref_WGS.longitude));
float ref_z = ((a * (1 - e2) / ref_phi) + ref_WGS.altitude) * sin(degToRad(ref_WGS.latitude));

ENU wgs84ToENU(WGS84 wgs84)
{
    double X, Y, Z, dx, dy, dz, latitude, longitude, h;
    double phi, lambda, N;

    latitude = wgs84.latitude;
    longitude = wgs84.longitude;
    h = wgs84.altitude;

    phi = degToRad(latitude);
    lambda = degToRad(longitude);
    N = a / sqrt(1 - e2 * sin(phi) * sin(phi));

    X = (N + h) * cos(phi) * cos(lambda);
    Y = (N + h) * cos(phi) * sin(lambda);
    Z = ((1 - e2) * N + h) * sin(phi);

    dx = X - ref_x;
    dy = Y - ref_y;
    dz = Z - ref_z;

    ENU enu;
    enu.East = -sin(degToRad(ref_WGS.longitude)) * dx + cos(degToRad(ref_WGS.longitude)) * dy;
    enu.North = -sin(degToRad(ref_WGS.latitude)) * cos(degToRad(ref_WGS.longitude)) * dx - sin(degToRad(ref_WGS.latitude)) * sin(degToRad(ref_WGS.longitude)) * dy + cos(degToRad(ref_WGS.latitude)) * dz;
    enu.Up = cos(degToRad(ref_WGS.latitude)) * cos(degToRad(ref_WGS.longitude)) * dx + cos(degToRad(ref_WGS.latitude)) * sin(degToRad(ref_WGS.longitude)) * dy + sin(degToRad(ref_WGS.latitude)) * dz;

    return enu;
}