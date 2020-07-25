#include<iostream>
#include<stdio.h>
#include<map>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 4e5 + 10;
int n, m, maxid, maxn;
vector < int > G[N];
int f[N];
int d[N];
int vis[N];
int path[N];
int book[N];
int du[N];
int ans, ct, nid;
void dfs(int x) {
  for (int i = 0; i < G[x].size(); i++) {
    int u = G[x][i];
    if (vis[u] == 1) continue;
    vis[u] = 1;
    if (d[u] < d[x] + 1) {
      d[u] = d[x] + 1;
      if (maxn < d[u]) {
        maxid = u;
        maxn = d[u];
      }
      path[u] = x;
    }
    dfs(u);
  }
  return;
}
void dfss(int x, int num) {
  if (ct < num) {
    ct = num;
    nid = x;
  }
  for (int i = 0; i < G[x].size(); i++) {
    int u = G[x][i];
    if (book[u] == 1) continue;
    book[u] = 1;
    dfss(u, num + 1);
  }
  return;
}
int main() {
  int cnt = 1, st, ed, idd;
  scanf("%d", & n); {
    m = n - 1;
    int flag = 0;
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i <= n; i++) book[i] = 0;
    for (int i = 1; i <= m; i++) {
      int ta, tb;
      scanf("%d%d", & ta, & tb);
      G[ta].push_back(tb);
      G[tb].push_back(ta);
    }
    for (int i = 1; i <= n; i++) vis[i] = 0;
    maxn = 0;
    maxid = 0;
    dfs(1);
    int tem = maxid;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= n; i++) path[i] = -1;
    for (int i = 1; i <= n; i++) d[i] = 0;
    maxid = 0;
    maxn = 0;
    path[tem] = -1;
    vis[tem] = 1;
    dfs(tem);
    st = maxid;
    int idd;
    for (int i = maxid; i != -1; i = path[i]) {
      book[i] = 1;
      ed = i;
    }
    for (int i = 1; i <= n; i++)
      if (book[i] && i != st && i != ed) idd = i;
    ct = 0, nid = idd;
    ans = maxn;
    for (int i = 1; i <= n; i++)
      if (book[i] == 1) {
        ct = 0;
        dfss(i, 0);
        if (ans < maxn + ct) {
          ans = maxn + ct;
          idd = nid;
        }
      }
    printf("%d\n%d %d %d\n", ans, st, ed, idd);
  }
  return 0;
}