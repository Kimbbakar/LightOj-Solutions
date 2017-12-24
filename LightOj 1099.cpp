//#include<cstdio>
//#include<vector>
//#include<queue>
//#include<algorithm>
//#include<map>
//#include<utility>
//#define MAX 5009
//#define INF 100000000
//
//using namespace std;
//
//
//class nod
//{
//    public:
//        int n,w;
//};
//
//bool operator < (nod a,nod b)
//{
//    return a.w>b.w;
//}
//
//vector<int>graph[MAX];
//map<pair<int,int>,int >maps;
//int cost[MAX];
//int n,r;
//nod my;
//
//void clr()
//{
//    for(int i=0;i<MAX;i++)
//    {
//        cost[i]=INF;
//        graph[i].clear();
//    }
//    maps.clear();
//}
//
//void input()
//{
//    scanf("%d %d",&n,&r);
//    int num1,num2,w;
//    for(int i=1;i<=r;i++)
//    {
//        scanf("%d %d %d",&num1,&num2,&w);
//        if(maps[make_pair(num1,num2)]==0)
//        {
//           maps[make_pair(num1 ,num2)]=w;
//           maps[make_pair(num2 ,num1)]=w;
//           graph[num1].push_back(num2);
//            graph[num2].push_back(num1);
//        }
//        else if(maps[make_pair(num1,num2)]>w)
//        {
//            maps[make_pair(num1 ,num2)]=w;
//            maps[make_pair(num2 ,num1)]=w;
//        }
//    }
//}
//
//void dijkstra()
//{
//    my.n=1;
//    my.w=0;
//    priority_queue<nod>q;
//    int nw,nxt,w,count=0;
//    q.push(my);
//    while(!q.empty())
//    {
//        nw=q.top().n;
//        w=q.top().w;
//        q.pop();
//        if(nw==n)count++;//printf("** %d %d %d\n",nw,w,count);
//        if(count==2) {printf("%d\n",w);return;}
//        for(int i=0;i<graph[nw].size();i++)
//        {
//            nxt=graph[nw][i];//printf("%d %d %d\n",nxt,w+graph[nw][i].w,cost[nxt]);
//            //if(w+graph[nw][i].w<cost[nxt])
//            {
//                cost[nxt]=w+maps[make_pair(nw,nxt)];
//                my.n=nxt;
//                my.w=cost[nxt];
//                q.push(my);
//            }
//        }
//    }
//}
//
//
//int main()
//{
//    int t,tcase;
//    while(scanf("%d",&t)==1)
//    {
//        tcase=1;
//        while(t--)
//        {
//            clr();
//            input();
//            printf("Case %d: ",tcase++);
//            dijkstra();
//        }
//    }
//    return 0;
//}
//

#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 5009
#define INF 100000000

using namespace std;


class nod
{
    public:
        int n,w;
};
class nod1
{
    public:
        int f,s;
};

bool operator < (nod a,nod b)
{
    return a.w>b.w;
}

vector<nod>graph[MAX];
nod1 cost[MAX];
int n,r;
nod my;

void clr()
{
    for(int i=0;i<MAX;i++)
    {
        cost[i].f=cost[i].s=INF;
        graph[i].clear();
    }
}

void input()
{
    scanf("%d %d",&n,&r);
    int num1,num2;
    for(int i=1;i<=r;i++)
    {
        scanf("%d %d %d",&num1,&num2,&my.w);
        my.n=num2;
        graph[num1].push_back(my);
        my.n=num1;
        graph[num2].push_back(my);
    }
}

void dijkstra()
{
    my.n=1;
    my.w=0;
    priority_queue<nod>q;
    int nw,nxt,w,count=0;
    q.push(my);
    while(!q.empty())
    {
        nw=q.top().n;
        w=q.top().w;
        q.pop();
        for(int i=0;i<graph[nw].size();i++)
        {
            nxt=graph[nw][i].n;
            if(w+graph[nw][i].w<cost[nxt].f)
            {
                cost[nxt].s=cost[nxt].f;
                cost[nxt].f=w+graph[nw][i].w;
                my.n=nxt;
                my.w=cost[nxt].f;
                q.push(my);
            }
            else if(w+graph[nw][i].w>cost[nxt].f && w+graph[nw][i].w<cost[nxt].s)
            {
                cost[nxt].s=w+graph[nw][i].w;
                my.n=nxt;
                my.w=cost[nxt].s;
                q.push(my);
            }//printf("%d->(%d) %d(%d) %d %d\n",nw,nxt,w,graph[nw][i].w,cost[nxt].f,cost[nxt].s);
        }
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
            clr();
            input();
            dijkstra();
            printf("Case %d: %d\n",tcase++,cost[n].s);

        }
    }
    return 0;
}
