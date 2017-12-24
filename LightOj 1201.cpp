// Problem name : 1201 - A Perfect Murder
// Algorithm : DP
// Contest/Practice : OffLine Practice
// Source : LightOj
// Comment :
// Date : 21-Sep-2014

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
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define pf printf

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

int dp[1009][2];
int mark[1009];
vector<int>graph[1009];
int n,m,sz;


void clr()
{
    for(int i=0;i<1009;i++)
    {
        graph[i].clear();
        mark[i]=-1;
    }
}
void clr1()
{
    for(int i=0;i<1009;i++)
    {
        for(int j=0;j<2;j++)
            dp[i][j]=-1;
    }
}

void input()
{
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
}

void bfs(int s,int c,vector<int>&got )
{
    queue<int>q;
    q.push(s);
    got.pb(s);
    mark[s]=c;
    while(!q.empty() )
    {
        int l=q.front();
        q.pop();
        for(int i=0;i<sz(graph[l]);i++)
        {
            if(mark[graph[l][i]]==-1)
            {
                got.pb(graph[l][i]);
                mark[graph[l][i]]=c;
                q.push(graph[l][i]);
            }
        }
    }
}

int re(int i,int f,int prv)
{//printf("%d %d %d\n",i,f,prv);pause;
    if(i>n) return 0;
    //if(graph[i].size()==0 || (graph[i].size()<=1 && f>0 )) return prv==0?1:0;

    if(dp[i][prv]!=-1) return dp[i][prv];

    int r1=0,r2=0;
    if(prv==0)r1=1;
    for(int j=0;j<sz(graph[i] );j++)
    {
        if(graph[i][j]==f) continue;
        if(prv==0)
            r1+=re(graph[i][j],i,1);
        r2+=re(graph[i][j],i,0);
    }
    r1=max(r1,r2);
    return dp[i][prv]=r1;
}

int main()
{
    int t,tcase=1;
    scanf("%d",&t);
    while(t--)
    {
        clr();
        clr1();
        input();
        int ans=0,r;
        vector<int>got;
        int color=1;
        for(int i=1;i<=n;i++)
        {
            if(mark[i]==-1)
            {
                got.clear();
                bfs(i,color,got);color++;
                r=0;//printf("   %d \n",sz(got));
                for(int j=0;j<sz(got);j++)
                {
                    //clr1();
                    int l=0;
                    r=max(r,(l=re(got[j],0,0) ) );//printf("%d %d \n",got[j],l);
                }

                ans+=r;
            }
        }
        printf("Case %d: %d\n",tcase++,ans);
    }
    return 0;
}

