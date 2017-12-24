// Problem name : 1169 - Monkeys on Twin Tower
// Algorithm : DP
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself, people also start to believe in you
// Date : 08-Oct-14

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


int dp[1005][2];
int towr_l[1005];
int jump_l[1005];
int towr_r[1005];
int jump_r[1005];
int n;


inline void clr()
{
    for(int i=0;i<=n;i++)
        dp[i][0]=dp[i][1]=-1;
}

int re(int pos,int towr)
{
    if(pos>=n) return 0;

    if(dp[pos][towr]!=-1 ) return dp[pos][towr];
    if(towr==0)
    {
        return dp[pos][towr]=towr_l[pos]+min(re(pos+1,0),jump_l[pos]+re(pos+1,1));
    }
    else
    {
        return dp[pos][towr]=towr_r[pos]+min(jump_r[pos]+re(pos+1,0),re(pos+1,1));
    }
}


int main()
{
    int t,tcase=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        clr();

        for(int i=0;i<n;i++)
            scanf("%d",&towr_l[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&towr_r[i]);
        for(int i=0;i<n-1;i++)
            scanf("%d",&jump_l[i]);
        for(int i=0;i<n-1;i++)
            scanf("%d",&jump_r[i]);
        printf("Case %d: %d\n",tcase++,min(re(0,0),re(0,1) ) );
    }
    return 0;
}

