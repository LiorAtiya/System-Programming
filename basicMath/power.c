#include "myMath.h"
#define E 2.71828182846

double Exponent(int x){
    return Power(E,x);
}

double Power(double x , int y){
    int temp = y;
    if(y < 0) temp = mul(-1,y);
    double ans = 1;
    for(int i=0 ; i < temp ; i++){
        ans *= x;
    }
    if(y < 0) ans = 1./ans;
    return ans;
}