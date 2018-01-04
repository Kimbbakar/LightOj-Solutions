/*
 Problem name : 1418 - Trees on My Island
 Algorithm : Pick's Theorem
 Contest/Practice :
 Source : Light oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 21-Feb-15
 Last Update : 27-Jan-2015
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

    while(b)
    {
        a=a%b;
        swap(a,b);
    }

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

/*...... ! Code start from here ! ......*/

class data
{
public:
    ll x,y;
    void ip()
    {
        x=in<ll>();
        y=in<ll>();
    }
};

data ara[10008];

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
//        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif


    double area;
    ll b;
    int n;

    int t,tcase=1;

    t=in<int>();

    while(t--)
    {
        n=in<int>();


        ara[0].ip();
        ara[n]=ara[0];
        area=0,b=0;

        for(int i=1;i<n;i++)
        {
            ara[i].ip();

            area+=((ara[i-1].x*ara[i].y )-(ara[i-1].y*ara[i].x ) );
            b+=gcd(abs(ara[i-1].x-ara[i].x),abs(ara[i-1].y-ara[i].y) );
        }
        area+=((ara[n-1].x*ara[n].y )-(ara[n-1].y*ara[n].x ) );
        b+=gcd(abs(ara[n-1].x-ara[n].x),abs(ara[n-1].y-ara[n].y) );

        area=fabs(area/2.0);

        ll ans=area+1-(b)/2;

        printf("Case %d: %lld\n",tcase++,ans);
    }

    return 0;
}

