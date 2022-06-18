#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define LPII pair<LL, pair<int,int> >
#define MP make_pair
#define F first
#define S second
#define LINF LLONG_MAX


LL shomadhan(LL r,LL c,LL k)
{
   if(k > r || k > c)
       return 0;
   else if(k==(LL)0)
       return 1;
   else if(r==(LL)1)
       return c;
   else return c*shomadhan(r-1,c-1,k-1)+shomadhan(r-1,c,k);


}

int main()
{
   //freopen("LightOj1099.txt","w",stdout);

   int tc;
   scanf("%d",&tc);

   for(int i=1; i<=tc; i++)
   {
       LL n,k;
       scanf("%lld %lld",&n,&k);

       LL ans=shomadhan(n,n,k);

       printf("Case %d: %lld\n",i,ans);
   }

   return 0;
}