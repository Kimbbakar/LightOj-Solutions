// Problem name : 1064 - Throwing Dice
// Algorithm : DP
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself, people also start to believe in you
// Date : 13-Oct-14

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
    return num;
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

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! ......

ll dp[27][160];
int x,n;
ll c;

ll re(int dice,int sum)
{
    if(dice==n)
    {
        return sum>=x?1:0;
    }

    ll &r=dp[dice][sum];

    if(r!=-1) return r;

    r=0;
    for(int i=1;i<=6;i++)
        r+=re(dice+1,sum+i);
    return r;
}


int main()
{
    int t,tcase=1;
    ll ans,g;
    scanf("%d",&t);

    while(t--)
    {
        reset(dp,-1);

        scanf("%d %d",&n,&x);
        c=fast_pow((ll) 6, (ll) n);

        ans=re(0,0);
        g=gcd(ans,c);
//        printf("%lld %lld %lld\n",ans,c,g);
        printf("Case %d: ",tcase++);
        if(ans%c==0)
            printf("%lld\n",ans/c);
        else
            printf("%lld/%lld\n",ans/g,c/g );

    }

    return 0;
}


