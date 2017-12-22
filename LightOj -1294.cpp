#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    int i;
    long long n,m;
    for(i=0;i<t;i++){
        scanf("%lld%lld",&n,&m);
        if(n%(2*m)==0){
            printf("Case %d: %lld\n",(i+1),(m*n)/2);
        }
    }
    return 0;
}
