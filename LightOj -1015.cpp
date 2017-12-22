#include<stdio.h>

int main()
{
    long long T,a,N;
    scanf("%lld",&T);
    long long i,j;
    if(T<=100){
    for(i=0;i<T;i++){
        scanf("%lld",&N);
        if(N>=1 && N<=1000){
            long long sum=0;
            for(j=0;j<N;j++){
                scanf("%lld",&a);
                if(a<0){
                    continue;
                }
                sum=a+sum;
            }
            printf("Case %lld: %lld\n",(i+1),sum);
            }
        }
    }
    return 0;
}
