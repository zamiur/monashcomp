#include<bits/stdc++.h>
using namespace std;
typedef pair < int, int > pii;
const int D = 25;
const int maxx = 52 + 2 * D;
const int maxy = 52 + 2 * D;
const int dx[] = {
  0,
  0,
  1,
  -1
};
const int dy[] = {
  1,
  -1,
  0,
  0
};
const long long mod = 1000000007;
int m, sx, sy, tx, ty;
int mem[maxx][maxy][maxx * 3][4];
int calc(int x, int y, int t, int d) {
  if (mem[x][y][t][d] != -1)
    return mem[x][y][t][d];
  if (t == 0) {
    if (x == sx && y == sy && d == 0) mem[x][y][t][d] = 1;
    else mem[x][y][t][d] = 0;
    return mem[x][y][t][d];
  }
  if (x == sx && y == sy) {
    mem[x][y][t][d] = 0;
    return 0;
  }
  int prex = x - dx[d];
  int prey = y - dy[d];
  int res = 0;
  if (prex >= 0 && prex <= tx + D && prey >= 0 && prey <= ty + D) {
    for (int i = 0; i < 4; i++) {
      if (t > 1 && (t - 1) % m == 0 && i == d) continue;
      res += calc(prex, prey, t - 1, i);
      if (res >= mod) res %= mod;
    }
  }
  mem[x][y][t][d] = res;
  return res;
}
void solve() {
  memset(mem, -1, sizeof(mem));
  int ans = -1;
  int opt = max(tx - sx, ty - sy);
  for (int t = 1; t <= 3 * opt; t++) {
    for (int d = 0; d < 4; d++) {
      int res = calc(tx, ty, t, d);
      if (res == 0) continue;
      if (ans == -1) ans = 0;
      ans = (ans + res) % mod;
    }
    if (ans >= 0) {
      cout << t << " " << ans << endl;
      break;
    }
  }
}
int main() {
  cin >> m >> sx >> sy >> tx >> ty;
  sx += D, sy += D, tx += D, ty += D;
  solve();
  return 0;
}