/*
 Problem name : 1117 - Helping Cicada
 Algorithm : Inclusion-Exclusion
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
 Last Update : 25-Mar-2015
*/

/*
    Hey brother, there’s an endless road to re-discover.
    Hey sister, know the water's sweet but blood is thicker.
    Oh, if the sky comes falling down for you,
    There’s nothing in this world I wouldn’t do.

    Hey brother, do you still believe in one another?
    Hey sister, do you still believe in love, I wonder?
    Oh, if the sky comes falling down for you,
    There’s nothing in this world I wouldn’t do.

    What if I'm far from home?
    Oh, brother I will hear you call.
    What if I lose it all?
    Oh, sister I will help you out!
    Oh, if the sky comes falling down for you,
    There’s nothing in this world I wouldn’t do.

    Hey brother, there’s an endless road to re-discover.
    Hey sister, do you still believe in love, I wonder?
    Oh, if the sky comes falling down for you,
    There’s nothing in this world I wouldn’t do.

    What if I'm far from home?
    Oh, brother I will hear you call.
    What if I lose it all?
    Oh, sister I will help you out!
    Oh, if the sky comes falling down for you,
    There’s nothing in this world I wouldn’t do.


*/



#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
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
#define lcm(x,y)        (abs(x) /gcd(x,y))* abs(y)
#define on(x,w)         x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define sf              scanf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";

typedef long long ll;
typedef unsigned long long llu;

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
inline T gcd(T a,T b)
{
    a=abs(a);
    b=abs(b);

    while(b) b ^= a ^= b ^= a %= b;
    return a;
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

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}


template<class T>
inline int in(register T& num)
{
    register char c=0;
    num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    num=n?-num:num;
    return 1;
}

/******* ! Code start from here ! *******/

#define MAX 70000

int isprime[MAX/32 + 5];
vector<int>prime;

#define on1(x,w)  isprime[x]=isprime[x]|(1<<w)
#define check1(x,w) (isprime[x]&(1<<w))

int p,q,cnt;


inline void bit_wise_sieve()
{
    memset(isprime,0,sizeof(isprime) );
    cnt=0;
    prime.pb(2);
    int ls=sqrt(MAX);
    for(int i=3;i<=MAX;i+=2)
    {
        p=i/32;
        q=i%32;
        if(!check1(p,q))
        {
            prime.pb(i);
            for(ll j=(ll) i*(ll)i;i<=ls && j<=(ll) MAX;j+=(2*(ll) i) )
            {
                p=(j)/32;
                q=(j)%32;
                on1(p,q);
            }
        }
    }

}


ll kp[18];
int c;
ll n,get=0;

void re(int p , ll s,int cnt )
{
    if(s>n) return ;

    if(p==c)
    {
        if(!cnt) return;
        if(cnt&1)
            get-=(n/s);
        else
            get+=(n/s);
        return;
    }

    re(p+1,lcm(s,kp[p]) ,cnt+1 );
    re(p+1,s,cnt );
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;

    in(t);
    int m;
    ll num;

    while(t--)
    {
        in(n);
        in(c);

        for(int i=0;i<c;i++)
        {
            in(kp[i]);

        }



        get=0;
        re(0,1,0);
        n=n+get;

        pf("Case %d: %lld\n",tcase++,n);
    }


    return 0;
}

