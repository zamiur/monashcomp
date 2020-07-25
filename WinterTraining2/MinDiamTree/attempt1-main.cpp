#include<bits/stdc++.h>
using namespace std;
int du[100005]={0};
int main() {
  int n, m, i, j, k;
  scanf("%d %d", & n, & m);
  for (i = 1; i < n; i++) {
    scanf("%d %d", & j, & k);
    du[j]++;
    du[k]++;
  }
  int ans = 0;
  for (i = 1; i <= n; i++)
    if (du[i] == 1) ans++;
  printf("%.7lf\n", 2.0 * m / ans);
  return 0;
}