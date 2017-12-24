#include<stdio.h>

int main()
{
    long long a,b;
    long long num;
    scanf("%lld",&num);
    long long i;
    if(num<=125){
        for(i=0;i<num;i++){
            scanf("%lld%lld",&a,&b);
            if(0<=a && a<=10 && 0<=b && b<=10){
                long long sum=a+b;
                printf("Case %lld: %lld\n",(i+1),sum);
            }
        }
    }
    return 0;
}
