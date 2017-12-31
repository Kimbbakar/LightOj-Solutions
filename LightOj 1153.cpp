 /*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
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


int cap[105][105];
int visit[105];
int n,c,t,s,u,v,w,p;
bool ok;
int mn,ans;
int path[105];
vector<int>aj_list[105];

inline void input()
{
    n=in<int>();
    s=in<int>();
    t=in<int>();
    c=in<int>();

    for(int i=0;i<=100;i++)
        aj_list[i].clear();


    for(int i=0;i<c;i++)
    {
        u=in<int>();
        v=in<int>();
        w=in<int>();

        cap[u][v]+=w;
        cap[v][u]+=w;

        aj_list[u].pb(v);
        aj_list[v].pb(u);
    }
}

void dfs(int nod,int v)
{
    if(ok) return;

    visit[nod]=c;

    if(nod==t)
    {
        ok=true;

        ans+=v;
        //what_is(p)
        for(int i=0;i<p-1;i++)
        { //printf("%d ",path[i] );
            cap[path[i]][path[i+1] ]-=v;
            cap[path[i+1] ][path[i]]+=v;
        } //printf("\n");
        p=1;//pause
        return;
    }

    for(int i=0;i<sz(aj_list[nod] ) && !ok;i++ )
    {
        int k=aj_list[nod][i];

        if(visit[k]!=c && cap[nod][k]>0 )
        {
            path[p++]=k;
            dfs(k,min(v,cap[nod][k]) );
            p--;
        }
    }

}



int main()
{
 //    std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;


    while(t--)
    {
        reset(cap,0);

        input();

        reset(visit,0);


        ans=0,p=c=1;
        path[0]=s;

        ok=true;

        while(ok)
        {
            ok=false;

            dfs(s,100000000); c++; //what_is(ok)
            p=1;
        }

        printf("Case %d: %d\n",tcase++,ans);
    }

    return 0;
}

