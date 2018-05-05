 /*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
 Last Update : 25-Mar-2015
*/

#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000000007
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())//vector must be sorted
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
#define sf              scanf
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

    while(b) b ^= a ^= b ^= a %= b;
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
 

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}

#define debug(args...) {dbg,args; cerr<<endl;}

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int nextInt() { int n; scanf("%d", &n); return n; }
long long nextLong() { long long n; scanf("%lld", &n); return n; }
void print(int n){ printf("%d", n); }
void println(int n){ printf("%d\n", n); }
void println(long long n){ printf("%lld\n", n); }



template<class T>
inline int in(register T& num)
{
    register char c=0;
    num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    num=n?-num:num;
    return 1;
}

/******* ! Code start from here ! *******/

#define MNODE 55 
#define MEDGE 5005 

ll cost[MEDGE],cap[MEDGE],flow[MEDGE],mark[MNODE];
int path[MNODE];
int _source,_sink;
int _node,_edge;
vector<pair<int,int> > edges;

inline void init(int n, int s,int d ) {
    _node   = n;
    _source = s;
    _sink   = d;
    _edge = 0;
    edges.clear();
    reset(cap,0);
    reset(flow,0);
    reset(cost,0);
}

/*
    u = from
    v = to
    f = flow 
    c = cost
*/

void addEdge(int u,int v,int f,int c){
    cost[_edge] = c;
    edges.pb({u,v} );
    cap[_edge] = f;
    flow[_edge] = 0;
    _edge++;

    cost[_edge] = - c;
    edges.pb({v,u} );
    cap[_edge] = 0;  
    flow[_edge] = 0;
    _edge++;
}
 
bool bellmanFord()
{
    reset(path,-1);
    for(int i=0;i<=_node;i++)
        mark[i]=inf;
    mark[_source]=0; 
    bool ok=true;

    for(int _t=1;_t<=_node;_t++ ){
        ok=false;
 
        for(int i=0;i<_edge;i++){
            if(mark[edges[i].S]> (cost[i] + mark[edges[i].F] )&& cap[i] ){
                mark[edges[i].S] = cost[i] + mark[edges[i].F];
                ok=true;
                path[edges[i].S]=i;
            }            
        }
    

  
        if(!ok) break;
    }
 
    return (mark[_sink]<(inf) );
}

ll minFlow(){
    ll mnfl = inf;
    int y=_sink;
    while(path[y]!=-1){   
        mnfl = min(cap[path[y]],mnfl);
        y=edges[ path[y] ].F ;
    }    

    return mnfl;
}

ll FlowCost( ll mnfl ) {

    ll fcost = 0;

    int y=_sink;
    while(path[y]!=-1){
        cap[path[y]]-=mnfl;   
        cap[path[y]^1]+=mnfl;   

        flow[path[y]]+=mnfl;   
        flow[path[y]^1]-=mnfl;   

        fcost+=(mnfl*cost[path[y] ] );
        y=edges[ path[y] ].F ;
    }     

    return fcost;
}

pair<ll,ll> mcmf(ll p){
    ll ans = 0;
    ll cnt = 0;
    while(bellmanFord()  and cnt<p)
    {
        int mnfl = minFlow() ;
        if(cnt+mnfl>p) 
            mnfl = p-cnt;
        cnt+=mnfl;
        ans+=FlowCost(mnfl);

    }    

    return {cnt,ans};
}



int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
      //  freopen ( "E:/Code/out.txt", "w", stdout );
    #endif


    int t,tcase=1;
 
    int n,m,u,v,w,f,p;
    in(t);

    while(t--){
        in(n),in(m),in(p);

        init(n,1,n);

        while(m--){
            in(u),in(v),in(f),in(w); 

            addEdge(u,v,f,w);
            addEdge(v,u,f,w);
        }

        pair<ll,ll>res = mcmf(p);

        pf("Case %d: ",tcase++);  
 
        if(res.F<p)
            pf("impossible\n");
        else pf("%lld\n",res.S);
    }



    return 0;
}



