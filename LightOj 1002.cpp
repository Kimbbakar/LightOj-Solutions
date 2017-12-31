#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<map>
#include <cstdlib>
#include<algorithm>
using namespace std;
#define INF 100000000
vector<int>list[550];
vector<int>value(550);
map<pair<int,int>,int>maps;
int home;
class my
{
    public:
     int nod;
     int wight;
    my(int n,int w)
    {
        nod=n;
        wight=w;
    }
};
bool operator<(my a,my b)
{
    if(a.wight!=b.wight){
        return a.wight>b.wight;
    }
    else return false;
}

void clr(int n)
{
    int i;
    maps.clear();
    for(i=0;i<=n;i++){
        list[i].clear();
        value[i]=INF;
    }
}
void input(int n,int m)
{
    int i,a,b,w;
    clr(n);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&w);
        if(maps[make_pair(a,b)]==0 && maps[make_pair(b,a)]==0)
        {
            list[a].push_back(b);
            list[b].push_back(a);
            maps[make_pair(a,b)]=w;
            maps[make_pair(b,a)]=w;
        }
        else{
            if(maps[make_pair(a,b)]>w){
                maps[make_pair(a,b)]=w;
                maps[make_pair(b,a)]=w;
            }
        }
    }

}

void dijkstra(int a)
{
    int i,j,x,y;
    priority_queue<my>q;
    my m(a,0);
    q.push(m);
    value[a]=0;
    while(!q.empty())
    {
        x=q.top().nod;
        q.pop();
        for(i=0;i<list[x].size();i++){

            if((value[list[x][i]]>max(value[x],maps[make_pair(x,list[x][i])])) && list[x][i]!=a)
            {
                //printf("%d=%d %d=%d,%d\n",list[x][i],value[list[x][i]],x,value[x],maps[make_pair(x,list[x][i])]);
                value[list[x][i]]=max(value[x],maps[make_pair(x,list[x][i])]);
                my n(list[x][i],value[list[x][i]]);
                //printf("%d %d\n",list[x][i],value[list[x][i]]);
                q.push(n);
            }
           // system("pause");
        }
    }
}
int main()
{
    int i,t,tcase=1,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        input(n,m);
         scanf("%d",&home);
        dijkstra(home);
        printf("Case %d:\n",tcase++);
        for(i=0;i<n;i++){
            if(value[i]==INF) printf("Impossible\n");
            else printf("%d\n",value[i]);
        }
    }
    return 0;
}
