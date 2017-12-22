#include<stdio.h>

int main()
{
    int ara[30];
    int n,p,q,i,j,k,t;
    scanf("%d",&t);
    for(k=0;k<t;k++){
        int count=0,num=0,sum=0;
        scanf("%d%d%d",&n,&p,&q);
        if(n>=1 && n<=30 && p>=1 && p<=30 && q>=1 && q<=30){
            for(i=0;i<n;i++){
                scanf("%d",&ara[i]);
                sum +=ara[i];
            }
            if(sum<=q && n<=p){
                printf("Case %d: %d\n",k+1,n);
            }
            else{
                for(j=0;j<n;j++){
                    num=num+ara[j];
                    if(num<=sum && num<=q && count<n && count<p){
                        count++;
                        continue;
                    }
                    else{
                        printf("Case %d: %d\n",k+1,count);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
