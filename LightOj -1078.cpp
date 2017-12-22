#include<cstdio>

using namespace std;

int main()
{
    int i,j,t,num,dig,mod,count;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d",&num,&dig);
            j=dig;
            count=1;
            while((dig%num)!=0){
                dig=(dig*10+j)%num;
                count++;
            }
            printf("Case %d: %d\n",i,count);
    }
    return 0;
}
