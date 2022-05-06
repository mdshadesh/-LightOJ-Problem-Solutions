#include<iostream>
using namespace std;
int main(){
int t,a=0,b=0;
cin>>t;
while(t-->0){
int n;
cin>>n;
if(n>10){
    a=10;
    b=n-10;
  }
   else
     a=n;
cout<<b<<" "<<a<<endl;
a=0;b=0;
}
return 0;
}