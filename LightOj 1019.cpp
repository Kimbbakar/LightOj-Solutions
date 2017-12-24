#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<utility>

using namespace std;
#define INF 100000009
#define MAX 109
vector<int>take(MAX);
vector<int>list[MAX];
map<pair<int,int>,int>maps;
class my
{
    public:
    int nod,wight;
};
bool operator<(my a,my b)
{
    if(a.wight<b.wight) return a.wight>b.wight;
}
void clr(int m)
{
    maps.clear();
    int i;
    for(i=1;i<=m;i++)
    {
        take[i]=INF;
        list[i].clear();
    }
}
void input(int n)
{
    int i,j;
    int a,b,w;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        scanf("%d",&w);
        if(maps[make_pair(a,b)]==0)
        {
            maps[make_pair(a,b)]=w;
            maps[make_pair(b,a)]=w;
            list[a].push_back(b);
            list[b].push_back(a);
        }
        else if(maps[make_pair(a,b)]>w){
            maps[make_pair(a,b)]=w;
            maps[make_pair(b,a)]=w;
        }
    }
}

void dijkstra(int dis)
{
    int i,j,x_n,y_w,a_n,b_w;
    my le_me;
    le_me.nod=1;
    le_me.wight=0;
    priority_queue<my>q;
    q.push(le_me);
    take[1]=0;
    while(!q.empty())
    {
        x_n=q.top().nod;
        y_w=q.top().wight;
        q.pop();
        for(i=0;i<list[x_n].size();i++)
        {
            b_w=take[x_n]+maps[make_pair(x_n,list[x_n][i])];
            //printf("%d=%d b_w=%d\n",list[x_n][i],take[list[x_n][i]],b_w);
            if(take[list[x_n][i]]>b_w){
                take[list[x_n][i]]=b_w;
                if(list[x_n][i]!=dis){
                    le_me.nod=list[x_n][i];
                    le_me.wight=take[list[x_n][i]];
                    q.push(le_me);
                }
            }
        }
    }
}

int main()
{
    int i,j,m,n,t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%d %d",&m,&n);
            clr(m);
            input(n);
            dijkstra(m);
            printf("Case %d: ",tcase++);
            if(take[m]!=INF) printf("%d\n",take[m]);
            else printf("Impossible\n");
        }
    }
    return 0;
}
