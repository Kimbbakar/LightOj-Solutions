#include<stdio.h>

int tobinary(int d)
{
    int ara[10000];
    int i,j,count=0,c=0;
    for(i=0;d>0;i++){
        ara[i]=d%2;
        d/=2;
    }
    for(j=0;j<i;j++){
        if(ara[j]==1){
            count++;
        }
    }
    return count;
}

int main()
{
    int i,t,d,b;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&d);
        b=tobinary(d);
        if(b%2==0){
            printf("Case %d: even\n",i);
        }
        else{
            printf("Case %d: odd\n",i);
        }
    }
    return 0;
}
