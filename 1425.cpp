#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;

#define MAX 999999999999
#define MIN -99999999999
#define MAXSIZE 1024
#define pf(I,a) printf("Case %d: %lld\n",I++,a);
#define pd(I,a) printf("Case %d: %.10lf\n",I++,a);
#define sc(a) scanf("%lld",&a)

vector<vector<int> > graph(MAXSIZE);

int nodes;

int dfs(int s,int e)
{
    vector<int> A;
    for (auto u : graph[s]) {
       if (u != e) A.push_back(dfs(u, s));
    }
    if(A.size()<nodes)return 1;
    sort(A.begin(),A.end(),greater<int>());
    int sum=1;
    for(int i=0;i<nodes;i++)
    {
        sum+=A[i];
    }
    return sum;
}

vector<double> a(100000000/1000 + 1);
void sieve()
{
    a[0]=0;
    int index=1;
    for(double i=1;i<=100000000;i+=1000,index++)
    {
        double sum=a[index-1];
        for(double j=1,k=i;j<=1000;j++,k++)sum+=double(1/k);
        a[index]=sum;
    }
    /*for(int i=0;i<=100000;i++)
    {
        cout<<i*1000<<" "<<a[i]<<endl;
    }*/
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,I=1,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> a(n+1);
        a[0]=0;
        ll minn=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            minn=max(minn,a[i]-a[i-1]);
        }
        //cout<<minn<<" ";
        int count=minn;
        int c=-1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]-a[i-1]==minn)c++;
        }
        if(c>0)c=1;
        else c=0;
        pf(I,minn+c);
    }
    return 0;
}