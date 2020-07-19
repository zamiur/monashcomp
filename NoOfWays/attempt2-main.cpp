#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long sum, k;
int a[500010];
void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    for (int i = 0; i < n; ++i)
        sum += a[i];

    if (sum % 3 != 0) {
        cout << 0 << endl;
        return;
    }
    k = sum / 3;
    vector<int> forward, backward;
    sum = 0;
    for (int i = 0; i < n-2; ++i) {
        sum += a[i];
        if (sum == k) {
            forward.push_back(i+1);
        }
    }
    sum = 0;
    for (int i = n - 1; i >= 2; i--) {
        sum += a[i];
        if (sum == k) {
            backward.push_back(i-1);
        }
    }
    reverse(backward.begin(), backward.end());

    int j = 0;
    int fn = forward.size();
    int bn = backward.size();
    long long ans = 0;
    for (int i = 0; i < fn; ++i) {
        while (j < bn && backward[j] < forward[i])
            j++;
        ans += bn-j;
    }
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}