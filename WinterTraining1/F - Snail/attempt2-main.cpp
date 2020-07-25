#include<iostream>
using namespace std;
double h,u,d,f;
int main()
{
    while(cin>>h>>u>>d>>f)
    {
        if(h==0)
            return 0;
        double fall=u*f/100,now=0;
        int u1=0,day=0;
        while(now>=0&&now<=h)
        {
            day++;
            if(u1==1&&u-fall>=0){
                u-=fall;
            }
            if(u1==1&&u-fall<0){
                u=0;
            }
            if(u1==0){
                u1=1;
            }
            now+=u;
            if(now>h){
                cout<<"success on day "<<day<<endl;
                break;
            }
            now-=d;
            if(now<0){
                cout<<"failure on day "<<day<<endl;
                break;
            }
        }
    }
    return 0;
}