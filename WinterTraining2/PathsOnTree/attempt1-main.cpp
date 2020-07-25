#include<iostream>

#include<algorithm>

#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
#define ll long long# define mset(a, x) memset(a, x, sizeof(a))
using namespace std;
const double PI = acos(-1);
const int inf = 0x3f3f3f3f;
const double esp = 1e-6;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int dir[4][2] = {
  0,
  1,
  1,
  0,
  0,
  -1,
  -1,
  0
};
ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}
ll inv(ll b) {
  if (b == 1) return 1;
  return (mod - mod / b) * inv(mod % b) % mod;
}
ll fpow(ll n, ll k) {
  ll r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % mod;
    n = n * n % mod;
  }
  return r;
}
ll Fpow(ll n, ll k) {
  ll r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n;
    n = n * n;
  }
  return r;
}
ll upd(ll x, ll v) {
  x = x + v >= mod ? x + v - mod : x + v;
  return x;
}
struct node {
  int next, v, u, w;
}
p[maxn];
int head[maxn], cnt, vis[maxn], n, k, maxx;
void add(int u, int v) {
  p[cnt].v = v;
  p[cnt].next = head[u];
  head[u] = cnt++;
}
void dfs(int now, int fa, int step) {
  maxx++;
  if (step == 0) return;
  for (int i = head[now]; ~i; i = p[i].next) {
    if (p[i].v == fa) continue;
    dfs(p[i].v, now, step - 1);
  }
}
int main() {
  int i, j, x, y;
  scanf("%d%d", & n, & k);
  for (i = 0; i <= n; i++) head[i] = -1;
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", & x, & y);
    add(x, y);
    add(y, x);
  }
  int ans = 0;
  if (k % 2) {
    for (i = 1; i <= n; i++) {
      for (j = head[i]; ~j; j = p[j].next) {
        maxx = 0;
        int t = p[j].v;
        dfs(t, i, k / 2);
        dfs(i, t, k / 2);
        ans = max(maxx, ans);
      }
    }
  } else {
    for (i = 1; i <= n; i++) {
      maxx = 0;
      dfs(i, 0, k / 2);
      ans = max(maxx, ans);
    }
  }
  printf("%d\n", n - ans);
}