#include<stdio.h>
#include<string.h>

int main()
{
    int t;
    scanf("%d",&t);
    char s[10];
    int num;
    int i;
    for(i=1;i<=t;i++){
        scanf("%d %s",&num,s);
        if(strcmp(s,"Alice")==0 && num%3==1){
            printf("Case %d: Bob\n",i);
        }
        else if(strcmp(s,"Alice")==0 && num%3!=1){
            printf("Case %d: Alice\n",i);
        }
        else if(strcmp(s,"Bob")==0 && num%3==0){
            printf("Case %d: Alice\n",i);
        }
        else if(strcmp(s,"Bob")==0 && num%3!=0){
            printf("Case %d: Bob\n",i);
        }

    }
    return 0;
}
