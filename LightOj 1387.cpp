#include<stdio.h>

int main()
{
    char ara[10];
    long long r[100];
    long long num,sum,i,j,t,k,t1,count;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        sum=0;
        count=0;
        scanf("%lld",&t1);
        for(j=1;j<=t1;j++){
            scanf("%s",ara);
            if(ara[0]=='d' && ara[1]=='o' && ara[2]=='n' && ara[3]=='a' && ara[4]=='t' && ara[5]=='e'){
                scanf("%lld",&num);
                sum=sum+num;
            }
            else if(ara[0]=='r' && ara[1]=='e' && ara[2]=='p' && ara[3]=='o' && ara[4]=='r' && ara[5]=='t'){
                r[count]=sum;
                count++;
            }
        }
        printf("Case %lld:\n",i);
        for(k=0;k<count;k++){
            printf("%lld\n",r[k]);
        }
    }
    return 0;
}
