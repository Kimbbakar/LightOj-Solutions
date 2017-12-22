/*
 Problem name : 1106 - Gone Fishing
 Algorithm : DP
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 09-Nov-12
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
#define check(x,w) (x&(1<<w))
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


int dp[26][16*12+5];
int n,h,mx;

int f[26];
int t[26];
int d[26];

int re(int pos,int minute)
{
    if(pos>=n || minute<0) return 0;

    int &r=dp[pos][minute];

    if(r!=-1) return r;

    r=0;
    int fish=0,tmp;

    r=max(r,fish+re(pos+1,minute-t[pos] ) );

    for(int i=1,j=0;i<=minute;i++,j++)
    {
        if(f[pos]-d[pos]*j>0)
        {
            fish+=(f[pos]-d[pos]*j);
        }

        r=max(r,fish+re(pos+1,minute-i-t[pos] ) );
    }

    return r;
}

void print_sol(int pos,int minute,int cfish)
{
    if(pos>=n ) return ;

    int fish=0;

    if(cfish==0)
    {
        if(pos+1==n)
        printf("0\n");
        else
        {
            printf("0, ");
            print_sol(pos+1,minute-t[pos],cfish);
        }
        return ;
    }

    for(int i=minute;i>=0;i--)
    {
        fish=0;
        for(int j=1,k=0;j<=i;j++,k++)
        {
            if(f[pos]-d[pos]*k>0)
            {
                fish+=(f[pos]-d[pos]*k);
            }
        }
        //printf("Hi pos=%d %d %d %d\n",pos,fish,dp[pos+1][minute-i-t[pos]],i*5);
        if(cfish==fish+re(pos+1,minute-i-t[pos]) )
        {
            if(pos+1==n)
                printf("%d\n",i*5);
            else
            {
                printf("%d, ",i*5);
                print_sol(pos+1,minute-i-t[pos],cfish-fish);
            }
            break;
        }
    }

}


int main()
{
    int te,tcase=1;

    te=in<int>();

    while(te--)
    {
        n=in<int>();
        h=in<int>();
        h=h*12;

        for(int i=0;i<n;i++)
            f[i]=in<int>();
        for(int i=0;i<n;i++)
            d[i]=in<int>();
        for(int i=0;i<n-1;i++)
            t[i]=in<int>();

        printf("Case %d:\n",tcase++);

        reset(dp,-1);

        mx=re(0,h);

        print_sol(0,h,mx);

        printf("Number of fish expected: %d\n",mx);

    }
    return 0;
}
