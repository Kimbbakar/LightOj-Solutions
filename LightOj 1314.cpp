 /*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
 Last Update : 25-Mar-2015
*/

/*
    SO STEP INSIDE/ SEE THE DEVIL IN I
    Too many times, we’ve let it come to this
    STEP INSIDE/ SEE THE DEVIL IN I
    Oh, when all that’s left does not make sense
    STEP INSIDE/ SEE THE DEVIL IN I
    I know you’ll find your answers in the end
    STEP INSIDE/ SEE THE DEVIL IN I
    You’ll realize I’m not your Devil… anymore

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

class nod
{
public:
    int F,S,P;

    bool operator <(const nod& a ) const
    {
        return (F==a.F)?(S<a.S ):(F<a.F);
    }
};

int pos[20][10004] ; // after every sort state of suffix
int sf_rank[10004]; // rank of i'th suffix
int mark[10004]; // suffix position for i'th rank
int lcp[10004]; // lcp[i] = lcp(i,i+1)
nod taple[10004];
string s;
int n;

void build_suffix_array()
{
    for(int i=0;i<n;i++)
    {
        pos[0][i] =s[i]-'a';
    }

    for(int p=1,i=1;p<n;p*=2,i++)
    {
        for(int j=0;j<n;j++)
        {
            taple[j].F=pos[i-1][j];
            taple[j].S=(j+p<n?pos[i-1][j+p]:-1 );
            taple[j].P=j;
        }

        sort(taple,taple+n);

        for(int j=0;j<n;j++)
        {
            pos[i][ taple[j].P ]=(j>0 && taple[j].F==taple[j-1].F && taple[j].S==taple[j-1].S ) ?pos[i][taple[j-1].P] :j;

            mark[pos[i][ taple[j].P ]]=taple[j].P;
        }

    }

    for(int i=0;i<n;i++)
        sf_rank[mark[i] ]=i ;

}

void build_lcp()
{
    for(int i=0,k=0;i<n;i++,(k>0)?k--:k )
    {
        if(sf_rank[i]==n-1 )
        {
            lcp[i] =0;
            continue;
        }

        int j=mark[sf_rank[i]+1 ];

        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;

        lcp[i]=k;
    }
}



int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;
    int p,q;

    in(t);

    while(t--)
    {
        cin>>s;
        in(p),in(q);

        n=sz(s);

        build_suffix_array();
        build_lcp();


        int res=max(0,min(q,n-mark[0] ) -p+1 );


        for(int i=1;i<n;i++)
        {
            res+=max(0,min(q,n-mark[i] ) -max(lcp[mark[i-1]],p-1) );
        }


        pf("Case %d: %d\n",tcase++,res);

    }


    return 0;
}



