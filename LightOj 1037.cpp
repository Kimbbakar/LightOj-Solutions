// Problem name : 1037 - Agent 47
// Algorithm : Bit mask DP
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment :
// Date : 23-Sep-14

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
#define on(x,w)  x|(1<<w)
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

int dp[2<<15];
char po[17][16];
int w[16];
int n,stop;


inline void clr()
{
    for(int i=0;i<2<<15;i++)
            dp[i]=-1;
}

inline void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=0;i<n;i++)
        po[0][i]='1';
    for(int i=1;i<=n;i++)
        scanf("%s",po[i]);
}




int re(int mark)
{
//    printf(" * %d \n",mark);pause;

    if(mark==stop) return 0;

    if(dp[mark]!=-1) return dp[mark];

    int r=1<<28;

    for(int i=1;i<=n;i++)
    {
        bool c=check(mark,i);
        int cost=0;
        if(!c)
        {
            for(int j=0;j<=n;j++)
            {
              c=check(mark,j);

              if(c && (po[j][i-1]-48)>0)
              {
                cost=w[i]/ (po[j][i-1]-48) +( w[i]%(po[j][i-1]-48)==0?0:1) ;//printf("%d %c\n",w[i],po[j][i-1]);
                if(cost)
                {
                    int o=on(mark,i);//printf("%d\n",cost);
                    r=min(r,cost+re(o));
                }
              }
            }//printf("hi %d %d %d\n",mark,i,r);
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
        clr();
        input();
        stop=0;
        for(int i=0;i<=n;i++)
            stop=on(stop,i);//printf("->> %d\n",stop);
        printf("Case %d: %d\n",tcase++,re(1));
    }
    return 0;
}

