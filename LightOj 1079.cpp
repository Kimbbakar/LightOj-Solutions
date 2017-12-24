/*
 Problem name : 1079 - Just another Robbery
 Algorithm : DP
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 15-Nov-14
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

class bank
{
public:
    int prof;
    double prob;
    bank()
    {

    }
};

double dp[105][10009];
int take[105][10009];
int cc,n;
double rob;
bank info[105];

double re(int pos,int left)
{   //printf("%d %d\n",pos,left);
    if(pos>=n) return (left==0?0.0:111111111.0);

    if(take[pos][left]==cc) return dp[pos][left];

    double &r=dp[pos][left];

    double x=re(pos+1,left-info[pos].prof);

    r=min(x + (1.0-x)*info[pos].prob  ,re(pos+1,left ) );

    take[pos][left]=cc;

    return r;
}

int main()
{
    int t,tcase=1,mx;
    cc=1;

    reset(dp,0.0);
    reset(take,0);

    t=in<int>();

    while(t--)
    {
        scanf("%lf",&rob);
        n=in<int>();
        mx=0;

        for(int i=0;i<n;i++)
        {
            info[i].prof=in<int>();
            mx+=info[i].prof;

            scanf("%lf",&info[i].prob);
        }

        int ans;

        for(int i=mx;i>=0;i--)
        {//printf("*** %lf\n",re(0,i));pause
                if(re(0,i)<=rob )
                {
                    ans=i;
                    break;
                }
        }

        printf("Case %d: %d\n",tcase++,ans);

        cc++;
    }

    return 0;
}
