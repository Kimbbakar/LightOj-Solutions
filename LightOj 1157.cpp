/*
 Problem name : 1157 - LCS Revisited
 Algorithm : LCS (~_~)
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 26-Nov-14
*/

#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000007
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

int dp[1005][1005];
int nexts1[1005][30];
int nexts2[1005][30];
int keep[1005][1005];

char s1[1005];
char s2[1005];

int sz1,sz2;
//string s1,s2;

int re(int i,int j)
{
    if(i>=sz1 || j>=sz2) return 0;

    int &r=dp[i][j];

    if(r!=-1) return r;

    if(s1[i]==s2[j]) return r=1+re(i+1,j+1);

    else return r=max(re(i+1,j),re(i,j+1) );
}


int re1(int i,int j)
{
    if(i>=sz1 || j>=sz2) return 1;

    int &r=keep[i][j];

    if(r!=-1) return r;

    int info=re(i,j);

    if(info==0) return keep[i][j]=1;

    r=0;

    for(int k=0;k<26;k++)
    {
        int lasts1=nexts1[i][k];
        int lasts2=nexts2[j][k];

        if(re(lasts1,lasts2)==info)
        {
            r+=re1(lasts1+1,lasts2+1);
            r%=mod;
        }
    }

    return r;
}

int track[33];

int main()
{
    int t,tcase=1;

    t=in<int>();

    while(t--)
    {
        scanf("%s",s1);
        scanf("%s",s2);

//        cin>>s1>>s2;

        sz1=strlen(s1);
        sz2=strlen(s2);

        reset(dp,-1);
        reset(keep,-1);

//        re(0,0);

        reset(track,26);

        for(int i=sz1-1;i>=0;i--)
        {
            track[s1[i]-'a']=i;

            for(int j=0;j<26;j++)
                nexts1[i][j]=track[j];
        }

        reset(track,26);

        for(int i=sz2-1;i>=0;i--)
        {
            track[s2[i]-'a']=i;

            for(int j=0;j<26;j++)
                nexts2[i][j]=track[j];
        }

        printf("Case %d: %d\n",tcase++,re1(0,0));
    }
    return 0;
}
