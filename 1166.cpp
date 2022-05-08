#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define LL long long int
#define ULL unsigned LL
#define MOD 1e9+7


int main()
{
	int tn, cn=0;
	scanf("%d", &tn);
	while(tn--)
	{
		int n;
		scanf("%d", &n);
		int ar[n];
		for(int i=0; i<n; i++)
			scanf("%d", &ar[i]);
		int mx=n, pos=n-1, tot=0;

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<(n-i); j++)
			{
				if(ar[j]==mx && j!=(mx-1))
				{
					///cout<<ar[j]<< " " <<ar[pos]<<endl;
					tot++;
					swap(ar[j], ar[pos]);
					break;
				}
			}
			mx-=1;
			pos-=1;
		}
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}