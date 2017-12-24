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
ll mod=1000000007;

template<class T>
inline T mod_v(T num)
{
    return num%mod;
    return (num%mod+mod)%mod;
}
template<class T>
T fast_pow(T n, T p)
{
    if(p==1) return n;
    if(p%2)
    {
        T g=mod_v ( n * mod_v(fast_pow(n,p-1)) );
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
#define MAX 1000000

ll n,m;

vector<bool>isprime(MAX+5,false);

vector<ll>prime;
ll ans;

void sieve()
{
    isprime[0]=isprime[1]=true;
    for(int i=2;i<=sqrt(MAX);i++)
    {
        if(isprime[i]==false)
        {
            for(int j=2;i*j<=MAX;j++)
                isprime[i*j]=true;
        }
    }
    for(int i=0;i<=MAX;i++)
        if(isprime[i]==false)
            prime.push_back(i);
}


void solve(ll x,ll y)
{
    for(int i=0;prime[i]<=sqrt(x) && x>1 && i<sz(prime);i++)
    {
        if(x%prime[i]==0)
        {
            ll count=0;
            while(x%prime[i]==0 && x>1)
            {
                x=x/prime[i];
                count++;
            }
            count*=y;
           ans=mod_v(ans*mod_v(mod_v(fast_pow(prime[i],count+1)-1) * mod_v(modInverse(prime[i]-1) )      )  );
         }

    }
    if(x>1)
    {
         ans=mod_v(ans*mod_v(mod_v(fast_pow(x,y+1)-1) * mod_v(modInverse(x-1) )      )  );
         ans=mod_v(ans+mod);
    }
}

int main()
{
    int t,tcase=1;
//    while(scanf("%d",&t)==1)
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        ans=1;
        scanf("%lld %lld",&n,&m);
//        if(n==mod)
//            ans=1;
//        else
            solve(n,m);
        printf("Case %d: %lld\n",tcase++,ans);
    }
    return 0;
}

