#include<bits/stdc++.h>
using namespace std;
int main()
{
    int Case;
    cin>>Case;
    int C=1;
    while(Case--)
    {
        double ra;
        cin>>ra;
        double sq=pow(ra*2,2);
        double cir=2 * acos (0.0)*pow(ra,2);
        double result=sq-cir+0.000000001;
        printf("Case %d: %.2f\n",C++,result);
    }
    return 0;
}