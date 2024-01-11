#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define DEG2RAD(deg) (deg * (PI/180))
#define RAD2DEG(rad) (rad * (180/PI))
#define array_size(arr) (*(&arr + 1)) - (arr)

#define max(a,b) (a>b ? a : b)
#define min(a,b) (a>b ? b  : a)

#define d_sin(degree) (sin(DEG2RAD(degree)))
#define d_cos(degree) (cos(DEG2RAD(degree)))


int main() {
  
}
