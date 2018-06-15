
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


/*
max flow (dinitz algorithm)
works on undirected graph
can have loops, multiple edges, cycles
*/

#define MAXN 20409
#define MAXE 20000*2*4+100
#define SET(x) reset(x,-1)
#define i64 int
#define INF inf
 
int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], Next[MAXE], to[MAXE];

inline void init(int _src, int _snk, int _n) {
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(fin);
}

inline void add(int u, int v, int _cap) {
    to[nEdge] = v, cap[nEdge] = _cap, flow[nEdge] = 0;
    Next[nEdge] = fin[u], fin[u] = nEdge++;
    /*
        If graph is directed, _cap = 0 from here.
    */
    _cap = 0;
    to[nEdge] = u, cap[nEdge] = _cap, flow[nEdge] = 0;
    Next[nEdge] = fin[v], fin[v] = nEdge++;
}
 
bool bfs( ) {
    int st, en, i, u, v;
    SET(dist);
    dist[src] = st = en = 0;
    Q[en++] = src;  
    while(st < en) { 
        u = Q[st++]; 
        for(i=fin[u]; i>=0; i=Next[i]) {
            v = to[i]; 
            if(flow[i] < cap[i] && dist[v]==-1) {
                dist[v] = dist[u]+1;
                Q[en++] = v;
            }
        }
    }  
    return dist[snk]!=-1;
}
 
int dfs(int u, int fl) { 
 
    if(u==snk or fl==0) return fl;
 
    for(int &e=pro[u], v, df; e>=0; e=Next[e]) {
        v = to[e]; 
        if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
            df = dfs(v, min(cap[e]-flow[e], fl));  
            if(df>0) {
                flow[e] += df;  
                flow[e^1] -= df; 
                return df;
            }
        }
    }
    return 0;
}

i64 dinitz() {
    i64 ret = 0;
    int df;
    while(bfs()) {
        for(int i=1; i<=nNode; i++) pro[i] = fin[i];
        while(true) {
            df = dfs(src, INF); 
            if(df) ret += (i64)df; 
            else break;
        }
    } 
    return ret;
}

int sp(int x,int y,int m){
    return (x-1)*m+y+1;
} 

int x[] = {0,1};
int y[] = {1,0};

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
//        freopen ( "E:/Code/out.txt", "w", stdout );
    #endif

    int t,tcase=1,n,m,k,u,v;

    in(t);
    char s[102];

    while(t--){
        in(n),in(m) ;
        k = 0;

        init(1,2,n*m*2+10);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                add(sp(i,j,m)*2,sp(i,j,m)*2 + 1,1) ; 

                if(i==1 or j==1 or i==n or j==m) 
                    add(sp(i,j,m)*2+1,snk ,1 );                                        

                for(int _k=0;_k<2;_k++){
                    int nX = x[_k] +i;
                    int nY = y[_k] +j;
                
                    if(nX<1 or nX>n) continue;
                    if(nY<1 or nY>m) continue;

                    add(sp(i,j,m)*2+1,sp(nX,nY,m)*2,1 );
                    add(sp(nX,nY,m)*2+1,sp(i,j,m)*2,1 );

                }
            }
        }

        for(int i=1;i<=n;i++){
            scanf("%s",s);// what_is(s)

            for(int j=1;j<=m;j++){
                if(s[j-1]=='*' ){  
                    add(src,sp(i,j,m)*2,1 );
                    k++;
                }
            }
        }

        pf("Case %d: %s\n",tcase++,(dinitz()==k?"yes":"no" ) );

    }


    return 0;
}



