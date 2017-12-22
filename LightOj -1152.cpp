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

#define MAX 450

vector<int>lst[MAX];
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
char s[25][25] ;
int x[25][25] ;
int c;
int n,m;

int bpm()
{
    int cnt=0;
    reset(rmatch,-1);
    reset(match,0);


    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
            if((i+j)%2 && x[i][j] )
            {
                reset(visit,false);
                if(dfs(x[i][j]))
                {
                    cnt++;
                }

            }

    }
//    for(int i=1;i<=c;i++)
//        pf("%d : %d\n",i,rmatch[i] );



    return c-cnt;
}




int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;

    in(t);

    while(t--)
    {
        in(n),in(m);

        reset(x,0);
        c=0;

        for(int i=0;i<=n*m;i++)
            lst[i].clear();

        for(int i=1;i<=n;i++)
        {
            scanf("%s",s[i] );
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='*'  )
                    x[i][j]=++c;

            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i+j)%2 && x[i][j] )
                {
                    if( j+1<m && x[i][j+1]  )
                        lst[x[i][j]].pb(x[i][j+1]);
                    if(i+1<=n && x[i+1][j]  )
                        lst[x[i][j]].pb(x[i+1][j]);

                    if( j-1>=0 && x[i][j-1]  )
                        lst[x[i][j]].pb(x[i][j-1]);
                    if(i-1>=1 && x[i-1][j]  )
                        lst[x[i][j]].pb(x[i-1][j]);
                }



            }
        }

        pf("Case %d: %d\n",tcase++,bpm() );
    }


    return 0;
}




