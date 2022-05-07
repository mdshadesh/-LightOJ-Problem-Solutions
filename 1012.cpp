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
    int t;
    cin>>t;
    int II=1;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<string> str(m);
        int I=-1,J=-1;
        for(int i=0;i<m;i++){
                cin>>str[i];
                for(int j=0;j<str[i].length();j++)
                {
                    if(str[i][j]=='@')
                    {
                        I=i;J=j;
                        break;
                    }
                }
        }
        //cout<<I<<" "<<J<<endl;
        queue<pair<int,int> > q;
        q.push(make_pair(I,J));
        int count=0;
        while(!q.empty())
        {
            I=q.front().first;
            J=q.front().second;
            //cout<<I<<" "<<J<<" "<<str[I][J]<<endl;
            q.pop();
            if(str[I][J]=='#')continue;
            count++;
            str[I][J]='#';
            if(I-1>=0&&str[I-1][J]!='#')
            {
                q.push({I-1,J});
            }
            if(J-1>=0&&str[I][J-1]!='#')
            {
                q.push({I,J-1});
            }
            if(I+1<m&&str[I+1][J]!='#')
            {
                q.push({I+1,J});
            }
            if(J+1<n&&str[I][J+1]!='#')
            {
                q.push({I,J+1});
            }
        }
        cout<<"Case "<<II++<<": "<<count<<endl;
    }
    return 0;
}