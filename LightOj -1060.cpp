/*
 Problem name : 1060 - nth Permutation
 Algorithm : Generating permutaion
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 21-Nov-14
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

ll dp[1<<20];
int take[1<<20];
char s[25];
int len,n,cc;

ll re(int mask)
{//printf("%d\n",mask);
    if(mask==(1<<len)-1) return 1;

    if(take[mask]==cc) return dp[mask];

    ll &res=dp[mask];

    take[mask]=cc;
    res=0;
    int smpl;

    for(int i=0;i<len;i++)
    {
        if(!check(mask,i))
        {
            if(i>0)
            {
                if(s[i]==s[i-1] && !check(mask,i-1)) continue;
                smpl=mask;
                on(smpl,i);

                res+=re(smpl);
            }

            else{
                smpl=mask;
                on(smpl,i);

                res+=re(smpl);
            }
        }
    }
    return res;
}

void print_path(int mask,ll l)
{
    if(mask==(1<<len)-1) return;


    ll res=0,k=0;
    int smpl;

    for(int i=0;i<len;i++)
    {
        if(!check(mask,i))
        {
            if(i>0)
            {
                if(s[i]==s[i-1] && !check(mask,i-1)) continue;
                smpl=mask;
                on(smpl,i);

                res+=re(smpl);
                if(res>=l)
                {
                    printf("%c",s[i]);
                    print_path(smpl,l-k);
                    return;
                }
                k=res;
            }

            else{
                smpl=mask;
                on(smpl,i);

                res+=re(smpl);
                if(res>=l)
                {
                    printf("%c",s[i]);
                    print_path(smpl,l-k);
                    return;
                }
                k=res;
            }
        }
    }
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
        scanf("%s %d",s,&n);
        len=strlen(s);

        sort(s,s+len);

        ll ans=re(0);

        printf("Case %d: ",tcase++);
        if(ans<n)
            printf("Impossible\n");
        else
        {
            print_path(0,(ll)n );
            printf("\n");
        }

        cc++;
    }
    return 0;
}

