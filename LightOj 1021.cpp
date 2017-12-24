// Problem name :
// Algorithm :
// Contest/Practice :
// Source :
// Comment :
// Date :

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


string s;
ll base,k;
ll bcase,l;
ll mod;
template<class T>
inline T mod_v(T num)
{
    //return num;
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

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! .......


inline ll value(char ch)
{
    if(ch>='0' && ch<='9')
        return ch-'0';
    else
        return 10+(ch-'A') ;
}

inline ll cal(ll x,ll pos)
{
    if(base==10)
        return value(s[x]);
    return value(s[x])*fast_pow(base,pos);
}

vector<vector<ll> >dp(1<<17,vector<ll>(20));

ll re(ll mark,ll modv,ll pos)
{
    if(mark==bcase ) return modv==0?1:0;
    else if(dp[mark][modv]!=-1) return dp[mark][modv];
    ll sum=0;
    for(int i=0;i<sz(s);i++)
    {
        bool z=check(mark,i);
        if(z==false)
        {
            ll smpl=mark;
            if(base==10)
                l=(modv*10+cal(i,sz(s)-pos-1))%k;
            else
                l=(modv+cal(i,sz(s)-pos-1))%k;
            smpl=on(smpl,i);
            sum+=re(smpl,l,pos+1);
        }
    }
    return dp[mark][modv]=sum;
}



int main()
{
    int t,tcase=1;
    scanf("%d",&t);
    while(t--)
    {
        memset2(dp,1<<17,20,(ll) -1);
        scanf("%lld %lld",&base,&k);
       mod=k;
        cin>>s;
        bcase=0;
        for(int i=0;i<sz(s);i++)
            on(bcase,i);
        printf("Case %d: %lld\n",tcase++,re(0,0,0));
    }
    return 0;
}

