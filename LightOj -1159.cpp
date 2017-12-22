// Problem name : 1159 - Batman
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

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! .......

int dp[55][55][55];

string a,b,c;

void clr()
{
    for(int i=0;i<55;i++)
        for(int j=0;j<55;j++)
            for(int k=0;k<55;k++)
                dp[i][j][k]=-1;
}

int re(int i,int j,int k)
{
    if(i>=sz(a) || j>=sz(b) || k>=sz(c))
        return 0;
    else if(dp[i][j][k]!=-1) return dp[i][j][k];

    int r=0;
    if(a[i]==b[j] && b[j]==c[k])
    {
        r=1+re(i+1,j+1,k+1);
    }
    else
    {
        r=max(r,re(i+1,j,k));
        r=max(r,re(i,j+1,k));
        r=max(r,re(i,j,k+1));
    }
    return dp[i][j][k]=r;
}


int main()
{
    int t,tcase=1;
    scanf("%d",&t);
    while(t--)
    {
        cin>>a>>b>>c;
        clr();
        printf("Case %d: %d\n",tcase++,re(0,0,0));
    }
    return 0;
}

