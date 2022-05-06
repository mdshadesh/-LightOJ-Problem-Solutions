#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<bitset>
#include<bits/stdc++.h>

using namespace std;

#define INF 999999999999999999

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
    sieve();
    int t,x,y;
    cin>>t;
    int I=1;
    while(t--)
    {
        vector<vector<int> > a(20001);
        bitset<20001> visited;
        bitset<20001> color;
        set<int> nodes;
        set<int>::iterator it;
        int color1=0;
        int color0=0;
        int n;
        cin>>n;
        while(n--)
        {
            cin>>x>>y;
            nodes.insert(x);
            nodes.insert(y);
            a[x].push_back(y);
            a[y].push_back(x);
        }

        queue<int> visit;
        int total=0;
        while(true){
                color1=0;
                color0=0;
                for(it=nodes.begin();it!=nodes.end();it++)
                {
                    if(visited[*it]==0)
                    {
                        visit.push(*it);
                        color[*it]=1;
                        color1++;
                        visited[*it] = 1;
                        break;
                    }
                }
            if(visit.empty())
                break;
           while(!visit.empty())
           {

              int tp=visit.front();
              visit.pop();
              //if(visited[tp] == 1)continue;
              //visited[tp] = 1;
              //cout<<"-->("<<tp<<","<<color[tp]<<")";
              for(int i=0;i<a[tp].size();i++)
              {
                  if(visited[a[tp][i]]==0)
                  {
                      if(color[tp]==0){color[a[tp][i]]=1;color1++;visited[a[tp][i]] = 1;
                      }
                      else{
                          color0++;visited[a[tp][i]] = 1;
                      }
                      visit.push(a[tp][i]);
                  }
              }
          }
          total+=max(color1,color0);
        }
        /*it=nodes.end();
        it--;
        for(int i=1;i<=*it;i++)
        {
            cout<<i<< " "<<color[i]<<" "<<visited[i]<<endl;
        }*/
        cout<<"Case "<<I++<<": "<<total<<"\n";
    }
    return 0;
}