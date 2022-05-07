    #include<iostream>
    using namespace std;
    int main(){
    int t,k=1;
    cin>>t;
    while(t-->0){
    int sum=0;
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++){
    cin>>x;
    if(x>0)
    sum=sum+x;
    }
    cout<<"Case "<<k<<": "<<sum<<endl;
    k++;
    }
    return 0;
    }