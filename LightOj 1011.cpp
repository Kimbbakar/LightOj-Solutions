#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

vector<vector<int> > grp(20,vector<int>(20));
int dp[17][1<<17];
int num,x;


void clr()
{
    memset(dp,-1,sizeof(dp));
}
int re(int i,int mark)
{

    if(i>num) return 0;
    if(dp[i][mark]>-1)return dp[i][mark];
    for(int j=0;j<num;j++)
    {
         if( (mark&(1<<j))==0)
         {
            dp[i][mark]=max(dp[i][mark],grp[i][j+1]+re(i+1,mark|(1<<j)));
         }
    }
    return dp[i][mark];
}


int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%d",&num);
            for(int i=1;i<=num;i++)
                for(int j=1;j<=num;j++)
                    scanf("%d",&grp[i][j]);
            clr();
            int ans=re(1,0);
            printf("Case %d: %d\n",tcase++,ans);
        }
    }
    return 0;
}
