/*
 Problem name : 1302-Independent Attacking Zones
 Algorithm : Matrix chain multiplecation
 Contest/Practice :
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 19-Nov-14
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

ll dp[75][75];
int take[75][75];
int cc;
char s[75];
int red,blk;

inline void c(int id1,int id2,int id3)
{
    red=0,blk=0;
    if(s[id1]=='R') red++;
    if(s[id2]=='R') red++;
    if(s[id3]=='R') red++;
    if(s[id1]=='B') blk++;
    if(s[id2]=='B') blk++;
    if(s[id3]=='B') blk++;
}


ll re(int l,int r)
{
//    printf("%d %d \n",l,r);
    if(r<l) return 1;

    ll &res=dp[l][r];

    if(take[l][r]==cc) return dp[l][r];

    res=0;

    for(int i=l+1;i<r;i++)
    {
        for(int j=i+1;j<=r;j++)
        {
            c(l,i,j);
            if( (red==0 && blk==3) || (red==1 && blk==2) )
            {//printf("** %d %d %d\n",l,i,r);pause
                res+=(re(l+1,i-1)*re(i+1,j-1)*re(j+1,r) );
            }
        }

    }

    take[l][r]=cc;

    return res;
}

int main()
{
    int t,tcase=1;

    t=in<int>();

    reset(dp,0);
    reset(take,0);
    cc=1;

    while(t--)
    {
        scanf("%s",&s);

        printf("Case %d: %lld\n",tcase++,re(0,strlen(s)-1));

        cc++;
    }
    return 0;
}


