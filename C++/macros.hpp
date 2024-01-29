#include <iostream>
#include <cmath>
#include <string>

#define PI M_PI
#define DEG2RAD(deg) (deg * (PI/180))
#define RAD2DEG(rad) (rad * (180/PI))

#define d_sin(degree) (sin(DEG2RAD(degree))) // sin func with degree
#define d_cos(degree) (cos(DEG2RAD(degree))) // cos func with degree

#define max(a,b) (a>b ? a : b)
#define min(a,b) (a>b ? b : a)

#define array_size(arr) (*(&arr + 1)) - (arr)
#define PRINTARRAY(arr) for(int i=0;i<array_size(arr);i++) std::cout << arr[i];

#define strToInt(val) stoi(val)
#define intToStr(val) std::to_string(val)

