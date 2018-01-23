 /*
 Problem name : 1161 - Extreme GCD
 Algorithm : inclusion exclusion
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 16-Aug-15
 Last Update : 25-Mar-2015
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


//template<class T>
//inline int in(register T& num)
//{
//    register char c=0;
//    num=0;
//    bool n=false;
//    while(c<33)c=getchar();
//    while(c>33){
//        if(c=='-')
//            n=true;
//        else num=num*10+c-'0';
//        c=getchar();
//    }
//    num=n?-num:num;
//    return 1;
//}
template<class T>
 inline int in(register T& x) {
    x=0;
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return x=flag * ret;
}

/******* ! Code start from here ! *******/

ll nCr[10005][5];
int val[10005],cnt[10005],mark[10005];
int kp[10004];


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
        freopen ( "out.txt", "w", stdout );
    #endif

    reset(nCr,0);

    nCr[0][0]=1;

    for(int i=1;i<=10000;i++)
    {
        nCr[i][0]=1;

        for(int j=1;j<=min(i,4);j++)
        {
            nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];
        }
    }

    for(int i=0;i<=10000;i++)
    {
        val[i]=1;
        mark[i]=1;
        cnt[i]=0;
    }

    for(int i=2;i<=10000;i++)
    {
        if(mark[i])
        {
            for(int j=i;j<=10000;j+=i)
            {
                cnt[j]++;
                val[j]*=i;
                mark[j]=0;
            }
        }
    }

    int x=0;
    int stor[10005];

    for(int i=2;i<=10000;i++)
    {
        if(val[i]==i)
        {
            stor[x++]=i;
        }
    }


    int t,tcase=1,n;

    in(t);
    int mx;
    int num;

    while(t--)
    {
        in(n);
        mx=0;

        for(int i=0;i<=10000;i++)
            kp[i]=0;
        int c=0;

        for(int i=0;i<n;i++)
        {
            in(num);
            if(!num) continue;
            c++;
            for(int j=1;j<=sqrt(num);j++)
            {
                if(num%j==0)
                {
                    kp[j]++;
                    if(num/j!=j)
                        kp[num/j]++;

                }
            }
            mx=max(mx,num);
        }
        n=c;

        ll res=nCr[n][4];

        //mx=sqrt(mx);

        for(int i=0;i<x && stor[i]<=mx;i++ )
        {
            if(kp[stor[i] ]<4) continue;
            if(cnt[stor[i] ]&1)
                res-=(nCr[kp[stor[i] ]][4] );
            else
                res+=(nCr[kp[stor[i] ]][4] );
        }



        pf("Case %d: %lld\n",tcase++,res);
    }



    return 0;
}
