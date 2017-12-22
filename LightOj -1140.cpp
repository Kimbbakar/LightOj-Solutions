// Problem name : 1140 - How Many Zeroes?
// Algorithm : Counting / Digit DP
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment :
// Date : 29-Sep-14

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

ll dp[20][20][2][2];
string s;

inline void clr()
{
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            for(int k=0;k<2;k++)
                for(int l=0;l<2;l++)
                    dp[i][j][k][l] =-1;
}


inline void conv(ll num)
{
    clr();
    s.clear();
    while(num>0)
    {
        s.push_back((num%10)+48);
        num/=10;
    }
    reverse(all(s));
}


ll re(int pos,int zero,bool can,int got)
{
    if(pos>=sz(s)) return zero;

    if(dp[pos][zero] [got][can]!=-1) return dp[pos][zero] [got][can];

    ll r=0;

    if(can)
    {
        for(int i=0;i<=9;i++)
            r+=re(pos+1,zero+( (i==0 && got==1) ?1:0 ),can,max(got,(i>0)?1:0 ));
    }
    else
    {
        r=re(pos+1,zero+( (s[pos]=='0' && got==1) ?1:0 ),can,max(got,(s[pos]>'0')?1:0 ) );

        if(s[pos]>'0')
        {
            for(int i=s[pos]-1-48;i>=0;i--)
                r=r+re(pos+1,zero+( (i==0 && got==1) ?1:0 ),1,max(got,(i>0)?1:0 ));
        }
    }
    return dp[pos][zero] [got][can]=r;
}

int main()
{
    int t,tcase=1;
    ll num;
    ll ans1,ans2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&num);
        num--;
        if(num<0)
            ans1=0;
        else
        {
            conv(num);
            ans1=re(0,0,0,0)+1;
        }
        scanf("%lld",&num);
        conv(num);
        ans2=re(0,0,0,0)+1;

        printf("Case %d: %lld\n",tcase++,ans2-ans1);
    }
    return 0;
}


