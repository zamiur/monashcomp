#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
 
int main()
{
    double h = 0,u = 0,d = 0,f = 0;
    double down = 0;
    double fot = 0,len = 0;
    int i = 0,tf = 0,day = 0;
 
    while (scanf ("%lf%lf%lf%lf",&h,&u,&d,&f)&&h&&u&&d&&f)
    {
        down = (double)f / 100;
        fot = u * down;
        day = 0;
        len = 0;
        tf = 1;
        while (len < h){
            if (u > 0)
                len += u;
            day++;
            if (len > h){
                tf = 1;
                break;
            }
            len -= d;
            if (len < 0){
                tf = 0;
                break;
            }
            u -= fot;
        }
        if (tf){
            cout << "success on day" << day << endl;
        }else{
            cout << "failiure on day" << day << endl;
        }
    }
    return 0;
}