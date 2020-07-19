#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<cctype>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<iomanip>
#include<set>
#include<vector>
using namespace std;
const int MAX=51;
int arr[MAX];
bool comp(int x,int y){
	return x>y;
}int main(){
	memset(arr,0,sizeof(arr));
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}int flag=1;
	sort(arr,arr+n,comp);
	int i;
        if (k > n) {
          std::cout << "-1\n" << std::endl;
          return 0;
        } else {
          std::cout << arr[k - 1] << std::endl;
          return 0;
        }
}
