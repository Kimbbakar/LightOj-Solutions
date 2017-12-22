/*
 Problem name : 1222 - Gift Packing
 Algorithm : Min Cost-Max flow
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
 Last Update : 25-Mar-2015
*/

/*
"
    When I look into your eyes
    It's like watching the night sky
    Or a beautiful sunrise
    Well, there's so much they hold
    And just like them old stars
    I see that you've come so far
    To be right where you are
    How old is your soul?

    Well, I won't give up on us
    Even if the skies get rough
    I'm giving you all my love
    I'm still looking up

    And when you're needing your space
    To do some navigating
    I'll be here patiently waiting
    To see what you find

    'Cause even the stars they burn
    Some even fall to the earth
    We've got a lot to learn
    God knows we're worth it
    No, I won't give up

    I don't wanna be someone who walks away so easily
    I'm here to stay and make the difference that I can make
    Our differences they do a lot to teach us how to use
    The tools and gifts we got, yeah, we got a lot at stake
    And in the end, you're still my friend at least we did intend
    For us to work we didn't break, we didn't burn
    We had to learn how to bend without the world caving in
    I had to learn what I've got, and what I'm not, and who I am

    I won't give up on us
    Even if the skies get rough
    I'm giving you all my love
    I'm still looking up, I'm still looking up.

    Well, I won't give up on us (no I'm not giving up)
    God knows I'm tough enough (I am tough, I am loved)
    We've got a lot to learn (we're alive, we are loved)
    God knows we're worth it (and we're worth it)

    I won't give up on us
    Even if the skies get rough
    I'm giving you all my love
    I'm still looking up
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

int cost[105][105];
int mark[105],path[105];
int cap[105][105];
vector<int>aj_list[105];
int n;
int source,sink,v;

bool putki()
{
    reset(path,-1);
    for(int i=0;i<=2*n+5;i++)
        mark[i]=-inf;

    mark[source]=0;

    bool ok=true;
    for(int x=0;x<=2*n+2 && ok;x++)
    {
        ok=false;

        for(int i=0;i<=2*n+2;i++)
        {
            for(int j=0;j<sz(aj_list[i]);j++)
            {
                int k= aj_list[i][j] ;

                if(mark[k]<cost[i][k] + mark[i] && cap[i][k] )
                {//printf("%d -> %d\n",i,k);
                    mark[k]= cost[i][k] + mark[i];
                    ok=true;
                    path[k]=i;
                }
            }
        }

        if(!ok) break;
    }

    return (mark[sink]>(-inf) );
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;

    while(t--)
    {
        n=in<int>();

        fill(aj_list,aj_list+2*n+5,vector<int>());
        source=0;
        sink=n+1;

        for(int i=1;i<=n;i++)
        {
            aj_list[source].pb(i);
            aj_list[i].pb(source);

            cap[source][i]=1;
            cap[i][source]=0;

            aj_list[i+n+1].pb(sink);
            aj_list[sink].pb(i+n+1);

            cap[i+n+1][sink]=1;
            cap[sink][i+n+1]=0;

            cap[i][i]=0;
            cap[i+n+1][i+n+1]=0;

            cost[source][i]=cost[i][source]=cost[i+n+1][sink]=cost[sink][i+n+1]=0;

            for(int j=1;j<=n;j++)
            {
                v=in<int>();

                aj_list[i].pb(j+n+1);
                aj_list[j+n+1].pb(i);

                cap[i][j+n+1]=1;
                cap[j+n+1][i]=0;

                cost[i][j+n+1]=v;
                cost[j+n+1][i]=-v;
            }
        }

        int ans=0;

        while(putki() )
        {
            //what_is("Putki")
            int y=sink;

            while(path[y]!=-1){
                cap[path[y]][y]--;
                cap[y][path[y]]++;
                ans+=cost[path[y]][y];
                y=path[y];
            }
        }

        printf("Case %d: %d\n",tcase++,ans);

    }



    return 0;
}

