#include<bits/stdc++.h>
using namespace std;
typedef pair < int, int > pii;
typedef vector < int > vi;
const int maxn = 100001;
struct spawn {
  int x, y, tl, tr;
  bool operator < (const spawn & rhs) const {
    return y < rhs.y;
  }
};
struct truck {
  int x, y, l, h;
  bool operator < (const truck & rhs) const {
    return y < rhs.y;
  }
};
vector < truck > tk;
vector < spawn > sp;
int b, p, q;
int bs[maxn << 2], lz[maxn << 2];
void push_down(int rt) {
  assert((rt << 1) < (b << 2));
  assert((rt << 1 | 1) < (b << 2));
  if (lz[rt]) {
    lz[rt << 1] += lz[rt];
    bs[rt << 1] += lz[rt];
    lz[rt << 1 | 1] += lz[rt];
    bs[rt << 1 | 1] += lz[rt];
    lz[rt] = 0;
  }
}
void push_up(int rt) {
  assert((rt << 1) < (b << 2));
  assert((rt << 1 | 1) < (b << 2));
  bs[rt] = max(bs[rt << 1], bs[rt << 1 | 1]);
}
void update(int l, int r, int L, int R, int rt, int v) {
  assert(r >= l);
  assert(l >= 0 && r <= b - 1);
  int mid = (L + R) >> 1;
  if (l <= L && R <= r) {
    lz[rt] += v;
    bs[rt] += v;
    return;
  }
  push_down(rt);
  if (l <= mid && r >= L) update(l, r, L, mid, rt << 1, v);
  if (l <= R && r >= mid + 1) update(l, r, mid + 1, R, rt << 1 | 1, v);
  push_up(rt);
}
int query(int l, int r, int L, int R, int rt) {
  assert(r >= l);
  assert(l >= 0 && r <= b - 1);
  int mid = (L + R) >> 1;
  if (l <= L && R <= r) {
    return bs[rt];
  }
  push_down(rt);
  int lans = -1, rans = -1;
  if (l <= mid && r >= L) lans = query(l, r, L, mid, rt << 1);
  if (l <= R && r >= mid + 1) rans = query(l, r, mid + 1, R, rt << 1 | 1);
  push_up(rt);
  return max(lans, rans);
}
void init() {
  memset(bs, 0, sizeof(bs));
  memset(lz, 0, sizeof(lz));
}
void solve() {
  init();
  int pt = p - 1, ps = q - 1, ans = -1;
  for (int y = b - 1; y >= 0; y--) {
    while (pt >= 0 && tk[pt].y > y) pt--;
    while (ps >= 0 && sp[ps].y > y) ps--;
    int d = b - 1 - y;
    while (pt >= 0 && tk[pt].y == y) {
      const truck & c = tk[pt];
      int l = (c.x - d + b) % b, r = (l + c.l - 1) % b;
      if (l <= r) {
        update(l, r, 0, b - 1, 1, c.h);
      } else {
        update(l, b - 1, 0, b - 1, 1, c.h);
        update(0, r, 0, b - 1, 1, c.h);
      }
      pt--;
    }
    while (ps >= 0 && sp[ps].y == y) {
      const spawn & c = sp[ps];
      int l, r;
      if (c.tr - c.tl + 1 >= b) {
        l = 0;
        r = b - 1;
      } else {
        l = ((c.x - c.tr - d) % b + b) % b, r = ((c.x - c.tl - d) % b + b) % b;
      }
      if (l <= r) {
        int tmp = query(l, r, 0, b - 1, 1);
        ans = max(ans, tmp);
      } else {
        int tmp = query(l, b - 1, 0, b - 1, 1);
        ans = max(ans, tmp);
        tmp = query(0, r, 0, b - 1, 1);
        ans = max(ans, tmp);
      }
      ps--;
    }
  }
  cout << ans << endl;
}
int main() {
  cin >> b >> p >> q;
  tk.resize(p);
  sp.resize(q);
  for (size_t i = 0; i < (size_t) p; i++) {
    cin >> tk[i].x >> tk[i].y >> tk[i].l >> tk[i].h;
  }
  for (size_t i = 0; i < (size_t) q; i++) {
    cin >> sp[i].x >> sp[i].y >> sp[i].tl >> sp[i].tr;
  }
  sort(tk.begin(), tk.end());
  sort(sp.begin(), sp.end());
  solve();
  return 0;
}