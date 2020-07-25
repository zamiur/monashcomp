#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxx = 110;
const int maxy = 110;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
vector<pii> p;
int m, sx, sy, tx, ty;
int ts[maxx][maxy][4];
struct node {
  int x, y, d;
};
void solve() {
  queue<node> q;
  node best = node{-1, -1, -1};
  memset(ts, -1, sizeof(ts));
  q.push({sx, sy, 0});
  ts[sx][sy][0] = 0;
  while (!q.empty()) {
    node c = q.front(); q.pop();
    int cost = ts[c.x][c.y][c.d];
    if (c.x == tx && c.y == ty) {
      if (best.x == -1) best = c;
      else if (ts[best.x][best.y][best.d] > cost) best = c;
      continue;
    }
    for (int i=0; i<4; i++) {
      // change direction
      if (cost > 0 && cost % m == 0 && i == c.d) continue;
      node nxt;
      nxt.x = c.x + dx[i];
      nxt.y = c.y + dy[i];
      nxt.d = i;
      // if nxt in bound
      if (nxt.x >= 0 && nxt.x < maxx && nxt.y >= 0 && nxt.y < maxy) {
        if (ts[nxt.x][nxt.y][nxt.d] == -1 || ts[nxt.x][nxt.y][nxt.d] > cost + 1) {
          ts[nxt.x][nxt.y][nxt.d] = cost + 1;
          q.push(nxt);
        }
      }
    }
  }
  int best_cost = ts[best.x][best.y][best.d];
  while (!(best.x == sx && best.y == sy)) {
    p.push_back({best.x, best.y});
    int cost = ts[best.x][best.y][best.d];
    int prex = best.x - dx[best.d];
    int prey = best.y - dy[best.d];
    int pred = -1;
    for (int d=0; d<4; d++) if (ts[prex][prey][d] + 1 == cost) {
      if (ts[prex][prey][d] > 0 && ts[prex][prey][d] % m == 0 && d == best.d) continue;
      pred = d;
      break;
    }
    assert(pred != -1);
    best = {prex, prey, pred};
  }
  reverse(p.begin(), p.end());
  assert(p.size() == best_cost);
  cout << best_cost << endl;
  for (auto i: p) cout << i.first << " " << i.second << endl;
}
int main() {
  cin >> m >> sx >> sy >> tx >> ty;
  solve();
  return 0;
}