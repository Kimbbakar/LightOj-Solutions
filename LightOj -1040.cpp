
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

class data
{
    public:
    int house1,house2,w;
};

bool operator < (data a,data b)
{
    if(a.w!=b.w) return a.w>b.w;
}

int house,w,denot;
vector<int>parent(55);
vector<int>child(55);
int i,j,path,x,y;
data my;
priority_queue<data>q;

void clr()
{
    while(!q.empty())
        q.pop();
    for(i=1;i<=50;i++)
    {
        parent[i]=i;
        child[i]=1;
    }
}

void input()
{
    clr();
    denot=0;
    scanf("%d",&house);
    for(i=1;i<=house;i++)
    {
        for(j=1;j<=house;j++)
        {
            scanf("%d",&w);
            if(w!=0)
            {
                denot+=w;
                my.house1=i;
                my.house2=j;
                my.w=w;
                q.push(my);
            }
        }
    }
}

int find(int a)
{
    if(parent[a]==a) return a;
    else parent[a]=find(parent[a]);
}

void find_union()
{
    path=0;
    while(!q.empty())
    {
        //printf("pf %d %d\n",q.top().house1,q.top().house2);
        x=find(q.top().house1);
        y=find(q.top().house2);

        //printf("f %d %d\n",x,y);
        if(x!=y)
        {
            if(child[x]>=child[y])
            {

                parent[y]=x;
                child[x]+=child[y];
                child[y]=0;
                //printf("1)%d %d\n",q.top().house1,q.top().house2);
                //printf("%d=%d %d=%d %d\n",x,child[x],y,child[y],q.top().w);
                //printf("p == %d %d\n",parent[x],parent[y]);
            }
            else
            {

                parent[x]=y;
                child[y]+=child[x];
                child[x]=0;
                //printf("2)%d %d\n",q.top().house1,q.top().house2);
                //printf("%d=%d %d=%d %d\n",x,child[x],y,child[y],q.top().w);
                //printf("P == %d %d\n",parent[x],parent[y]);
            }
            path++;
            //printf("%d %d\n",q.top().house1,q.top().house2);
            //printf("%d=%d %d=%d %d\n",x,child[x],y,child[y],q.top().w);
            denot-=q.top().w;
        }
        q.pop();
        if(path==house-1) break;
    }
}

int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            input();
            find_union();
            printf("Case %d: ",tcase++);
            if(path==house-1) printf("%d\n",denot);
            else printf("%d\n",-1);
        }
    }
    return 0;
}
