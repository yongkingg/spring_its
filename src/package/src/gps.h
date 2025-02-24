#ifndef GPS_H
#define GPS_H

#include <cmath>

struct WGS84
{
    double latitude;
    double longitude;
    double altitude;
};

struct ENU
{
    double East;
    double North;
    double Up;
};

using namespace std;

double degToRad(double deg);
ENU wgs84ToENU(WGS84 wgs84);

extern float offset[2];
extern WGS84 ref_WGS;
extern float a, f, e2;
extern float ref_phi, ref_q, ref_x, ref_y, ref_z;

#endif