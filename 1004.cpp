#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define pf(n) cout << n << endl
#define ps() cout <<" ";
#define sf(n) cin >> n
#define in(i,n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define vp vector<pair<int, int>>
#define graph vector< vector<int> >
#define vs vector<string>
/**  '' "\n" ^ **/


typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;
int INF=1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    int a[1000][1000];
    in(I,t)
    {
        
        int n;
        cin>>n;

        for(int i=0;i<2*n;i++)
        {
            for(int j=0;j<2*n;j++)
            {
                a[i][j]=0;
            }
        }
        int j=(2*n)/2-1;
        for(int i=0;i<n;i++)
        {
           
            for(int k=j,l=0;l<=i;k+=2,l++)
            {
                //cout<<i;ps();pf(k);
                cin>>a[i][k];

            }
            j--;
        }
        //cout<<111111111111111111<<endl;
        j=1;
        for(int i=(2*n)/2,p=(2*n)/2-1;i<2*n-1;i++,p--)
        {
           
            for(int k=j,l=0;l<p;k+=2,l++)
            {
                //cout<<i;ps();pf(k);
                cin>>a[i][k];
            }
            j++;
        }

        j=(2*n)/2-2;
        for(int i=1;i<n;i++)
        {
            
            for(int k=j,l=0;l<=i;k+=2,l++)
            {
                int left=0,right=0;
                if(k-1>=0)
                    left=a[i-1][k-1];
                if(k+1<2*n-1)
                    right=a[i-1][k+1];
                a[i][k]+=max(left,right);

            }
            j--;
        }
        
        j=1;
        for(int i=(2*n)/2,p=(2*n)/2-1;i<2*n-1;i++,p--)
        {
          
            for(int k=j,l=0;l<p;k+=2,l++)
            {
                int left=0,right=0;
                if(k-1>=0)
                    left=a[i-1][k-1];
                if(k+1<2*n-1)
                    right=a[i-1][k+1];
                a[i][k]+=max(left,right);
            }
            j++;
        }
        cout<<"Case "<<I+1<<": ";
         cout<<a[2*n-2][2*n/2-1]<<endl;
   
    }
}