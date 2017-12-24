#include<stdio.h>
#include<string.h>

int main()
{
    char a[105];
    int count,i,n,tcase=1,t;
    scanf("%d",&t);
    while(t--){
        count=0;
        scanf("%d",&n);
        scanf("%s",a);
        for(i=0;i<n;i++){
            if((a[i]=='.' && a[i+1]=='#' && a[i+2]=='#') || (a[i]=='.' && a[i+1]=='.' && a[i+2]=='.') || (a[i]=='.' && a[i+1]=='#' && a[i+2]=='.') ||(a[i]=='.' && a[i+1]=='.' && a[i+2]=='#') || a[i]=='.'){
                count++;
                i+=2;
            }
        }
        printf("Case %d: %d\n",tcase++,count);
    }
    return 0;
}
