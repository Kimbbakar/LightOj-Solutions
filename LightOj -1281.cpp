
//Light oj 1281-New Traffic System

#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define MAX 10000
using namespace std;

class nod1
{
    public:
        int nod,w,type;
        void s_v(int nod,int w,int type)
        {
            this->nod=nod;
            this->w=w;
            this->type=type;
        }
};

class nod2
{
    public:
        int nod,use,wight;
        void s_v(int nod,int use,int wight)
        {
            this->nod=nod;
            this->use=use;
            this->wight=wight;
        }
};


bool operator < (nod2 a,nod2 b)
{
    return a.wight>b.wight;
}

int m,n,k,d;
vector<nod1>graph[MAX+5];
int dis[11][MAX+5];
int ans;


void clr()
{
    for(int i=0;i<=MAX;i++)
    {
        graph[i].clear();
        for(int j=0;j<11;j++)
            dis[j][i]=100000000;
    }
}

void input()
{
    scanf("%d%d%d%d",&m,&n,&k,&d);
    int a,b,w;
    nod1 my;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&w);
        my.s_v(b,w,0);
        graph[a].push_back(my);
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&a,&b,&w);
        my.s_v(b,w,1);
        graph[a].push_back(my);
    }
}

int dijkstra()
{
    priority_queue<nod2>q;
    nod2 my;
    my.s_v(0,0,0);
    q.push(my);
    int nxt,nw,w,u;
    while(!q.empty())
    {
        nw=q.top().nod;
        u=q.top().use;
        w=q.top().wight;
        //printf("** %d\n",nw);
        if(nw==m-1)
            return w;
        q.pop();
        for(int i=0;i<graph[nw].size();i++)
        {
            if(u+graph[nw][i].type<=d)
            {
                if(dis[u+graph[nw][i].type][graph[nw][i].nod]>w+graph[nw][i].w)
                {
                    //printf("* %d\n",graph[nw][i].nod);
                    dis[u+graph[nw][i].type][graph[nw][i].nod]=w+graph[nw][i].w;
                    my.s_v(graph[nw][i].nod,u+graph[nw][i].type,dis[u+graph[nw][i].type][graph[nw][i].nod]);
                    q.push(my);
                }
            }
        }
    }
    return -1;
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
            ans=dijkstra();
            printf("Case %d: ",tcase++);
            if(ans==-1)
                printf("Impossible\n");
            else
                printf("%d\n",ans);
        }
    }
    return 0;
}
