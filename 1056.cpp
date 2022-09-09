
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLI pair<LL,int>
#define LPII pair<LL, pair<int,int> >
#define MP make_pair
#define F first
#define S second
#define LINF LLONG_MAX

#define EPS 1e-11

int main()
{
    int tc;
    scanf("%d",&tc);

    //freopen("LightOj1056.txt","w",stdout);

    for(int i=1;i<=tc;i++)
    {
        int x,y;
        char ch;
        cin>>x>>ch>>y;

        double a,b=(y/(x*1.0))*a;

        double target=200; /// 400/2

        double lo=0,hi=200,mid=(lo+hi)/2;
        a=mid;
        b=(y/(x*1.0))*a;

        double val = sqrt(a*a+b*b)*atan(b/(a*1.0)) + a;

        while(1)
        {
            if(fabs(val-target)<=EPS)
                break;
            else if(val>target)
                hi=mid;
            else if(val<target)
                lo=mid;

            mid = (lo+hi)/2;
            a = mid;
            b = (y/(x*1.0))*a;

            val = sqrt(a*a+b*b)*atan(b/(a*1.0)) + a;
        }

        cout<<"Case "<<i<<": "<<fixed<<setprecision(8)<<a<<" "<<fixed<<setprecision(8)<<b<<endl;


    }

    return 0;

}

