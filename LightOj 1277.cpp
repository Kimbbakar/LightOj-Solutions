/*
 Problem name : 1277 - Looking for a Subsequence
 Algorithm : LIS
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 24-Nov-14
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
#define on(x,w)         x=x|(1<<w)
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

int dp[100009];
int input[100009];
int mark[100009];
int n,q,m,top;

inline void LIS()
{
    dp[1]=input[n];
    mark[n]=1;
    top=1;

    for(int i=n-1;i>=1;i--)
    {
        int l=1,r=top+1;

        while(l<r)
        {
            int mid=(l+r)>>1;

            if(input[i]<dp[mid]) l=mid+1;
            else r=mid;
        }

        dp[ r ]=input[ i ];
        if( r== top+1) top++;
        mark[ i ] = r;
    }
}


inline void print_res()
{
    int last=- (1<<30);
    for(int i=1;i<=n,m>0;i++)
    {
        if(mark[i]>=m && last<input[i] )
        {
            printf("%d",input[i]);
            m--;
            last=input[i];
            if(m>0)
                printf(" ");
        }
    }
    printf("\n");
}


int main()
{
    int t,tcase=1;

    t=in<int>();

    while(t--)
    {
        n=in<int>();
        q=in<int>();

        for(int i=1;i<=n;i++)
            input[i]=in<int>();

        LIS();

//        for(int i=1;i<=n;i++)
//            printf("%d ",mark[i]);

        printf("Case %d:\n",tcase++);
        while(q--)
        {
            m=in<int>();

            if(top<m)
                printf("Impossible\n");
            else
                print_res();
        }
    }
    return 0;
}

