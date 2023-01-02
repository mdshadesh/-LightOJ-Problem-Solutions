#include <stdio.h>
typedef long long LL;

void solve() {
  LL n,ans = 0;
  LL i,j;

  scanf("%lld",&n);
  for (i = 2; i * i <= n; ++i) {
    j = n / i;
    ans += (i + j) * (j - i + 1) / 2;
    ans += i * (j - i);
  }
  printf("%lld\n", ans);
}

int main() {
  int tc;
  scanf("%d",&tc);
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}