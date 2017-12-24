#include<cstdio>
#include<vector>
#include<cmath>
#include<cstdlib>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}

int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        int num,n;
        while(t--)
        {
            scanf("%d",&num);
            int count=0;
            int sum=0;
            for(int i=1;i<=num;i++)
            {
                scanf("%d",&n);
                if(n<0)
                    count++;
                sum+=abs(n);
            }
            num-=count;
            printf("Case %d: ",tcase++);
            if(num==0)
                printf("inf\n");
            else
            {
                int v=gcd(sum,num);
                printf("%d/%d\n",sum/v,num/v);
            }
        }
    }
    return 0;
}
