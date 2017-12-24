#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    int i,c1,r1,c2,r2;
    for(i=0;i<t;i++){
        scanf("%d%d%d%d",&c1,&r1,&c2,&r2);
        int sum1=c1+c2;
        int sum2=r1+r2;
        int dif1=c1-c2;
        int dif2=r1-r2;
        if(dif1<0){
            dif1=-1*dif1;
        }
        if(dif2<0){
            dif2=-1*dif2;
        }
        if(sum1%2!=sum2%2){
            printf("Case %d: impossible\n",(i+1));
            continue;
        }
        if(dif1==dif2){
            printf("Case %d: 1\n",(i+1));
            continue;
        }
        else{
            printf("Case %d: 2\n",(i+1));
        }
    }
    return 0;
}
