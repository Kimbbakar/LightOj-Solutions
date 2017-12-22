/*
 Problem name : 1370 - Bi-shoe and Phi-shoe
 Algorithm :Sieve
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 04-Sep-15
 Last Update : 25-Mar-2015
*/

/*
	So close no matter how far
	Couldn't be much more from the heart
	Forever trusting who we are
	And nothing else matters

	Never opened myself this way
	Life is ours, we live it our way
	All these words I don't just say
	And nothing else matters

	Trust I seek and I find in you
	Every day for us something new
	Open mind for a different view
	And nothing else matters

	Never cared for what they do
	Never cared for what they know
	But I know

	So close no matter how far
	Couldn't be much more from the heart
	Forever trusting who we are
	And nothing else matters

	Never cared for what they do
	Never cared for what they know
	But I know

	I never opened myself this way
	Life is ours, we live it our way
	All these words I don't just say
	And nothing else matters

	Trust I seek and I find in you
	Every day for us something new
	Open mind for a different view
	And nothing else matters

	Never cared for what they say
	Never cared for games they play
	Never cared for what they do
	Never cared for what they know
	And I know

	So close no matter how far
	Couldn't be much more from the heart
	Forever trusting who we are
	No nothing else matters


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

class nod
{
public:
    int val,idx;

    bool operator < (const nod &a) const
    {
        if(val!=a.val)
            return val<a.val;
        return idx<a.idx;
    }

};

#define MAX 1000050
int prime[79000],c=0 ;

int isprime[MAX/32 + 5];

#define on1(x,w)  isprime[x]=isprime[x]|(1<<w)
#define check1(x,w) (isprime[x]&(1<<w))

int p,q,cnt;


inline void bit_wise_sieve()
{
    memset(isprime,0,sizeof(isprime) );
    cnt=0;
    prime[c++]=2 ;
    int ls=sqrt(MAX);
    for(int i=3;i<=MAX;i+=2)
    {
        p=i/32;
        q=i%32;
        if(!check1(p,q))
        {
            prime[c++]=i ;
            for(ll j=(ll) i*(ll)i;i<=ls && j<=(ll) MAX;j+=(2*(ll) i) )
            {
                p=(j)/32;
                q=(j)%32;
                on1(p,q);
            }
        }
    }

}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
//        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    bit_wise_sieve();


    int t,tcase=1;
    int n,num;
    ll res;

    in(t);

    while(t--)
    {
        res=0;

        in(n);

        for(int i=0;i<n;i++)
        {
            in(num);

            int get=lower_bound(prime,prime+c,num+1 )-prime;

            res+=(ll) (prime[get] );
        }

        pf("Case %d: %lld Xukha\n",tcase++,res);

    }



    return 0;
}


