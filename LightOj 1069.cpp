#include<stdio.h>

int main()
{
    int a,b;
    int num;
    scanf("%d",&num);
    int i;
    if(num<=25){
        for(i=0;i<num;i++){
            scanf("%d%d",&a,&b);
            int times=0;
            if(a<=100 && b<=100){
                int dif=b-a;
                if(dif<0){
                    dif=-1*dif;
                }
                int times=dif*4+19+a*4;
                printf("Case %d: %d\n",(i+1),times);
            }
        }
    }
    return 0;
}
