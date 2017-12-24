//Algorithm MST

#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<queue>
#define MAX 105

using namespace std;

class data1 // for minimum spaning tree
{
    public:
    int s,min_v;
    data1 (int s1,int v1)
    {
        s=s1;
        min_v=v1;
    }
};

class data2 //for maximum spaning tree
{
    public:
    int s,max_v;
    data2 (int s1,int v1)
    {
        s=s1;
        max_v=v1;
    }
};

bool operator <(data1 a,data1 b) //operator overloaded for min value
{
    if(a.min_v!=b.min_v)
        return a.min_v>b.min_v;
}

bool operator <(data2 a,data2 b) // operator overloaded for max value
{
    if(a.max_v!=b.max_v)
        return a.max_v<b.max_v;
}

vector<int>aj_list[MAX];
map<pair<int,int>,int>max_p; //keep max dis betwen A<-->B
map<pair<int,int>,int>min_p; //keep min dis betwen A<-->B
int i,j,n,min_cost,max_cost,c,now;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
void clr()
{
    max_p.clear();
    min_p.clear();
    for(i=0;i<MAX;i++)
        aj_list[i].clear();
}
void input()
{
    int s1,s2,d;
    clr();
    scanf("%d",&n);
    while(scanf("%d %d %d",&s1,&s2,&d)==3)
    {
        if(s1==0 && s2==0 && d==0) break;
        if(max_p[make_pair(s1,s2)]==0)
        {
            aj_list[s1].push_back(s2);
            aj_list[s2].push_back(s1);
            max_p[make_pair(s1,s2)]=d;
            max_p[make_pair(s2,s1)]=d;
            min_p[make_pair(s2,s1)]=d;
            min_p[make_pair(s1,s2)]=d;
        }
        else
        {
            max_p[make_pair(s1,s2)]=max(d,max_p[make_pair(s1,s2)]);
            max_p[make_pair(s2,s1)]=max(d,max_p[make_pair(s2,s1)]);
            min_p[make_pair(s2,s1)]=min(d,min_p[make_pair(s2,s1)]);
            min_p[make_pair(s1,s2)]=min(d,min_p[make_pair(s1,s2)]);
        }
    }

}

void min_tree()
{
    priority_queue<data1>q;
    data1 my(0,0);
    q.push(my);
    vector<int>take(MAX);
    min_cost=c=0;
    while(!q.empty())
    {
        now=q.top().s;
        if(take[now]==1)
        {
            q.pop();
            continue;
        }
        min_cost+=q.top().min_v;
        take[now]=1;
        c++;
        //printf("Now %d,%d cost=%d\n",now,q.top().min_v,min_cost);
        q.pop();
        if(c==n+1) return;
        for(i=0;i<aj_list[now].size();i++)
        {
            if(take[aj_list[now][i]]==0)
            {
                //printf("%d ",aj_list[now][i]);
                my.s=aj_list[now][i];
                my.min_v=min_p[make_pair(aj_list[now][i],now)];
                q.push(my);
            }
            //printf("\n");
        }
    }
}

void max_tree()
{
    priority_queue<data2>q;
    data2 my(0,0);
    q.push(my);
    vector<int>take(MAX);
    max_cost=c=0;
    while(!q.empty())
    {
        now=q.top().s;
        if(take[now]==1)
        {
            q.pop();
            continue;
        }
        max_cost+=q.top().max_v;
        take[now]=1;
        c++;
        //printf("Now %d,%d cost=%d\n",now,q.top().min_v,min_cost);
        q.pop();
        if(c==n+1) return;
        for(i=0;i<aj_list[now].size();i++)
        {
            if(take[aj_list[now][i]]==0)
            {
                //printf("%d ",aj_list[now][i]);
                my.s=aj_list[now][i];
                my.max_v=max_p[make_pair(aj_list[now][i],now)];
                q.push(my);
            }
            //printf("\n");
        }
    }
}
int main()
{
    int t,tcase,div,ans;
    while(scanf("%d",&t)==1)
    {
        //scanf("%d",&t);
        tcase=1;
        while(t--)
        {
            input();
            min_tree();
            max_tree();
            ans=min_cost+max_cost;
            //printf("%d %d\n",min_cost,max_cost);
            printf("Case %d: ",tcase++);
            if(ans%2==0) printf("%d\n",ans/2);
            else printf("%d/2\n",ans);
        }
    }
    return 0;
}
