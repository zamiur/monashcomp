#include<cstdio>
#include<vector>
using namespace std;
const long long MOD = 1000000000+7;
const int MAXN = 100000;
vector<int> G[MAXN + 5];
long long dp[MAXN + 5][4], r[MAXN + 5];
int col[MAXN + 5];
int N, P;
void dfs(int x, int pre) {
  dp[x][0] = dp[x][1] = 1;
  if (col[x] == 1) {
    dp[x][0] = 0;
    for (int i = 0; i < G[x].size(); i++) {
      int p = G[x][i];
      if (p == pre)
        continue;
      dfs(p, x);
      dp[x][1] = dp[x][1] * (dp[p][1] + dp[p][0]) % MOD;
    }
  } else {
    dp[x][1] = 0;
    for (int i = 0; i < G[x].size(); i++) {
      int p = G[x][i];
      if (p == pre)
        continue;
      dfs(p, x);
      dp[x][1] = (dp[x][1] * (dp[p][0] + dp[p][1]) % MOD + (dp[x][0] * dp[p][1])) % MOD;
      dp[x][0] = dp[x][0] * (dp[p][0] + dp[p][1]) % MOD;
    }
  }
}
int main() {
  scanf("%d", & N);
  for (int i = 0; i < N - 1; i++) {
    scanf("%d", & P);
    G[P].push_back(i + 1);
    G[i + 1].push_back(P);
  }
  for (int i = 0; i < N; i++)
    scanf("%d", & col[i]);
  dfs(0, -1);
  printf("%lld\n", dp[0][1]);
}