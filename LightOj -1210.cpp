// Problem name : 1210-Efficient Traffic System
// Algorithm : SCC
// Contest/Practice : Off line practice
// Source : LightOj
// Comment :
// Date : 19-Aug-14

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define pf printf

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


template<class T>
inline T mod_v(T num)
{
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
inline void memset3(vector<vector<T> >&v,int s1)
{
    for(int i=0;i<s1;i++)
        v[i].clear();
}

template<class T>
T fast_pow(T n , T p)
{
    if(p==1) return n;
    if(p%2)
    {
        int g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        int g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}

template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,mod-2);
}

#ifndef ONLINE_JUDGE
#  define print(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! .......

#define MAX 22222
vector<int>graph1[MAX];
vector<int>graph2[MAX];
vector<int>belong(MAX);
vector<int>mark(MAX);
vector<int>ind(MAX);
vector<int>outd(MAX);
vector<int>keep;
int n,m,scc;


void input()
{
    int a,b;
    for(int i=0;i<MAX;i++)
    {
        graph1[i].clear();
        graph2[i].clear();
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        graph1[a].pb(b);
        graph2[b].pb(a);
    }
}

void dfs1(int u)
{
    mark[u]=1;
    for(int i=0;i<sz(graph1[u]);i++)
    {
        if(!mark[graph1[u][i]])
        {
            dfs1(graph1[u][i]);
        }
    }
    keep.pb(u);
}

void dfs2(int u,int scc)
{
    mark[u]=1;
    belong[u]=scc;
    for(int i=0;i<sz(graph2[u]);i++)
    {
        if(!mark[graph2[u][i]])
        {
            dfs2(graph2[u][i],scc);
        }
    }
}

void kosaraju()
{
    memset1(mark,sz(mark),0);
    keep.clear();
    memset1(belong,sz(belong),0);
    for(int i=1;i<=n;i++)
        if(!mark[i])
            dfs1(i);
    scc=0;
    memset1(mark,sz(mark),0);
    for(int i=sz(keep)-1;i>=0;i--)
    {
        if(!mark[keep[i]])
        {
            scc++;
            dfs2(keep[i],scc);
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
            scanf("%d %d",&n,&m);
            input();
            kosaraju();
            int in=0,out=0;
            memset1(ind,sz(ind),0);
            memset1(outd,sz(outd),0);
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<sz(graph1[i]);j++)
                {
                    if(belong[i]!=belong[graph1[i][j]])
                    {
                        outd[belong[i]]++;
                        ind[belong[graph1[i][j]]]++;
                    }
                }
            }
            for(int i=1;i<=scc;i++)
            {
                if(ind[i]==0)in++;
                if(outd[i]==0)out++;
            }
            if(scc==1)
                printf("Case %d: %d\n",tcase++,0);
            else
                printf("Case %d: %d\n",tcase++,max(in,out));
        }
    }
    return 0;
}


