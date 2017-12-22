/*
 Problem name : 1018 - Brush (IV)
 Algorithm : Bit Mask DP
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



class point
{
public:
    int x,y;
    point()
    {

    }

    bool online(point a,point b)
    {
//      | 1  x    y    |
//      |              |
//      | 1  a.x  a.y  | = 0
//      |              |
//      | 1  b.x  b.y  |

        if( ( ( (a.x*b.y) - (a.y*b.x) ) - x * (b.y-a.y ) + y * ( b.x-a.x) ) ==0 )
            return true;
        return false;
    }
};

int dp[1<<16];
int take[1<<16];
point s[20];
int info[20][20];
int cc,n;

inline void call_me_may_be()
{
    reset(info,0);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            on(info[i][j],i);
            on(info[i][j],j);
            on(info[j][i],i);
            on(info[j][i],j);
            for(int k=0;k<n;k++)
            {
                if(!(k==i || k==j) &&  s[i].online(s[j],s[k]))
                {
                    on(info[i][j],k);
                    on(info[i][j],k);
                    on(info[j][i],k);
                    on(info[j][i],k);
                }
            }
        }
    }
}


int re(int mask)
{
    //printf("--> %d\n",mask);pause
    if(mask == (1<<n)-1) return 0;

    if(take[mask]==cc) return dp[mask];

    int &r=dp[mask],smpl;
    bool got=true;

    r=inf;

    for(int i=0;i<n;i++)
    {

        if(!check(mask,i))
        {
            for(int j=i+1;j<n;j++)
            {
                if(!check(mask,j))
                {
                    smpl=mask;

                    smpl=smpl|info[i][j];

                    r=min(r,1+re(smpl));

                    got=false;
                }

            }
            if(got)
            {
                smpl=mask;
                on(smpl,i);
                r=min(r,1+re(smpl));
            }
            break;
        }

    }

    take[mask]=cc;

    return r;

}

int main()
{
    int t,tcase=1;

    t=in<int>();
    cc=1;

    reset(dp,0);
    reset(take,0);

    while(t--)
    {
        n=in<int>();

        for(int i=0;i<n;i++)
        {
            s[i].x=in<int>();
            s[i].y=in<int>();
        }

        call_me_may_be();
      //  printf("** %d\n",(1<<n)-1);
        printf("Case %d: %d\n",tcase++,re(0));

        cc++;
    }
    return 0;
}


