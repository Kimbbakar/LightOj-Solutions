/*
 Problem name : 1349 - Aladdin and the Optimal Invitation
 Algorithm : Ternary Search
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 10-Dec-14
*/

#include<bits/stdc++.h>

#define pause           system("pause");
#define rep(i,n)        for(int i=0; i<(int)n; i++)
#define repv(i,n)       for(int i=n-1; i>=0; i--)
#define repl(i,n)       for(int i=1; i<=(int)n; i++)
#define replv(i,n)      for(int i=n; i>=1; i--)
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
#define on(x,w)         x|(1<<w)
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

class nod
{
public:
    int x,y,p;

    nod()
    {

    }
};


nod kp[50008];
int n,m,q,x,y;

inline ll cal1(int x)
{
    ll ans=0;

    for(int i=0;i<q;i++)
    {
        ans+= (abs(x-kp[i].x ) ) * kp[i].p;
    }

    return ans;
}

inline ll cal2(int y)
{
    ll ans=0;

    for(int i=0;i<q;i++)
    {
        ans+= (ll) (abs(y-kp[i].y) ) * (ll) kp[i].p;
    }

    return ans;
}

inline ll ternary_search_2()
{
    int l=1,r=m;
    ll ans=1LL<<60;

//    int d=24;

    while(l<=r)
    {
        int mid1=(2*l+r)/3;
        int mid2=(l+2*r)/3;


        ll res1=cal2(mid1);
        ll res2=cal2(mid2);

        if(ans>res1)
        {
            ans=res1;
            y=mid1;
        }

        if(ans>res2)
        {
            ans=res2;
            y=mid2;
        }

        if(res1<res2)
        {
            r=mid2-1;
        }
        else
            l=mid1+1;
    }

    return ans;
}


inline int ternary_search_1()
{
    int l=1,r=n;

    ll ans=1LL<<60;

    int d=24;

    while(l<=r)
    {
        int mid1=(2*l+r)/3;
        int mid2=(l+2*r)/3;


        ll res1=cal1(mid1);
        ll res2=cal1(mid2);

        if(ans>res1)
        {
            ans=res1;
            x=mid1;
        }

        if(ans>res2)
        {
            ans=res2;
            x=mid2;
        }

        if(res1<res2)
        {
            r=mid2-1;
        }
        else
            l=mid1+1;
    }

    return ans;
}


int main()
{

    int t,tcase=1;

    t=in<int>();

    while(t--)
    {
        n=in<int>();
        m=in<int>();
        q=in<int>();

        for(int i=0;i<q;i++)
        {
            kp[i].x=in<int>();
            kp[i].y=in<int>();
            kp[i].p=in<int>();
        }



        ternary_search_1();
        ternary_search_2();

        int x1=x,y1=y;

        ll res=1LL<<60;
        for(int i=x+1;i>=x-1;i--)
        {
            int s=cal1(i);
            if(res>s && i>0 && i<=n )
                x1=i,res=s;
        }

        res=1LL<<60;

        for(int i=y+1;i>=y-1;i--)
        {
            int s=cal2(i);
            if(res>s && i>0 && i<=m )
                y1=i,res=s;
        }


        printf("Case %d: %d %d\n",tcase++,x1,y1);
    }

    return 0;
}

