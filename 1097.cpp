#include <bits/stdc++.h>
using namespace std;

/*------- Constants---- */
#define LMT				100
#define ll				long long
#define ull				unsigned long long
#define mod				1000000007
#define MEMSET_INF		63
#define MEM_VAL			1061109567
#define FOR(i,n)			for( int i=0 ; i < n ; i++ )
#define mp(i,j)			make_pair(i,j)
#define lop(i,a,b)		for( int i = (a) ; i < (b) ; i++)
#define pb(a)			push_back((a))
#define gc				getchar_unlocked
#define PI				acos(-1.0)
#define inf				1<<30
#define lc				((n)<<1)
#define rc				((n)<<1 |1)
#define msg(x)			cout<<x<<endl;

/*---- short Cuts ------- */
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))
typedef pair<int, int> ii;
typedef vector<int > vi ;
/*------ template functions ------ */
inline void sc(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 | c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
	if(neg) x=-x;
}

template <class T> inline T bigmod(T p,T e,T M){
	ll ret = 1;
	for(; e > 0; e >>= 1){
		if(e & 1) ret = (ret * p) % M;
		p = (p * p) % M;
	} return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

/*************************** END OF TEMPLATE ****************************/

const int MAC = 2097152;
const int IM = 1429500;
int iBit[MAC + 5 ];

void updt(int n,int val )
{
	// update the n item adding val to it
	while( n <= MAC) {
		iBit[n] +=val;
		n += (n&-n);
	}
}

int bs(int val )
{
	int idx = 0 , d = MAC , tidx;
	val --;
	while (d >0 &&  idx <= MAC ) {
		tidx = idx + d;
		if(tidx <= MAC &&  iBit[tidx] <= val) {
			idx = tidx;
			val -= iBit[tidx];
		}
		d >>= 1;
	}
	return idx + 1;
}

int query (int n)
{
	// Returns Comulative Sum [1.....n]
	
	int sum = 0;
	while (n > 0) {
		sum += iBit[n];
		n -= (n&-n);
		
	}
	return sum;
}

int ans[100005];
int main()
{
	
	int tc , n ,cs = 0 ;
	
	// updating every odd with 1 , even are already deleted
	for(int i = 1;i <= MAC ; i += 2  ) updt(i , 1);
	
	ans[1] = 1;
	int cnt = 2;
	int prv = 1;
	
	for( int i = 3; i <= IM ; i += 2 ){
		
		int k1 = query(i);	// this gives sum [1...i]
		int k = k1  - prv ;	// prv stores query(i-1) , We store it to avoid double counting
		
		// if k ==1 , then i th element is not deleted from the list
		
		if(k ) {
			ans[cnt ++] = i ; // add in the answer array
			int p = (IM / i ) * i  ; // Starting from Rightmost pos , this update willnot affect the [1 ..... p-1] update
			while(p >= i ) {
				int pk = bs(p);	// Find the number which is the p th element in the list
				updt(pk , -1);	// Update it -1 , as we added 1 to each of the, nullify is done with -1 update
				p-= i ;
			}
			prv = k1;
			
		}
	}
	sc(tc);
	while (tc -- ) {
		sc(n);
		printf("Case %d: %d\n", ++cs , ans[n]);
	}
	
	return 0;
}