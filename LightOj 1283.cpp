// Problem name : 1283 - Shelving Books
// Algorithm : DP
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself,people also start to believe in you
// Date : 04-Oct-14

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


int dp[105][105][105];
int book[105];
int n;
void clr()
{
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=n+1;j++)
            for(int k=0;k<=n+1;k++)
                dp[i][j][k]=-1;
    }

}

int re(int pos,int l,int r)
{//printf("%d %d %d %d\n",pos,l,r,c);pause;
    if(pos>n) return 0;

    if(dp[pos][l][r]!=-1) return dp[pos][l][r];

    int res=0;

    if(book[l]<=book[pos] && book[pos]<=book[r])
        res=max(res,1+re(pos+1,pos,r));
    if(book[l]<=book[pos] && book[pos]<=book[r])
        res=max(res,1+re(pos+1,l,pos));
    res=max(res,re(pos+1,l,r));

    return dp[pos][l][r]=res;
}

int main()
{
    int t,tcase=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&book[i]);
        clr();
        book[n+1]=1<<28;
        printf("Case %d: %d\n",tcase++,re(1,0,n+1));

    }
    return 0;
}

