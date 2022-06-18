#include<iostream>
#include<cstdio>

#define M 5000000

using namespace std;

int phi[M+2];

unsigned long long sum[M+2];

void calculatePhi()
{
    for(int i=2; i<=M; i++)
        phi[i] = i;

    for(int i =2; i<=M; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=M; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}

void calculatesum()
{
    sum[1] = 0;

    for(int i=2; i<=M; i++)
    {
        sum[i] = phi[i];
        sum[i]*=phi[i];
        sum[i]+=sum[i-1];
    }

}


int main()
{

    int test,a,b,result;

    calculatePhi();

    calculatesum();

    scanf("%d",&test);

    for(int i=1; i<=test; i++)
    {
        scanf("%d%d",&a,&b);

        printf("Case %d: %llu\n",i,sum[b]-sum[a-1]);
    }

    return 0;
}