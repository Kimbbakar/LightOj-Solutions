#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>

using namespace std;


int dp[105][105];
vector<int>elmnt;
map<int,int>maps;
int n,w,k;

void clr()
{
    for(int i=0;i<105;i++)
        for(int j=0;j<105;j++)
            dp[i][j]=-1;
    maps.clear();
    elmnt.clear();
}

void input()
{
    int x,y;
    scanf("%d %d %d",&n,&w,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        //if(maps[y]==0)
            elmnt.push_back(y);
        //maps[y]++;
    }
    sort(elmnt.begin(),elmnt.end());
}

int  re(int i,int k1)
{
    if(i>=elmnt.size() || k1>=k) return 0;
    if(dp[i][k1]!=-1) return dp[i][k1] ;
    int  r1=0,r2=0;
    for(int j=i;j<n;j++)
    {
        if(elmnt[i]+w<elmnt[j])
        {
            r1+=re(j,k1+1);
            break;
        }
        //r1+=maps[elmnt[j]];
        r1++;
    }
    r2=re(i+1,k1);
    return dp[i][k1]=max(r1,r2);
}

int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            clr();
            input();
            printf("Case %d: %d\n",tcase++,re(0,0));
        }
    }
    return 0;
}
