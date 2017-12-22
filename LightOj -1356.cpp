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

#define MAX1 500000

int mark[500005];
vector<int>p;

void prime()
{
    for(int i=4;i<=MAX1;i+=2)
        mark[i]=1;

    p.pb(2);

    for(int i=3;i<=MAX1;i+=2)
    {
        if(!mark[i] )
        {
            p.pb(i);
            for(int j=2*i;j<=MAX1;j+=i )
                mark[j]=1;
        }

    }
}

#define INF 100000000
#define MAX 40005

// Taken from Tarango Khan .

// Runtime O( sqrt(V) *E ) . For more details, look at wiki page

int N, M, E, R, C;
// N = Maximum number of matching possible from left set.

vector< int > Graph[MAX];
vector<int> lst[MAX];
int Left[MAX];
int Right[MAX];
int dist[MAX];
int n;

set<int>st;
inline bool BFS() {
    queue< int > Q;
    for(int i=1;i<=n;i++)
    {
        if(Left[i] == 0) {
            dist[i] = 0;
            Q.push(i);
        } else {
            dist[i] = INF;
        }
    }
    dist[0] = INF;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        if(u != 0) {
            int len = Graph[u].size();
            for(int i = 0; i<len; i++) {
                int v = Graph[u][i];
                if(dist[Right[v]] == INF) {
                    dist[Right[v]] = dist[u] + 1;
                    Q.push(Right[v]);
                }
            }
        }
    }
    return (dist[0] != INF);
}

bool DFS(int u) {
    if(u != 0) {
        int len = Graph[u].size();
        for(int i = 0; i<len; i++) {
            int v = Graph[u][i];
            if(dist[Right[v]] == dist[u]+1) {
                if(DFS(Right[v])) {
                    Right[v] = u;
                    Left[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}


int hopcroft_karp() {
    int matching = 0;
    for(int i=0;i<=n;i++)
    {
        Left[i]=Right[i]=0;
    }

//    reset(Left,0);
//    reset(Right,0);

    while(BFS()){
        for(int i=1;i<=n;i++)
        {
            if(Left[i] == 0 && DFS(i)){
                matching++;
            }
        }
    }
    return n-matching;
}

int ara1[2][500004];



int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    prime();

    int t,tcase=1,v;


    in(t);
    vector<int>kp;

    while(t--)
    {
        in(n);
        reset(mark,0);
        reset(ara1,0);
        kp.clear();

        int mx=0;
        for(int i=1;i<=n;i++)
        {
            in(v);
            mark[v]=i;
            kp.pb(v);
            mx=max(mx,v);
        }

        for(int i=0;i<=n;i++)
        {
            lst[i].clear();
            Graph[i].clear();
        }

        for(int i=0;i<sz(kp);i++)
        {
            int tmp=kp[i];
            int c=0;

            for(int j=0;j<sz(p) && p[j] * p[j] <=tmp ;j++ )
            {
                if(tmp%p[j]==0 )
                {
                    lst[i].pb(p[j] );

                    while(tmp>1 && tmp%p[j]==0)
                    {
                        tmp/=p[j];
                        c++;
                    }
                }
            }

            if(tmp>1)
            {
                lst[i].pb(tmp);
                c++;
            }

            ara1[c&1][kp[i] ] =i+1;

        }


        for(int i=0;i<n;i++)
        {
            if(ara1[0][kp[i] ] )
            {
                for(int j=0;j<sz(lst[i] )  ;j++ )
                {
                    if(ara1[1][kp[i]/lst[i][j] ]  )
                    {
                        Graph[i+1].pb(ara1[1][kp[i]/lst[i][j]] );
                    }
                }
            }
            else
            {
                for(int j=0;j<sz(lst[i] ) ;j++ )
                {
                    if(ara1[0][kp[i]/lst[i][j]]  )
                    {
                        Graph[ara1[0][kp[i]/lst[i][j]] ].pb(i+1);
                    }
                }
            }
        }

        pf("Case %d: %d\n",tcase++,hopcroft_karp() ) ;
    }


    return 0;
}




