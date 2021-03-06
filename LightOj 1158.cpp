// Problem name : 1158 - ANAGRAM DIVISION
// Algorithm : Bit Mask DP
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself, people also start to believe in you
// Date : 22-Oct-14

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
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
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

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! ......

int dp[1<<10][1002];
char s[12];
int sz,d,ch,smpl,prv;


int re(int mark,int mdv)
{
//    printf("%d %d\n",mark,mdv);
    if(mark==(1<<sz)-1)
        return (mdv==0)?1:0;

    int &r=dp[mark][mdv];

    if(r!=-1) return r;

    r=0;

    ch;
    smpl;
   	prv='X';

    for(int i=0;i<sz;i++)
    {
        ch=check(mark,i);

        if(ch==false && s[i]!=prv)
        {
            smpl=mark;
            smpl=on(smpl,i);
            r+=re(smpl,(mdv*10+(s[i]-48))%d);
        	prv=s[i];
        }
    }

    return r;
}

int main()
{
    int t,tcase=1;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s %d",s,&d);

        sort(s,s+strlen(s));

        sz=strlen(s);

        memset(dp,-1,sizeof(dp));

        printf("Case %d: %d\n",tcase++,re(0,0));
    }
    return 0;
}

