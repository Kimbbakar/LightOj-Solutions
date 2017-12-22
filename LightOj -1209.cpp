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

#define MAX 1004

vector<int>lst[MAX];
vector<int>F[MAX];
vector<int>S[MAX];
int match[MAX],rmatch[MAX];
bool visit[MAX];


bool dfs (int v)
{
    for(int i=0;i<sz(lst[v]);i++)
    {
        int u=lst[v][i];

        if(!visit[u] )
        {
            visit[u]=true;



            if(rmatch[u]==-1 || dfs(rmatch[u] ) )
            {
                rmatch[u]=v;
                match[v]=u;
                return true;
            }
        }
    }

    return false;
}
int n;
int m,f;

int bpm()
{
    int cnt=0;
    reset(rmatch,-1);
    reset(match,0);


    for(int i=1;i<=2*n;i++)
    {
        if(!match[i]  )
        {
            reset(visit,false);
            if(dfs(i) )
            {
                cnt++;
            }

        }

    }


//    for(int i=1;i<=c;i++)
//        pf("%d : %d\n",i,rmatch[i] );



    return n-cnt;
}



int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
 //       freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;

    string u,v;

    in(t);

    while(t--)
    {
        in(m),in(f),in(n);

        for(int i=1;i<=2*n;i++)
        {
            lst[i].clear();
            F[i].clear();
            S[i].clear();
        }

        m=f=0;

        map<string ,int>x;

        int a,b;

        for(int i=1;i<=n;i++)
        {
            cin>>u>>v;

            if(x[u]==0)
                x[u]=++m;

            if(x[v]==0)
                x[v]=++m;

            a=x[u],b=x[v];

            for(int j=0;j<sz(S[a] );j++ )
            {

                if(u[0]=='M' )
                    lst[i].pb(S[a][j] );
                else
                lst[S[a][j] ].pb(i);
            }


            for(int j=0;j<sz(F[b] );j++ )
            {
                if(u[0]=='M' )
                    lst[i].pb(F[b][j] );
                else
                    lst[F[b][j]].pb(i);
            }

            F[a].pb(i);
            S[b].pb(i);

        }


        pf("Case %d: %d\n",tcase++,bpm() );
    }


    return 0;
}




