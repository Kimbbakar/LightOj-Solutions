#include<stdio.h>
#include<string.h>
#include<math.h>

int todesimal(int a)
{
    int  d=0;
    int powr=0;
    while(a>0){
        d=d+(a%10)*pow(2,powr);
        powr++;
        a=a/10;
    }
    return d;
}

int main()
{
    int a,b,c,d,e,f,g,h;
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        scanf("%d.%d.%d.%d",&e,&f,&g,&h);
        if(a==todesimal(e) && b==todesimal(f) && c==todesimal(g) && d==todesimal(h)){
            printf("Case %d: Yes\n",i);
        }
        else{
            printf("Case %d: No\n",i);
        }
    }
    return 0;
}
