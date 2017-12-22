
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int n,m,ans=0;
int p[200]={0};
int Rank[200]={0};
map<string,int>maps;
class edges
{
   public:
    int v1;
    int v2;
    int cost;
};
bool compare(edges a,edges b)
{
    if(a.cost!=b.cost)
        return(a.cost<b.cost);

}
edges ed[55];
void taking_edges()
{
    char name1[55]={'\0'};
    char name2[55]={'\0'};
    int i,j=1;
    /*for(i=1;i<=m;i++)
    {
        ed[i].v1=0;
        ed[i].v2=0;
        ed[i].cost=0;
        //cout<<i<<" "<<ed[i].v1<<" "<<ed[i].v2<<" "<<ed[i].cost<<endl;
    }*/

    maps.clear();
    for(i=1;i<=m;i++)
    {
        ed[i].v1=0;
        ed[i].v2=0;
        ed[i].cost=0;
        //cin>>name1>>name2>>ed[i].cost;
        scanf("%s %s %d",name1,name2,&ed[i].cost);
        //cout<<name1<<" "<<maps[name1]<<" "<<name2<<" "<<maps[name2]<<endl;
        if(maps[name1]==0)
            maps[name1]=j++;
        if(maps[name2]==0)
            maps[name2]=j++;
         //cout<<name1<<" "<<maps[name1]<<" "<<name2<<" "<<maps[name2]<<endl;
        ed[i].v1=maps[name1];
        ed[i].v2=maps[name2];
        //cout<<i<<" "<<ed[i].v1<<" "<<ed[i].v2<<" "<<ed[i].cost<<endl;
    }
    n=j-1;
    sort(ed+1,ed+m+1,compare);
    //for(i=1;i<=m;i++)
       // cout<<ed[i].v1<<" "<<ed[i].v2<<" "<<ed[i].cost<<endl;;
    //cout<<endl;
}
void initial_parent()
{
     int i;
    for(i=1;i<=n;i++)
    {
        p[i]=i;
    }
}
int parent(int x) //recursion
{
    if(x!=p[x])
    {
        p[x]=parent(p[x]);
    }
    return (p[x]);
}
void Union(int x,int y,int i)
{
    int p_x=parent(x);
    int p_y=parent(y);
    if(p_x!=p_y)
    {
        if(Rank[p_x]>Rank[p_y])
        {
            p[p_y]=p[p_x];
        }
        else
        {
            p[p_x]=p[p_y];
            Rank[p_y]++;
        }
        ans+=ed[i].cost;
        //cout<<"Ans "<<ed[i].cost<<endl;
    }
    return;
}
void building_tree()
{
    //memset(Rank,0,sizeof(Rank));
    int i;
    for(i=0;i<=n;i++)
    {
        Rank[i]=0;
    }
    int a,b;
    for(i=1;i<=m;i++)
    {
        a=ed[i].v1;
        b=ed[i].v2;
        //cout<<"a "<<a<<" "<<"b "<<b<<endl;
        Union(a,b,i);
    }
    return ;
}
int main()
{
    int i,t,test,c;
    scanf("%d",&test);
    for(t=1;t<=test;t++){
            ans=0;
            c=0;
    scanf("%d",&m);
    taking_edges();
    initial_parent();
    building_tree();
    int x=parent(1);
    for(i=2;i<=n;i++)
    {
        if(x!=parent(i))
        {
            printf("Case %d: Impossible\n",t);
            c=1;
            break;
        }
    }
    if(c==0)
       printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
