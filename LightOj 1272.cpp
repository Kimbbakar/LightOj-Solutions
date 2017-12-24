/*
 Problem name : 1272 - Maximum Subset Sum
 Algorithm : Gaussian Elimination
 Contest/Practice :  Off Line Practice
 Source : LightOj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 10-Dec-14
*/

#include<bits/stdc++.h>

#define pause           system("pause");
#define rep(i,n)        for(int i=0; i<(int)n; i++)
#define repv(i,n)       for(int i=n-1; i>=0; i--)
#define repl(i,n)       for(int i=1; i<=(int)n; i++)
#define replv(i,n)      for(int i=n; i>=1; i--)
#define mod             1000000007
#define inf             1<<30
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define F               first
#define S               second
#define sz(x)           ((int)x.size())
#define sqr(x)          ( (x)* (x) )
#define eps             1e-9
#define gcd(x,y)         __gcd(x,y)
#define lcm(x,y)        (x/gcd(x,y))*y
#define on(x,w)         x=x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x))

typedef long long ll;
typedef unsigned long long llu;

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
#  define p(x) 0;
#endif

/*...... ! Code start from here ! ......*/

bool cmp(ll a,ll b)
{
    return a>b;
}

ll v[101];

int main()
{

    int n,ts,tcase=1;

//    printf("%lld\n",fast_pow(2LL ,62LL ));
    ts=in<int>();

    while(ts--)
    {
        n=in<int>();

        for(int i=0;i<n;i++)
        {
                v[i]=in<ll>();
        }

        sort(v,v+n,cmp);

        long long int sig=1;
        int c=1;

        while(sig<=v[0] && c<63)
        sig<<=1LL,c++;

        sig>>=1LL;

        for(int t=0;sig>=1;sig>>=1LL)
        {
                int i=t;

                while(i<n && (v[i]&sig)==0)
                i++;


                if(i>=n)
                continue;

                swap(v[t],v[i]);

                for(int j=0;j<n;++j)
                {
                        if(j!=t && (v[j]&sig)!=0)
                        v[j]=v[j]^v[t];
                }

                t++;

        }


        long long int result=0;

        for(int q=0;q<n;q++)
        {
                result=result^v[q];
        }

        printf("Case %d: %lld\n",tcase++,result);
    }

    return 0;
}
