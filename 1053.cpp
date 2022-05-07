#include<bits/stdc++.h>
using namespace std;
int main()
{
    int C;
    cin>>C;
    int i=1;
    while(C--){
        vector<int> x;
        for(int j=0;j<3;j++)
        {
            int y;
            cin>>y;
            x.push_back(y);
        }
        sort(x.begin(),x.end());
        if(x[0]+x[1]>x[2])
        {
            long long a=pow(x[2],2.00);
            long long b=pow(x[0],2.00);
            long long c=pow(x[1],2.00);
            if(a==(b+c)){
               printf("Case %d: yes\n",i++);
               }
               else printf("Case %d: no\n",i++);
        }
        else
        {
             printf("Case %d: no\n",i++);
        }
    }

return 0;
}