// Problem name : 1051 - Good or Bad
// Algorithm : DP
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment :
// Date : 01-Oct-14

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


int dp[55][55][55];
string s;
int sz;


inline void clr()
{
    for(int i=0;i<55;i++)
        for(int j=0;j<55;j++)
            for(int k=0;k<55;k++)
                dp[i][j][k]=-1;
}

inline bool isv(char a)
{
    if(a=='A' || a=='E' || a=='I' || a=='O' || a=='U')
        return true;
    else return false;
}

int re(int pos,int con,int v)
{
    if(pos>=sz) return 0;

    if(dp[pos][con][v]!=-1) return dp[pos][con][v];

    int r=0,R=0;
    int a;

    if(s[pos]=='?')
    {
        r=re(pos+1,con+1,0);
        R=re(pos+1,0,v+1);

        if((con+1)>=5)
            r=1;
        if((v+1)>=3)
            R=1;

        if(r==0 && R==0)
            a=0;
        else if( (r==2 && R==0) || (r==0 && R==2) || (r==2 && R==1) || (r==1 && R==2) || (R==2 && r==2) || (R==1 && r==0) || (R==0 && r==1))
            a=2;
        else a=1;
    }
    else
    {
        if(isv(s[pos]))
        {
            a=re(pos+1,0,v+1);
            if(v+1>=3)
                a=1;
        }
        else
        {
            a=re(pos+1,con+1,0);
            if(con+1>=5)
                a=1;
        }
    }

    return dp[pos][con][v]=a;
}


int main()
{
    int t,tcase=1;
    scanf("%d",&t);
    while(t--)
    {
        clr();
        cin>>s;
        sz=sz(s);

        int ans=re(0,0,0);

        printf("Case %d: ",tcase++);

        if(ans==0)
            printf("GOOD\n");
        else if(ans==2)
            printf("MIXED\n");
        else
            printf("BAD\n");
    }
    return 0;
}

