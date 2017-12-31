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
#define mod             99999997
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

    bool operator < (const nod& a) const
    {
        return (F==a.F)?(S<a.S):(F<a.F);
    }
};

int state[20][50005];
int suffix_array[50005];
int mark[50004];
int lcp[500005];
string s;
nod taple[50005];
int n;
#define B 29

void build_suffix_array()
{
    for(int i=0;i<n;i++)
    {
        state[0][i]=s[i]-'a';
    }

    for(int p=1,i=1;p<n;p*=2,i++)
    {
        for(int j=0;j<n;j++)
        {
            taple[j].P=j;
            taple[j].F=state[i-1][j];
            taple[j].S=(j+p<n)?state[i-1][j+p]:-1  ;
        }

        sort(taple,taple+n);

        for(int j=0;j<n;j++)
        {
            state[i][taple[j].P]=(j>0 && taple[j].F==taple[j-1].F && taple[j].S==taple[j-1].S )?state[i][taple[j-1].P] : j;
            suffix_array[state[i][taple[j].P]]=taple[j].P;
        }
    }

    for(int i=0;i<n;i++)
    {
        mark[suffix_array[i] ]=i;
     //    cout<<suffix_array[i]<<" "<<s.substr(suffix_array[i],n)<<endl;
    }
}

void build_lcp()
{
    for(int i=0,k=0;i<n;i++ ,(k>0)?k--:k )
    {
        if(mark[i]==n-1)
        {
            lcp[i]=0;
            continue;
        }

        int j=suffix_array[mark[i]+1 ] ;

        while(j+k<n && i+k<n && s[i+k]==s[j+k]) k++;

        lcp[i]=k;
    }
}

int c[50004];

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;

    in(t);

    string g;
    int a;


    while(t--)
    {
        cin>>s;


        cin>>g;
        a=sz(g);
        n=sz(s);

        build_suffix_array();
        build_lcp();

        for(int i=0;i<n;i++)
            c[i]=1;

        ll h1=0,h2=0;

        ll p=1;

        for(int i=0;i<sz(g);i++)
        {
            h2=mod_v(mod_v(h2*B)+g[i]-'a'+1);
        }

        for(int i=0;i<sz(g)-1 && i<sz(s);i++ )
        {
            h1=mod_v(mod_v(h1*B)+s[i]-'a'+1);

            p=mod_v(p*B);
        }

        for(int i=sz(g)-1;i<sz(s);i++)
        {
            h1=mod_v(   mod_v(h1*B) +s[i]-'a'+1);

            if(h1==h2)
            {
                c[i-sz(g)+1]=0;
               // what_is(i)
            }

            h1=mod_v(h1-mod_v( (s[i-sz(g)+1]-'a'+1) *p) );

        }

        int res=0;
            int cnt=0;

            for(int i=sz(s)-1;i>=0;i--)
            {
                if(c[i])
                {
                    cnt++;
                    c[i]=cnt;
                }
                else
                {
                    c[i]=a-1;
                    cnt=a-1;
                }
              //  what_is(c[i])

            }

//            for(int i=sz(s)-1;i>=0;i--)
//            {
//                if(c[i])
//                {
//                    c[i]=cnt;
//                }
//                else
//                {
//                    c[i]=i;
//                    cnt=i;
//                }
//              //  what_is(c[i])
//
//            }

            for(int i=0;i<n;i++)
            {
                res+=max(0,min(n-suffix_array[i],c[suffix_array[i]] )-lcp[suffix_array[i] ] );
//                res+=max(0, min(n,c[suffix_array[i]]+a-1 )-suffix_array[i]-lcp[suffix_array[i] ]  );

//                what_is(lcp[suffix_array[i] ])
//                what_is(c[suffix_array[i]])
//                what_is(res)

            }

        pf("Case %d: %d\n",tcase++,res);


    }


    return 0;
}



