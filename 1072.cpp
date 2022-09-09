#include<bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;
int main()
{
    int t,n,i;
    double  R,r;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>R>>n;
        r=(R*(sin(PI/n)))/(1+sin(PI/n));
        printf("Case %d: %.10lf\n",i,r);
    }
 
}