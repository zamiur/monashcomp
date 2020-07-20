#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	int n,i,k,j;
	int a[51];
	int temp1;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	} if(k>n){
		printf("-1\n");
	} else {
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(a[j]>a[i]){
					temp1=a[i];
					a[j]=temp1;
					a[i]=a[j];
				}
			}
		}
		printf("%d %d\n",a[k-1],a[k-1]);
	}
	return 0;
}