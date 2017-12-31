/*
 Problem name : 1144 - Ray Gun
 Algorithm : Inclution Explution
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 11-Aug-15
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

#define MAX 1000000

int isprime[MAX+5] ;
int cnt[1000005];




void sieve()
{
    for(int i=2;i<=MAX;i++)
    {
        isprime[i]=1;
        cnt[i]=0;
    }


    for(int i=2;i<=MAX;i++)
    {
        if(isprime[i]==1)
        {
            for(int j=i;j<=MAX;j+=i)
            {
                isprime[j]*=i;
                cnt[j]++;
            }
        }
    }



}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
  //      freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif
    sieve();

    int t,tcase=1;

    int n,m;

    in(t);

    while(t--)
    {
        in(n);
        in(m);

        if(n>m)
            swap(n,m);

        if(!n)
        {
            if(!m)
            pf("Case %d: 0\n",tcase++);
            else
            pf("Case %d: 1\n",tcase++);

        }
        else
        {
            ll res=2+(ll) m*(ll) n ;

            for(int i=2;i<=n;i++)
            {
                if(isprime[i]!=i) continue;
                else
                {
                    if(cnt[i] & 1)
                    {
                        res-=( (ll) (n/i)* (ll) (m/i) );
                    }
                    else
                        res+=( (ll) (n/i)* (ll) (m/i) );
                }
            }

            pf("Case %d: %lld\n",tcase++,res);

        }
    }


    return 0;
}


