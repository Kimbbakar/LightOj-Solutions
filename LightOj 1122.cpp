#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>


using namespace std;

vector<int>dp(15);
vector<int>d(15);
int m,n;

void clr()
{
    for(int i=0;i<15;i++)
    {
        d[i]=0;
        dp[i]=0;
    }
}

int re(int i,int k)
{
    //printf("%d %d\n",i,k);
    if(k==1)
    {
       return 1;
    }
    //if(dp[i])return dp[i];
    int r=0,m=0;
    if(d[i])   r=r+re(i,k-1);
    if(d[i+2]) r=r+re(i+2,k-1);
    if(i-2>0)
    if(d[i-2]) r=r+re(i-2,k-1);
    if(d[i+1]) r=r+re(i+1,k-1);
    if(i-1>0)
    if(d[i-1]) r=r+re(i-1,k-1);
    return dp[i]=r;
}




int main()
{
    int t,tcase,a;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%d %d",&m,&n);
            clr();
            for(int i=1;i<=m;i++)
            {
                scanf("%d",&a);
                d[a]=1;
            }
            int ans=0;
            for(int i=1;i<=10;i++)
                if(d[i]==1)
                {
                    for(int i=0;i<15;i++)
                        dp[i]=0;
                    //printf("*******\n"),
                    ans+=re(i,n);
                }

            printf("Case %d: %d\n",tcase++,ans);
        }
    }
}
