// Problem name : 1068 - Investigation
// Algorithm : Digit DP
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself, people also start to believe in you
// Date : 05-Oct-14

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


int dp[10][100][100][3];
string x;
int k;
int s;

inline void convert(int num)
{
    x.clear();
    if(num==0)
        x.pb('0');
    while(num>0)
    {
        x.pb(num%10+48);
        num/=10;
    }
    reverse(all(x));
}

inline void clr()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<100;j++)
            for(int k=0;k<100;k++)
                for(int l=0;l<3;l++)
                    dp[i][j][k][l]=-1;
}

int re(int pos,int sum,int mdv,bool can)
{

    if(pos>=s)
    {
        if( (sum)%k==0 && mdv%k==0 && sum>0)
        {
            //printf("It ok %d %d %d\n",pos,sum,mdv);
            return 1;
        }

            else return 0;
    }

    if(dp[pos][sum][mdv][can]!=-1) return dp[pos][sum][mdv][can];

    int r=0;

    if(can)
    {
        for(int i=9;i>=0;i--)
        {
            r+= re(pos+1,sum+i,(mdv*10+i)%k,can);
        }
    }

    else
    {
        r+=re(pos+1,(sum+x[pos]-48),(mdv*10+x[pos]-48)%k,can);
        for(int i=x[pos]-48-1;i>=0;i--)
        {
            r+= re(pos+1,sum+i,(mdv*10+i)%k,1);
        }
    }//printf("%d %d %d %d %d\n",pos,sum,mdv,can,r);pause;
   return dp[pos][sum][mdv][can]=r;
}

int main()
{

    int t,tcase=1;
    scanf("%d",&t);
    int a,b;
    while(t--)
    {

        scanf("%d %d %d",&a,&b,&k);
        int get;

        printf("Case %d: ",tcase++);
        if(k<=81)
        {
            clr();
            convert(b);
            s=sz(x);//cout<<x<<endl;
            get=re(0,0,0,0);//printf("** %d\n",get);
            a--;
            clr();
            convert(a);
            s=sz(x);
            if(a>0)
                get-=re(0,0,0,0);
            printf("%d\n",get);
        }
        else
            printf("0\n");
    }
    return 0;
}


