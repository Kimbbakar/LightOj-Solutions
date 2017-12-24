/*
 Problem name : 1170 - Counting Perfect BST
 Algorithm : Catalan Number/Counting/DP/B-Search
 Contest/Practice :
 Source : LightOJ
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 10-Feb-15
 Last Update : 27-Jan-2015
*/

/*
" How am I supposed to be everything they
  expect me to be when
  I feel so alone,
  because I left my heart at home
  So, God, give me the strength to do what
  you created me to do. "
                    ~ Kellin Quinn
*/

#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             100000007
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
    return fast_pow(n,(ll) mod-2);
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

/*...... ! Code start from here ! ......*/

ll ara[105005];
ll kp[105005];
ll c[105005];
int cnt;

inline void pre_cal()
{
    int j=0;
    for(ll i=2;i<=100000;i++)
    {
        ll tmp=i*i;
        while(tmp<=(ll)10000000000)
        {
            ara[j++]=tmp;
            tmp*=i;
        }
    }

    sort(ara,ara+j);

    cnt=0;

    kp[cnt++]=ara[0];

    for(int i=1;i<j;i++)
    {
        if(ara[i]!=ara[i-1])
        {
            kp[cnt++]=ara[i];
        }
    }

    c[0]=0,c[1]=1;

    for(int i=2;i<=cnt;i++)
    {
        c[i]=mod_v(c[i-1]*mod_v( (4*(ll)i-2 ) * modInverse( (ll)i+1 ) ) ) ;
    }


}




int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
    #endif

    pre_cal();


    int t=in<int>(),tcase=1;
    ll a,b;

    while(t--)
    {
        int l=0,r=cnt-1,mid;

        int ls=cnt,rs=0;

        a=in<ll>();
        b=in<ll>();

        while(l<=r)
        {
            mid=(l+r)>>1;

            if(kp[mid]>=a)
            {
                ls=min(ls,mid);
                r=mid-1;
            }
            else
                l=mid+1;
        }

        l=0,r=cnt-1;

        while(l<=r)
        {
            mid=(l+r)>>1; //printf("%d %d %d %lld\n",l,r,mid,kp[mid]);

            if(kp[mid]<=b)
            {
                rs=max(rs,mid+1);
                l=mid+1;
            }
            else
                r=mid-1;
        }
       // what_is(ls) what_is(rs)
        printf("Case %d: %lld\n",tcase++,c[rs-ls]);

    }

    return 0;
}


