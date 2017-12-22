// Problem name : 1057 - Collecting Gold
// Algorithm : DP + BFS
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself,people also start to believe in you
// Date : 02-Oct-14

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<assert.h>


#define pause system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define mod 1000000007
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define sqr(x) ( (x)* (x) )
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?1:0
#define all(x) (x).begin(),(x).end()
#define pf printf
#define AND &&
#define OR ||

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


template<class T>
inline T mod_v(T num)
{
    if(num>=0)
        return num%mod;
    else
        return (num%mod+mod)%mod;
}

template<class T>
inline void memset1(vector<T>&v,int s,T value)
{
    for(int i=0;i<s;i++)
        v[i]=value;
}

template<class T>
inline void memset2(vector<vector<T> >&v,int s1,int s2,T value)
{
    for(int i=0;i<s1;i++)
        for(int j=0;j<s2;j++)
            v[i][j]=value;
}


template<class T>
T fast_pow(T n , T p)
{
    if(p==0) return 1;
    if(p%2)
    {
        T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        T g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}

template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,mod-2);
}

template<class T>
inline void debug(string S1,T S2,string S3)
{
    cout<<S1<<S2<<S3;
}

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! .......


class nod
{
public:
    int x,y;
    nod(int x,int y)
    {
        this->x;
        this->y;
    }
};



int dp[1<<16][20] ;
char graph[25][25];
int cost[25][25];
int mark[25][25];
int start_x,start_y;
vector<nod>pos;
map<pair<int,int>,int>maps;
int n,m,gold,stop;
int xd[]={0,1,1,1,0,-1,-1,-1};
int yd[]={1,1,0,-1,-1,-1,0,1};

void input()
{
    scanf("%d%d",&n,&m);
    gold=0;
    maps.clear();
    pos.clear();
    for(int i=0;i<1<<16;i++)
        for(int j=0;j<20;j++)
            dp[i][j]=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%s",graph[i]);
        for(int j=0;j<m;j++)
        {
            if(graph[i][j]=='x')
            {
                start_x=i;
                start_y=j;
            }
            else if(graph[i][j]=='g')
            {
                gold++;//printf("%d %d %d\n",i,j,gold);
                maps[make_pair(i,j)]=gold;
                pos.pb(nod(i,j));
            }
            cost[i][j]=0;
        }
    }
    stop=0;

    for(int i=0;i<gold;i++)
        on(stop,i);
}

void clr()
{
    for(int i=0;i<25;i++)
        for(int j=0;j<25;j++)
            mark[i][j] =0;
}

void bfs()
{
    queue<int>qx;
    queue<int>qy;
    clr();
    mark[start_x][start_y]=1;
    qx.push(start_x);
    qy.push(start_y);
    while(!qx.empty())
    {
        int x=qx.front();
        int y=qy.front();
        qx.pop();
        qy.pop();
        for(int i=0;i<8;i++)
        {
            if(x+xd[i]>=0 && y+yd[i]>=0 && x+xd[i]<n && y+yd[i]<m)
            {
                if(mark[x+xd[i]][y+yd[i]]==0)
                {
                    mark[x+xd[i]][y+yd[i]]=mark[x][y]+1;
					qx.push(x+xd[i]);
					qy.push(y+yd[i]);
                   if(maps[make_pair(x+xd[i],y+yd[i])]>0)
                   {
                       cost[0][maps[make_pair(x+xd[i],y+yd[i])]]=mark[x+xd[i]][y+yd[i]]-1;
                       cost[maps[make_pair(x+xd[i],y+yd[i])]][0]=mark[x+xd[i]][y+yd[i]]-1;
                   }

                }
            }
        }
    }

    for(int k=0;k<sz(pos);k++)
    {
        qx.push(pos[k].x);
        qy.push(pos[k].y);
        clr();
        mark[pos[k].x][pos[k].y]=1;
        while(!qx.empty())
        {
            int x=qx.front();
            int y=qy.front();
            qx.pop();
            qy.pop();

            for(int i=0;i<8;i++)
            {
                if(x+xd[i]>=0 && y+yd[i]>=0 && x+xd[i]<n && y+yd[i]<m)
                {
                    if(mark[x+xd[i]][y+yd[i]]==0)
                    {
                       mark[x+xd[i]][y+yd[i]]=mark[x][y]+1;
                        qx.push(x+xd[i]);
					   qy.push(y+yd[i]);
                       if(graph[x+xd[i]][y+yd[i]]=='g')
                       {
                            cost[maps[make_pair(pos[k].x,pos[k].y)]][maps[make_pair(x+xd[i],y+yd[i])]]=mark[x+xd[i]][y+yd[i]]-1;
                       }

                    }
                }
            }
        }
    }
}


int re(int mark,int parent)
{//printf("%d %d\n",mark,parent);
    if(mark==stop)
        return cost[0][parent];
    if(dp[mark][parent]!=-1) return dp[mark][parent];

    int r=1<<28;
    for(int i=0;i<gold;i++)
    {
        bool flag=check(mark,i);
        if(!flag)
        {
            int cur=mark;
            on(cur,i);

            r=min(r,cost[parent][i+1]+re(cur,i+1));
        }
    }
    return dp[mark][parent]=r;
}

int main()
{
    int t,tcase=1;

    scanf("%d",&t);
    while(t--)
    {
        input();
        bfs();
        printf("Case %d: %d\n",tcase++,re(0,0));
    }
    return 0;
}

