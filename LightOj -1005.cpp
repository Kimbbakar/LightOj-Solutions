//.......DP......
#include<cstdio>
#include<vector>
#define ull unsigned long long
using namespace std;

ull n,k;

ull re(ull i,ull j,ull count)
{
    if(count==k)
        return 1;
    else if(i>n || j>n) return 0;
    return (n-i+1)*re(i+1,j+1,count+1)+re(i,j+1,count);
}

int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%llu %llu",&n,&k);
            printf("Case %d: ",tcase++);
            if(k==0) printf("%llu\n",1);
            else if(n<k)printf("0\n");
            else if(n==1)printf("%llu\n",k);
            else
                printf("%llu\n",re(1,1,0));
        }
    }
    return 0;
}
