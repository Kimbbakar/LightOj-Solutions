#include<stdio.h>

int main()
{
    int t,i;
    scanf("%d",&t);
    long long  n,M,N;
    for(i=0;i<t;i++){
        scanf("%lld",&n);
        if(n%2==0){
            N=n;
            for(M=2;;M=M*2){
                N=N/2;
                if(N%2==1){
                    printf("Case %d: %lld %lld\n",i+1,N,M);
                    break;
                }
            }
        }
        else{
            printf("Case %d: Impossible\n",i+1);
        }
    }
    return 0;
}
