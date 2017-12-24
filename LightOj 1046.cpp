#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<utility>

using namespace std;

int x[]={1,1,2,2,-1,-1,-2,-2};
int y[]={2,-2,1,-1,2,-2,1,-1};

class my
{
    public:
        int n_visit;
        int step;
        int pre_step;
};

class point
{
    public:
        int type;
        int x,y;
        void set_v(int t,int a,int b)
        {
            type=t;
            x=a;
            y=b;
        }
};


vector<vector<my> >graph1(15,vector<my>(15));
vector<vector<char> >graph2(15,vector<char>(15));

void input(int &n,int &m,queue<point>&q)
{
    scanf("%d %d",&n,&m);
    point x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf(" %c",&graph2[i][j]);
            graph1[i][j].n_visit=graph1[i][j].step=graph1[i][j].pre_step=0;
            if(graph2[i][j]!='.')
            {
                x.set_v(graph2[i][j]-48,i,j);
                q.push(x);
            }
        }
    }
}

void bfs(int n,int m,point p,int &ans,int visitr)
{
    point now,nxt;
    queue<point>q;
    q.push(p);
    vector<vector<int> >take(n+2,vector<int>(m+2,0));
    graph1[p.x][p.y].n_visit++;
    graph1[p.x][p.y].step=0;
    int s=0;
    while(!q.empty())
    {
        now=q.front();
        if(take[now.x][now.y]%now.type==0) s=1;
        q.pop();
        for(int i=0;i<8;i++)
        {
            nxt.x=now.x+x[i];
            nxt.y=now.y+y[i];
            nxt.type=now.type;
            //printf("%d %d\n",nxt.x,nxt.y);
            if(nxt.x>=1 && nxt.x<=n && nxt.y>=1 && nxt.y<=m)
            {
                if(take[nxt.x][nxt.y]==0 && (nxt.x!=p.x || nxt.y!=p.y))
                {

                    take[nxt.x][nxt.y]=take[now.x][now.y]+1;
                    graph1[nxt.x][nxt.y].n_visit++;
                    graph1[nxt.x][nxt.y].step=graph1[now.x][now.y].step+s;
                        //printf("** %d (%d %d)\n",graph1[nxt.x][nxt.y].step,nxt.x,nxt.y);
                    q.push(nxt);
                    graph1[nxt.x][nxt.y].pre_step+=graph1[nxt.x][nxt.y].step;

                }
                if(graph1[nxt.x][nxt.y].n_visit==visitr)
                        ans=min(ans,graph1[nxt.x][nxt.y].pre_step);

            }
        }
        s=0;
    }
}

int main()
{
    int t,tcase,n,m;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            queue<point>q;
            input(n,m,q);
            int ans=10000000;
            printf("Case %d: ",tcase++);
            int visitr=q.size();
            if(visitr==1)
                printf("0\n");
            else
            {
                while(!q.empty())
                {
                    bfs(n,m,q.front(),ans,visitr);
                    q.pop();
                }
                if(ans==10000000)printf("-1\n");
                else printf("%d\n",ans);
            }

        }
    }
    return 0;
}
