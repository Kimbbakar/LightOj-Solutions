/*
 Problem name : 1420 - Subsequences forming Strings
 Algorithm : DP
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 27-Apr-15
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

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}


 inline int in() {
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
    return flag * ret;
}

/******* ! Code start from here ! *******/

int dp[105][105][105][3] ;
int done[105][105][105][3]={0},cc=1;

char a[105],b[105],c[105];
int az,bz,cz;

int re(int i,int j,int k,int f)
{
    if(k==cz) return 1;
    if(az==i && bz==j) return 0;

    if(done[i][j][k][f] ==cc) return dp[i][j][k][f];

    done[i][j][k][f]=cc;

    dp[i][j][k][f]=0;

    if(i<az && f!=0)
    {
        if(a[i]==c[k])
            dp[i][j][k][f]=mod_v(dp[i][j][k][f] +re(i+1,j,k+1,2));
        dp[i][j][k][f]=mod_v(dp[i][j][k][f]+re(i+1,j,k,1));
    }

    if(j<bz && f!=1)
    {
        if(b[j]==c[k])
            dp[i][j][k][f]=mod_v(dp[i][j][k][f]+re(i,j+1,k+1,2));
        dp[i][j][k][f]=mod_v(dp[i][j][k][f]+re(i,j+1,k,0));
    }

    return dp[i][j][k][f];
}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in(),tcase=1;

    while(t--)
    {
        scanf("%s",a);
        scanf("%s",b);
        scanf("%s",c);

        az=strlen(a);
        bz=strlen(b);
        cz=strlen(c);

        printf("Case %d: %d\n",tcase++,re(0,0,0,2));

        cc++;
    }


    return 0;
}


