#include<stdio.h>
#include<math.h>

int main()
{
    long long i,t,n,x,y;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        scanf("%lld",&n);
        long long sq=ceil(sqrt(n));
        long long r=sq*sq-n;
        if(r<sq){
            x=sq;
            y=r+1;
        }
        else{
            y=sq;
            x=2*sq-r-1;
        }
        if(sq%2==1){
           long long j=x;
           x=y;
           y=j;
       }
        printf("Case %lld: %lld %lld\n",i,x,y);
    }
    return 0;
}
