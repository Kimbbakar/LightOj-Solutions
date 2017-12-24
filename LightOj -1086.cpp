 /*
 Problem name : 1086 - Jogging Trails
 Algorithm : Off Line Practice
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 13-Oct-15
 Last Update : 25-Mar-2015
*/

/*
	Hey, once upon a younger year
	When all our shadows disappeared
	The animals inside came out to play
	Hey, went face to face with all our fears
	Learned our lessons through the tears
	Made memories we knew would never fade

	One day my father—he told me,
	"Son, don't let it slip away."
	He took me in his arms, I heard him say,

	"When you get older
	Your wild heart will live for younger days
	Think of me if ever you're afraid."

	He said, "One day you'll leave this world behind
	So live a life you will remember."
	My father told me when I was just a child
	These are the nights that never die
	My father told me

	When thunder clouds start pouring down
	Light a fire they can't put out
	Carve your name into those shining stars
	He said, "Go venture far beyond these shores.
	Don't forsake this life of yours.
	I'll guide you home no matter where you are."

	One day my father—he told me,
	"Son, don't let it slip away."
	When I was just a kid I heard him say,

	"When you get older
	Your wild heart will live for younger days
	Think of me if ever you're afraid."

	He said, "One day you'll leave this world behind
	So live a life you will remember."
	My father told me when I was just a child
	These are the nights that never die
	My father told me

	These are the nights that never die
	My father told me
	Hey, hey

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

int floy_war[20][20];
int dp[1<<20];
int done[1<<20]={0},cc=1;
int cnt[20];
vector<int>nd;


int re(int mask)
{
    if(mask==(1<<sz(nd))-1) return 0;

    if(done[mask]==cc) return dp[mask];

    done[mask]=cc;

    int &r=dp[mask];
    r=inf;

    for(int i=0;i<sz(nd);i++)
    {
        for(int j=i+1;j<sz(nd);j++)
        {
            if( ( (mask&(1<<j) ) ==0 &&  (mask&(1<<i) )==0) )
            {
                r=min(r,floy_war[nd[i]][nd[j]]+re( mask|((1<<j)|(1<<i) ) ) );
            }
        }
    }

    return r;

}



int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int n,m,t,tcase=1;
    int u,v,val;

    in(t);

    while(t--)
    {
        in(n),in(m);

        int res=0;

        reset(cnt,0);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) floy_war[i][j]=0;
                else
                    floy_war[i][j]=123456711;
            }
        }


        for(int i=1;i<=m;i++)
        {
            in(u),in(v),in(val);
            res+=val;

            floy_war[u][v]=min(floy_war[u][v],val);

            floy_war[v][u]=floy_war[u][v];

            cnt[u]++,cnt[v]++;
        }


        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    floy_war[i][j]=min(floy_war[i][j],floy_war[i][k]+floy_war[k][j] );
                }
            }
        }



        nd.clear();

        for(int i=1;i<=n;i++)
        {
            if(cnt[i]&1)
            {
                nd.pb(i);
            }
        }




        pf("Case %d: %d\n",tcase++,res+re(0) );

        cc++;

    }

    return 0;
}


