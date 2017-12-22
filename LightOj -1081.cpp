/*
 Problem name : 1081 - Square Queries
 Algorithm : RMQ
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 14-Dec-14
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

int rmq [9] [502] [502] ;

int grid[502][502];

int n,q;


int main()
{
    int t,tcase=1;
    int I,J,S;

    t=in<int>();

    while(t--)
    {
        n=in<int>();
        q=in<int>();

        reset(rmq,0);
        reset(grid,0);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                grid[i][j]=in<int>();

        for(int k=0;(1<<k) <=n;k++)
        {
            for(int i=0; i + (1<<k)-1 <n;i++)
            {
                for(int j=0; j+(1<<k)-1 <n;j++)
                {
                    if(k==0)
                        rmq[k][i][j]=grid[i][j];
                    else
                        rmq[k][i][j] = max ( max( rmq [ k-1 ] [ i ] [ j ] , rmq[ k-1 ] [ i ] [ j + (1<<(k-1) ) ] ) , max( rmq [ k-1 ] [ i + (1<<(k-1) )  ] [ j ] , rmq[ k-1 ] [ i + (1<<(k-1) ) ] [ j + (1<<(k-1) )  ] ) ) ;
                }
            }
        }

        printf("Case %d:\n",tcase++);

        while(q--)
        {
            I=in<int>();
            J=in<int>();
            S=in<int>();

            I--;
            J--;

            int k=log2(S);

            int ans=max( max(rmq [ k ] [ I ] [ J ] ,rmq [ k ] [ I ] [ S+J-(1<<k) ] ) ,max( rmq [k] [ I+S-(1<<k) ] [ J ] , rmq [k] [ I+S-(1<<k) ] [ S+J-(1<<k) ]  )  ) ;

            printf("%d\n",ans);
        }

    }

    return 0;
}


