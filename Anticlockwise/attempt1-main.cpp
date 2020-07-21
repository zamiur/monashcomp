#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
int a,b;
pair<int,int> p1,p2;
pair<int,int> calc(int x){
	pair<int,int> ans;
	int y=sqrt(x*1.0);
	if ((y&1)&&(y*y==x)){
		ans.first=ans.second=(-(y-1)>>1);
		return ans;
	}if ((y&1)==0) y--;
	int p=y*y;
	ans.first=ans.second=(-(y-1)>>1);
	if (x-p<=(y+1)){
		ans.second--;
		ans.first+=(x-p)-1;
		return ans;
	}p+=(y+1);
	ans.first+=y;
	ans.second--;
	if (x-p<=y+1){
		ans.second+=(x-p);
		return ans;
	}ans.second+=(y+1);
	p+=(y+1);
	if (x-p<=y+1){
		ans.first-=(x-p);
		return ans;
	}ans.first-=(y+1);
	p+=y+1;
	ans.second-=(x-p);
	return ans;
}
int main(){
	scanf("%d%d",&a,&b);
	p1=calc(a);
	p2=calc(b);
	printf("%d\n",abs(p1.first-p2.first)+abs(p1.second-p2.second));
	return 0;
}