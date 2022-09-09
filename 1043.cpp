#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int main(){
    int t;
    double AB,AC,BC,AD,ADE,ABC,rat;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
 
        scanf("%lf%lf%lf%lf",&AB,&AC,&BC,&rat);
        ABC=rat+1;
        AD=sqrt(rat/ABC)*AB;
        printf("Case %d: %.10lf\n",i,AD);
          // Time Complexity : O(1)
    }
}