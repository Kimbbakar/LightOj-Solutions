// Problem name : 1119 - Pimp My Ride
// Algorithm : Bit Mask DP
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself,people also start to believe in you
// Date : 03-OCT-14

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

int dp[1<<14];
int cost[15][15];
int n,stop;


inline void clr()
{
    for(int i=0;i<1<<14;i++)
        dp[i]=-1;
    stop=0;
    for(int i=0;i<n;i++)
        on(stop,i);
}

inline void input()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
}


int re(int mark)
{
    if(mark==stop)
        return 0;

    if(dp[mark]!=-1) return dp[mark];

    int r=1<<28;
    int sum,cur;
    for(int i=0;i<n;i++)
    {
        bool flag=check(mark,i);
        cur=mark;
        sum=0;
        if(!flag)
        {
            on(cur,i);
            for(int j=0;j<n;j++)
            {
                flag=check(cur,j);
                if(flag)
                    sum+=cost[i][j];
            }
            r=min(r,sum+re(cur));
        }
    }
    return dp[mark]=r;
}

int main()
{
    int t,tcase=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        clr();
        input();

        printf("Case %d: %d\n",tcase++,re(0));

    }
    return 0;
}

