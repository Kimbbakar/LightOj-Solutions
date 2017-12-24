#include<stdio.h>

int main()
{
    long long a,b,n;
    long long num;
    scanf("%lld",&num);
    long long i;
    if(num<=25){
        for(i=0;i<num;i++){
            scanf("%lld",&n);
            if(0<=0 && n<=20){
                if(n<10){
                    a=0;
                    b=n;
                    printf("%lld %lld\n",a,b);
                }
                if(n>=10){
                    b=10;
                    a=n-10;
                    printf("%lld %lld\n",a,b);
                }
            }
        }
    }
    return 0;
}
