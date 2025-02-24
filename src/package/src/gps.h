#ifndef GPS_H
#define GPS_H

#include <cmath>

// WGS84 및 ENU 구조체 정의
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

// 도(degree) -> 라디안 변환 함수
double degToRad(double deg);

// WGS84 -> ENU 변환 함수
ENU wgs84ToENU(WGS84 wgs84);

// 전역 변수 (extern 선언, 정의는 gps.cpp에서 수행)
extern WGS84 ref_WGS;
extern float a, f, e2;
extern float ref_phi, ref_q, ref_x, ref_y, ref_z;

#endif