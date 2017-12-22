// Problem name : 1200 - Thief
// Algorithm : 0-1 knapsack DP
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself,people also start to believe in you
// Date : 03-Oct-14

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

int n,w;
int item[105][2];
int dp[105][10005];


inline void clr()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=w;j++)
            dp[i][j]=-1;
}

inline void input()
{
    int c;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&item[i][0],&c,&item[i][1]);
        w-=(c*item[i][1]);
    }
    //now w means how mane extra weight thief can carry
}

int re(int pos,int cost)
{
    if(pos>=n)
        return 0;
    if(dp[pos][cost]!=-1) return dp[pos][cost];
    int r=0;
    if(item[pos][1]+cost<=w)
        r=max(r,item[pos][0]+re(pos,item[pos][1]+cost));
    r=max(r,re(pos+1,cost));

    return dp[pos][cost]=r;
}


int main()
{
    int t,tcase=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&w);
        clr();//printf("Hello\n");
        input();
        printf("Case %d: ",tcase++);
        if(w<0)
            printf("Impossible\n");
        else
        {
            printf("%d\n",re(0,0));
        }

    }
    return 0;
}
