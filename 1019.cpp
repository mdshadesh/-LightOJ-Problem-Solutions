#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<bits/stdc++.h>

using namespace std;

#define INF 9999999

typedef long long ll;

vector<ll> a(1000001);

void sieve()
{
    a[0]=1;
    for(int i=1;i<=1000000;i++)
    {
        a[i]=(i%1000003*a[i-1]%1000003)%1000003;
    }
    //cout<<a[4000]<<endl;
}

ll modPow(ll x,ll n,ll m)
{
    if(n==0)return 1%m;
    ll u=modPow(x,n/2,m);
    u=(u*u)%m;
    if(n%2==1)u=(u*x)%m;
    return u;
}

int main()
{
    //freopen("c.txt","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    int x,y,w;
    cin>>t;
    int I=1;
    while(t--)
    {
        int n,edges;
        cin>>n>>edges;
        vector< vector<pair<int,int> > > a(n+1);
        for(int i=0;i<edges;i++){
            cin>>x>>y>>w;
            a[x].push_back({y,w});
            a[y].push_back({x,w});
        }
        vector<int> distance(n+1);
        fill(distance.begin(),distance.end(),INF);
        distance[1]=0;
        vector<bool> visit(n+1);
        fill(visit.begin(),visit.end(),false);
        priority_queue<pair<ll,int> > q;
        q.push({0,1});
        while(!q.empty())
        {
            int tp = q.top().second;
            q.pop();
            if(visit[tp]==true)continue;
            visit[tp]=true;
            for(int i=0;i<a[tp].size();i++)
            {
                y=a[tp][i].first;w=a[tp][i].second;
                    if(distance[y]>(distance[tp]+w))
                    {
                        distance[y] = (distance[tp]+w);
                        q.push({-distance[y],y});
                    }
            }
        }
        if(distance[n]==INF)
            cout<<"Case "<<I++<<": Impossible\n";
        else
            cout<<"Case "<<I++<<": "<<distance[n]<<endl;
    }
    return 0;
}