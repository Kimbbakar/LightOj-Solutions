#include<stdio.h>

int main()
{
    int a[10000];
    int i,j,m,t,num,count;
    scanf("%d",&t);
    for(m=1;m<=t;m++){
        scanf("%d",&num);
            for(i=0;i<num;i++){
                scanf("%d",&a[i]);
            }
            count=0;
            for(i=0;i<num;i++){
                for(j=0;j<num;j++){
                    if(a[j]!=j+1){
                        count++;
                        int t=a[j];
                        a[j]=a[t-1];
                        a[t-1]=t;
                    }
                }
            }
        printf("Case %d: %d\n",m,count);
    }
    return 0;
}
