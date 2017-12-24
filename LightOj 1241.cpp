#include<stdio.h>

int main()
{
    int ara[50];
    int t;
    scanf("%d",&t);
    int i,j,num;
    for(i=0;i<t;i++){
        scanf("%d",&num);
        int count=0,pre=2;
        for(j=0;j<num;j++){
            scanf("%d",&ara[j]);
            if((ara[j]-pre)>=1 && (ara[j]-pre)<=5){
                count++;
                pre=ara[j];
            }
            else if(ara[j]==pre){
                continue;
            }
            else{
                double a=(ara[j]-pre)/5.0;
                int b=(ara[j]-pre)/5;
                double min=a-b;
                if(min!=0){
                    count=count+1+(ara[j]-pre)/5;
                    pre=ara[j];
                }
                else{
                    count=count+(ara[j]-pre)/5;
                    pre=ara[j];
                }
            }
        }
        printf("Case %d: %d\n",(i+1),count);
    }
    return 0;
}

