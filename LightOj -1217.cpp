#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class my
{
public:
    int value,start;
};

vector<my>dp(1009);
vector<int>v(1009);
int n;
int re(int i,int start)
{
    //printf("%d\n",v[i]);
    if(start==1 && i==n)
    {
        //printf("** %d %d\n",v[i],s);
        return 0;
    }
    if(i>n)return 0;
    if(dp[i].value)return dp[i].value;
    int r1,r2;
    if(start==-1)
        r1=v[i]+re(i+2,i);
    else
        r1=v[i]+re(i+2,start);
    r2=re(i+1,start);
    if(start!=-1)
        dp[i].start=start;
    //printf("%d %d\n",r1,r2);
    return dp[i].value=max(r1,r2);
}

int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%d",&n);

            for(int i=0;i<=1000;i++)
                dp[i].value=0,dp[i].start=i;
            for(int i=1;i<=n;i++)
                scanf("%d",&v[i]);
                int ans=re(1,-1);
            for(int i=0;i<=1000;i++)
                dp[i].value=0,dp[i].start=i;
                ans=max(ans,re(2,-1));
            printf("Case %d: %d\n",tcase++,ans);
        }
    }
    return 0;
}
