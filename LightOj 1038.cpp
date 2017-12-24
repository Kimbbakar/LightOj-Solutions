/*
 Problem name : 1038 - Race to 1 Again
 Algorithm : Expected Value
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 19-Dec-14
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
#define gcd(x,y)         __gcd(x,y)
#define lcm(x,y)        (x/gcd(x,y))*y
#define on(x,w)         x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||

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

vector<int>divs[100008];
int n;
double dp[100008];
int ok[100008];

double re(int x)
{
    if(x==1) return 0.0;
    if(ok[x]!=-1) return dp[x];

    ok[x]=1;

    dp[x]=0.0;
    double sum=0;
    for(int i=0;i<sz(divs[x])-1;i++ )
    {
        sum+=( re(divs[x][i])+1.0 ) / (1.0 *sz(divs[x] ) )  ;
    }

    dp[x]=(sz(divs[x] ) * sum + 1 ) / (sz(divs[x] )-1);

    return dp[x];

}


int main()
{
    for(int i=0;i<=100000;i++)
    {
        for(int j=1;j<=sqrt(i);j++ )
        {
            if(i%j==0)
            {
                divs[i].pb(j);
                if(j != (i/j))
                    divs[i].pb(i/j);
            }

        }
        sort(all (divs[i] ) );
    }

    reset(ok,-1);

    int t,tcase=1;

    t=in<int>();


    while(t--)
    {
        n=in<int>();

        printf("Case %d: %lf\n",tcase++,re(n));

    }
    return 0;
}

