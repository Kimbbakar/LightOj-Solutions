/*
 Problem name : 1035 - Intelligent Factorial Factorization
 Algorithm : Number Theory
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 30-Oct-14
*/

#include<bits/stdc++.h>

#define pause system("pause");
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
#define reset(x,v) memset(x,v,sizeof(x));
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
inline void memset1(vector<T>&v,T value)
{
    for(int i=0;i<sz(v);i++)
        v[i]=value;
}

template<class T>
inline void memset2(vector<vector<T> >&v,T value)
{
    for(int i=0;i<sz(v) ;i++)
        for(int j=0;j<sz(v[i]);j++)
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

template<class T>
inline T in()
{
    register char c=0;
    register T num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    return n?-num:num;
}

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! ......

#define MAX 110

int prime_fac[MAX+5];
vector<int>prime;
int n;


int isprime[MAX/32 + 10];
#define on1(x,w)  isprime[x]=isprime[x]|(1<<w)
#define check1(x,w) (isprime[x]&(1<<w))
int p,q;


inline void bit_mask_sieve()
{    memset(isprime,0,sizeof(isprime) );

    for(int i=2;i<=sqrt(MAX);i++)
    {
        p=i/32;
        q=i%32;
        if(!check1(p,q))
        {
            for(int j=2;i*j<=MAX;j++)
            {
                p=(i*j)/32;
                q=(i*j)%32;
                on1(p,q);
            }
        }
    }
    for(int i=2;i<=MAX;i++)
    {
        p=i/32;
        q=i%32;
        if(!check1(p,q))
        {
            prime.push_back(i);
        }
    }
}


inline void factor()
{
    int num;

    for(int i=2;i<=n;i++)
    {
        num=i;
        for(int j=0;prime[j]<=i && num>0;)
        {//printf("%d %d %d\n",i,num,prime[j]);
            if(num<=0)
                break;
            else if(num%prime[j]==0)
                prime_fac[prime[j]]++,num/=prime[j];
            else
                j++;
        }
    }
}

int main()
{
    int t,tcase=1;

    memset(isprime,false,sizeof(isprime));
    bit_mask_sieve();

    t=in<int>();

    while(t--)
    {
        n=in<int>();

        memset(prime_fac,0,sizeof(prime_fac));

        factor();

        vector<int>ans;

        for(int i=2;i<=n;i++)
            if(prime_fac[i])
                ans.pb(i);

        printf("Case %d: %d = ",tcase++,n);

        for(int i=0;i<sz(ans)-1;i++)
            printf("%d (%d) * ",ans[i],prime_fac[ans[i]]);
        printf("%d (%d)\n",ans[sz(ans)-1],prime_fac[ans[sz(ans)-1]]);
    }

    return 0;
}

