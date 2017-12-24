// Problem name : 1032 - Fast Bit Calculations
// Algorithm : Digit DP
// Contest/Practice : Off line practice
// Source : Light Oj
// Comment :
// Date : 26-Aug-14

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

class nod
{
public:
    ll path,c;
    void set(ll path,ll c)
    {
        this->path=path;
        this->c=c;
    }
};

int num;
nod my;
vector<char>binary;

nod dp[50][50][50];


inline void converToBinary()
{
    int x=num;
    binary.clear();
    while(x>0)
    {
        char c=(x%2)==0?'0':'1';
        binary.push_back(c);
        x/=2;
    }
    reverse(all(binary));
}


nod re(int idx,bool near,bool got)
{
    if(idx>=sz(binary))
    {
       my.set(1,0);
       return my;
    }
    if(dp[idx][near][got].c!=-1) return dp[idx][near][got];
    nod r1,r2;
    if(got)
    {
        if(binary[idx]=='1')
        {
            r1=re(idx+1,true,got);
            if(near)
                r1.c+=r1.path;
            r2=re(idx+1,false,got);
            r1.path+=r2.path;
            r1.c+=r2.c;
        }
        else
        {
            r1=re(idx+1,true,got);
            if(near)
                r1.c+=r1.path;
            r2=re(idx+1,false,got);
            r1.path+=r2.path;
            r1.c+=r2.c;
        }
    }
    else
    {
        if(binary[idx]=='1')
        {
            r1=re(idx+1,true,got);
            if(near)
                r1.c+=r1.path;
            r2=re(idx+1,false,true);
            r1.c+=r2.c;
            r1.path+=r2.path;
        }
        else
        {
            r1=re(idx+1,false,got);
        }
    }
    return dp[idx][near][got]=r1;
}

int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            for(int i=0;i<50;i++)
                for(int j=0;j<50;j++)
                    for(int k=0;k<50;k++)
                        dp[i][j][k].set(-1,-1);
            scanf("%d",&num);
            converToBinary();
            nod result=re(0,false,false);
            pf("Case %d: %lld\n",tcase++,result.c);
        }
    }
    return 0;
}
