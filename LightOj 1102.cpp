/*
 Problem name : 1102 - Problem Makes Problem
 Algorithm : Counting
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 03-Fev-14
 Last Update : 27-Jan-2015
*/

/*
" You say you love rain, but you use an umbrella to walk under it.
  You say you love sun, but you seek shelter when it is shining.
  You say you love wind, but when it comes you close your windows.
  So that's why I'm scared when you say you love me."
                                                    ~ Bob Marley
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
    return fast_pow(n,mod-(ll) 2);
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

int stor[2000008];

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
    #endif

    stor[0]=1;

    for(int i=1;i<=2000000;i++)
    {
        stor[i]=mod_v((ll)stor[i-1]*(ll)i );
    }

    int t,tcase=1;

    int n,k;
    int res1,res2;

    t=in<int>();

    while(t--)
    {
        n=in<int>();
        k=in<int>();

        res1=stor[n+k-1] ;
        res2=mod_v((ll)stor[n] * (ll)stor[k-1] ) ;
        res1=mod_v((ll) res1*modInverse((ll) res2) );

        printf("Case %d: %d\n",tcase++,res1);

    }

    return 0;
}

