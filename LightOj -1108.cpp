/*
 Problem name : 1108 - Instant View of Big Bang
 Algorithm : SCC + Bellman Ford
 Contest/Practice : Off Line Practice
 Source : Light OJ
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 26-Mar-15
 Last Update : 25-Mar-2015
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

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}


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

class data
{
public:
    int u,v,w;
     data(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

int visit[1006],cost[1006];
int id,mrk;
vector<data>aj_list[1005];
int u,v,w,n,m;

void dfs(int nod)
{
    visit[nod]=1;
    mrk=max(mrk,nod);//printf("%d\n",nod);
    for(int i=0;i<sz(aj_list[nod] );i++)
    {
        int k=aj_list[nod][i].v;
        if(!visit[k])
            dfs(k);
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
        n=in<int>();
        m=in<int>();

        reset(visit,0);
        reset(visit,inf);
        mrk=-1;
        fill(aj_list,aj_list+n+5,vector<data>() );

        for(int i=0;i<m;i++)
        {
            u=in<int>();
            v=in<int>();
            w=in<int>();

            aj_list[v].pb(data(v,u,w) );
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<sz(aj_list[j]);k++ )
                {
                    u=aj_list[j][k].u;
                    v=aj_list[j][k].v;
                    w=aj_list[j][k].w;

                    if(cost[u]+w<cost[v])
                        cost[v]=cost[u]+w;
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<sz(aj_list[j]);k++ )
            {
                u=aj_list[j][k].u;
                v=aj_list[j][k].v;
                w=aj_list[j][k].w;

                if(cost[u]+w<cost[v] && !visit[v] )
                {
                    dfs(u);
                }
            }
        }

        printf("Case %d :",tcase++);

        if(mrk==-1)
            printf(" impossible\n");
        else
        {
            for(int i=0;i<=mrk;i++)
                if(visit[i])
                    printf(" %d",i);
            printf("\n");
        }

    }

    return 0;
}

