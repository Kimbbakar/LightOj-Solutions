/*
 Problem name : 1026 - Critical Links
 Algorithm : Bridge
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 15-Mar-15
 Last Update : 27-Jan-2015
*/

/*
"
    Well you only need the light when it's burning low
    Only miss the sun when it starts to snow
    Only know you love her when you let her go

    Only know you've been high when you're feeling low
    Only hate the road when you’re missin' home
    Only know you love her when you let her go
    And you let her go

    Staring at the bottom of your glass
    Hoping one day you'll make a dream last
    But dreams come slow and they go so fast

    You see her when you close your eyes
    Maybe one day you'll understand why
    Everything you touch surely dies

    But you only need the light when it's burning low
    Only miss the sun when it starts to snow
    Only know you love her when you let her go

    Only know you've been high when you're feeling low
    Only hate the road when you're missin' home
    Only know you love her when you let her go

    Staring at the ceiling in the dark
    Same old empty feeling in your heart
    'Cause love comes slow and it goes so fast
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

/******* ! Code start from here ! *******/


int vist[10008] ;
vector<int>aj_list[10005];
vector<pair<int,int> > ans;
int n,m,id,u,v;

inline void input()
{
    n=in<int>();

    for(int i=0;i<=n;i++)
        aj_list[i].clear();

    for(int i=0;i<n;i++)
    {
        u=in<int>();

        scanf("(%d)",&m);
        for(int j=0;j<m;j++)
        {
            v=in<int>();

            aj_list[u].pb(v);
            aj_list[v].pb(u);
        }

    }
}

int root;

int dfs(int nod,int p)
{
    vist[nod]=id;
    int mn=id++;
    bool ok=false;
    int l=0,z;


    for(int i=0;i<sz(aj_list[nod] );i++ )
    {
        int k=aj_list[nod][i];
        if(vist[k]==0)
        {
            l++;
            z=dfs(k,nod);
            mn=min(mn,z );
            if(z>vist[nod])
            {
       //         printf("k = %d nod = %d z = %d mn = %d\n",k,nod,z,mn);
                if(nod<k)
                ans.pb(make_pair(nod,k) );
                else
                ans.pb(make_pair(k,nod) );
            }
        }
        else if(k!=p)
            mn=min(mn,vist[k] );
    }
//    printf("**** %d %d %d\n",nod,vist[nod],mn);


//printf("%d %d %d\n",nod,mn,ok);

    return mn;
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;

    while(t--)
    {
        input();

        reset(vist,0);
        id=1;

        ans.clear();

        for(int i=0;i<n;i++)
            if(vist[i]==0)
                dfs(i,-1);

        printf("Case %d:\n",tcase++);

        printf("%d critical links\n",sz(ans) );

        sort(all(ans) );

        for(int i=0;i<sz(ans);i++ )
            printf("%d - %d\n",ans[i].F,ans[i].S);
    }

    return 0;
}



