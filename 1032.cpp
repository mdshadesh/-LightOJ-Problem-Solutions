#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL n, digit[35], dp[35][35][2];

LL dfs(int i, int c, int s, int e) {
    if(!i) return c;
    if(!e && ~dp[i][c][s]) return dp[i][c][s];
    int to = e ? digit[i] : 1;
    LL ret = 0;
    for(int d = 0; d <= to; ++d)
        ret += dfs(i - 1, c + (s && d), d == 1, e && d == to);
    return e ? ret : dp[i][c][s] = ret;
}

LL calc(LL x) {
    int cnt = 0;
    for(; x; x /= 2) digit[++cnt] = x & 1;
    return dfs(cnt, 0, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    memset(dp, -1, sizeof dp);
    while(t--) {
        scanf("%lld", &n);
        printf("Case %d: %lld\n", ++kase, calc(n));
    }
    return 0;
}
