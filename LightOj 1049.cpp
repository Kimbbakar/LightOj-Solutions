#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<map>
#define FOR(n) for(i=1;i<=n;i++)
using namespace std;

class data
{
    public:
    int v,left,right;
};

vector<int>aj_list[105];
map<pair<int,int>,int>p;
int i,j,n,tcase,t;
int a,b,w,l_cost,r_cost;

void clr()
{
    p.clear();
    FOR(104)
    {
         aj_list[i].clear();
    }
}

void input()
{
    scanf("%d",&n);
    FOR(n)
    {
        scanf("%d %d %d",&a,&b,&w);
        aj_list[a].push_back(b);
        aj_list[b].push_back(a);
        p[make_pair(a,b)]=0;
        p[make_pair(b,a)]=w;
    }
}

void right_cost()
{
    vector<int>take(n+5);
    queue<int>q;
    int now;
    q.push(aj_list[1][0]);
    take[1]=1;
    r_cost+=p[make_pair(1,aj_list[1][0])];
    while(!q.empty())
    {
        now=q.front();
        take[now]=1;
        q.pop();
        for(i=0;i<aj_list[now].size();i++)
        {
            if(take[aj_list[now][i]]==0)
            {
                q.push(aj_list[now][i]);
                r_cost+=p[make_pair(now,aj_list[now][i])];
            }
        }
    }
    r_cost+=p[make_pair(now,1)];
}

void left_cost()
{
    vector<int>take(n+5);
    queue<int>q;
    int now;
    q.push(aj_list[1][1]);
    l_cost+=p[make_pair(1,aj_list[1][1])];
    take[1]=1;
    while(!q.empty())
    {
        now=q.front();
        take[now]=1;
        q.pop();
        for(i=0;i<aj_list[now].size();i++)
        {
            if(take[aj_list[now][i]]==0)
            {
                q.push(aj_list[now][i]);
                l_cost+=p[make_pair(now,aj_list[now][i])];
            }
        }
    }
    l_cost+=p[make_pair(now,1)];
}

int main()
{
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            clr();
            input();
            l_cost=r_cost=0;
            left_cost();
            right_cost();
            printf("Case %d: ",tcase++);
            l_cost<=r_cost?printf("%d\n",l_cost):printf("%d\n",r_cost);
        }
    }
    return 0;
}
