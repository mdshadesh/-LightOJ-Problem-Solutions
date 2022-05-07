#include<bitset>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<stdio.h>
#include<bitset>

using namespace std;

#define ll long long
#define INF 9999999
#define pfc(I,a) printf("Case %d: %d\n",I++,a)
#define pc(I,n) printf("Case %d: %d =",I++,n)
#define pf(n) printf("%d\n",n)
#define sf(n) scanf("%d",&n)
#define nl printf("\n");

vector<ll> primes;
int I=1;
bitset<101> p;
void sieve()
{
    p[0]=1;
    p[1]=1;
    for(int i=2;i*i<=100;i++)
    {
        if(p[i])continue;
        for(int j=2*i;j<=100;j+=i)
        {
            p[j]=1;
        }
    }
    for(int i=2;i<=100;i++)
    {
        if(!p[i])
        {
            primes.push_back(i);
        }
    }
    return;
}


void factorization(int nn)
{
    pc(I,nn);
    map<int,int> primeFactorization;
    for(int n=2;n<=nn;n++){
    int i=0;
    int nnn=n;
    while(i<primes.size()&&primes[i]<=nnn)
    {
        while(nnn%primes[i]==0)
        {
            primeFactorization[primes[i]]++;
            nnn/=primes[i];
        }
        i++;
    }
    if(nnn!=1)
    {
        primeFactorization[primes[i]]++;
    }
  }
    map<int,int>::iterator it;
    it=primeFactorization.begin();
    int i=0;
    int siz = primeFactorization.size();
    while(it!=primeFactorization.end())
    {
        i++;
        printf(" %d (%d)",it->first,it->second);
        if(i!=siz)
        {
            printf(" *");
        }
        it++;
    }
}

int main()
{
    sieve();
    int t;
    int n;
    sf(t);
    while(t--)
    {
        sf(n);
        factorization(n);
        nl;
    }
}
