#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <string>
#include <map>

#define pii pair <int,int>
#define sc scanf
#define pf printf
#define Pi 2*acos(0.0)
#define ms(a,b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define MP make_pair
#define oo 1<<29
#define dd double
#define ll long long
#define EPS 10E-10
#define ff first
#define ss second
#define MAX 10000
#define CIN ios_base::sync_with_stdio(0)
#define SZ(a) (int)a.size()
#define getint(a) scanf("%d",&a)
#define loop(i,n) for(int i=0;i<n;i++)
#define TEST_CASE(t) for(int z=1;z<=t;z++)
#define PRINT_CASE printf("Case %d: ",z)
#define all(a) a.begin(),a.end()
#define intlim 2147483648
#define inf 1000000
#define rtintlim 46340
#define llim 9223372036854775808
#define rtllim 3037000499
#define ull unsigned long long
#define I int

using namespace std;

vector<ll>v;
int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    getint(t);
    TEST_CASE(t)
    {
        int n,w;
        ll a,b;
        sc("%d %d",&n,&w);
        loop(i,n)
        {
            sc("%lld %lld",&a,&b);
            v.pb(b);
        }
        sort(all(v));
        int ans=1;
        a=v[0];
        for(int i=1; i<n; i++)
        {
            if(v[i]-a>w)
            {
                ans++;
                a=v[i];
            }
        }
        PRINT_CASE;
        pf("%d\n",ans);
        v.clear();
    }
    return 0;
}