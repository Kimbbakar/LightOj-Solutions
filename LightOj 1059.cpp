//lightoj-1059
//minimum spening tree

#include<cstdio>
#include<vector>
#include<queue>
#define FOR(n) for(i=1;i<=n;i++)

using namespace std;

class data
{
    public:
    int city1,city2,w;
};

bool operator <(data a,data b)
{
    if(a.w!=b.w) return a.w>b.w;
}

priority_queue<data>q;
data my;
vector<int>parent(10009);
int city,edge,port_cost,port_num,cost;
int i,j;

void clr()
{
    while(!q.empty())
        q.pop();
    FOR(10005)
        parent[i]=i;
}

void input()
{
    clr();
    scanf("%d %d %d",&city,&edge,&port_cost);
    port_num=city;
    int a,b,w;
    FOR(edge)
    {
        scanf("%d %d %d",&a,&b,&w);
        if(w<port_cost)
        {
            my.city1=a;
            my.city2=b;
            my.w=w;
            q.push(my);
        }
    }
}

int f(int a)
{
    if(parent[a]==a) return a;
    else parent[a]=f(parent[a]);
}

void union_finder()
{
    int x,y,path;
    path=cost=0;
    while(!q.empty())
    {
        x=f(q.top().city1);
        y=f(q.top().city2);
        if(x!=y)
        {
            parent[y]=x;
            cost+=q.top().w;
            port_num--;
            path++;
        }
        if(path==city-1) break;
        q.pop();
    }
}

int main()
{
    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
        freopen ( "out.txt", "w", stdout );
    #endif
    int t,tcase;
    scanf("%d",&t);
    {
        tcase=1;
        while(t--)
        {
            input();
            union_finder();
            cost=cost+(port_num*port_cost);
            printf("Case %d: %d %d\n",tcase++,cost,port_num);
        }
    }
    return 0;
}
