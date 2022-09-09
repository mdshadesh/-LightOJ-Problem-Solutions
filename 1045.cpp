    #include<stdio.h>
    #include<math.h>
     
    int main()
    {
        double sum[1000005];
        int x,t,i;
        scanf("%d",&x);
        for(i=1;i<=1000002;i++)
        {
            sum[i]=sum[i-1]+log(i);
        }
        for(t=1;t<=x;t++)
        {
            int n,base;
            double result,rs;
            result=0;
            scanf("%d%d",&n,&base);
            rs=sum[n];
            result=floor(rs/log(base))+1;
            printf("Case %d: %.0lf\n",t,result);
        }
        return 0;
    }