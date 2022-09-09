
#include<bits/stdc++.h>
using namespace std;
#define n 1000009
bool a[n];
long long int i,j,k=1;
long long int d[n];
void sieve()
{
 
    a[0]=a[1]=1;
    for(i=4; i<=n; i=i+2)
    {
        a[i]=1;
    }
 
    for(i=3;i<=sqrt(n);i=i+2)
    {
        for(j=i*i;j<=n;j=j+2*i)
        {
            a[j]=1;
        }
    }
    for(i=2; i<=n; i++)
    {
        if(a[i]==0)
        {
            d[k]=i;
            k++;
        }
    }
 
}
int main()
{
    long long int v,r,q,p,cnt,x,m,t;
    cin>>t;
    sieve();
    for(m=1; m<=t; m++)
    {
        cin>>v;
        r=1;
        for(p=1; p<=k&&d[p]<=sqrt(v); p++)
        {
            cnt=0;
            if(v%d[p]==0)
            {
                while(v%d[p]==0)
                {
                    cnt++;
                    v=v/d[p];
                    if(v==0||v==1)
                        break;
                }
                x=cnt+1;
                r=r*x;
            }
        }
        if(v!=1)
        {
            r=r*2;
        }
        printf("Case %lld: %lld\n",m,r-1);
    }
}