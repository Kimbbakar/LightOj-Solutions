#include<stdio.h>

int rev(int num)
{
    int rev=0;
    while(num>0){
        rev=rev*10+num%10;
        num=num/10;
    }
    return rev;
}

int main()
{
    int n,i,t,num;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        if(n==rev(n)){
            printf("Case %d: Yes\n",i);
        }
        else{
            printf("Case %d: No\n",i);
        }
    }
    return 0;
}
