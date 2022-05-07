#include<bits/stdc++.h>
using namespace std;

typedef  long long ll;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    int t,I=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x;
        vector<vector<int> > a(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++){
            cin>>x;
            a[i].push_back(x);
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0)
                {
                    a[i][j]+=min(a[i-1][j+1],a[i-1][j+2]);
                }
                if(j==1)
                {
                    a[i][j]+=min(a[i-1][j-1],a[i-1][j+1]);
                }
                if(j==2)
                {
                    a[i][j]+=min(a[i-1][j-1],a[i-1][j-2]);
                }
            }
        }
        cout<<"Case "<<I++<<": ";
        cout<<min(a[n-1][0],min(a[n-1][1],a[n-1][2]))<<endl;
    }
}