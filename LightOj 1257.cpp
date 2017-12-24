#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class data1
{
public:
    int nod,wight;
    void set_value(int n,int w)
    {
        nod=n;
        wight=w;
    }

};

vector<data1>aj_list[30050];
data1 my;

void clr(int n)
{
    for(int i=0;i<=n;i++)
        aj_list[i].clear();
}

void input(int n)
{
    int a,b,w;
    clr(n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d %d",&a,&b,&w);
        my.set_value(b,w);
        aj_list[a].push_back(my);
        my.set_value(a,w);
        aj_list[b].push_back(my);
    }
}

int bfs(int source,int keep[])
{
    queue<data1>q;
    my.set_value(source,0);
    q.push(my);
    vector<int>take(30050);
    data1 ans;
    ans.set_value(0,0);
    while(!q.empty())
    {
        data1 now=q.front();
        q.pop();
        take[now.nod]=1;
        for(int i=0;i<aj_list[now.nod].size();i++)
        {
            data1 next=aj_list[now.nod][i];
            if(take[next.nod]==0)
            {
                keep[next.nod]=keep[now.nod]+next.wight;
                q.push(next);
                if(keep[next.nod]>ans.wight)
                {
                    ans.nod=next.nod;
                    ans.wight=keep[next.nod];
                }
            }
        }
    }
    return ans.nod;
}

int main()
{
    int t,tcase;
    int n;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%d",&n);
            input(n);
            int k1[30005]={0};
            int k2[30005]={0};
            int k3[30005]={0};
            int s=bfs(0,k1);
            s=bfs(s,k2);
            s=bfs(s,k3);
            printf("Case %d:\n",tcase++);
            for(int i=0;i<n;i++)
                printf("%d\n",max(k2[i],k3[i]));
        }
    }
    return 0;
}
