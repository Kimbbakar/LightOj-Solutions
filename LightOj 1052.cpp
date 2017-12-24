/*
 Problem name : 1052 - String Growth
 Algorithm : Matrix Expo
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 16-Apr-15
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
   // if(num>=0)
        return num%mod;
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
    return fast_pow(n,mod-(ll) 2 );
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

class matrix
{
    public:
    ll ar[2][2];

    void rst()
    {
        ar[0][0]=ar[0][1]=ar[1][0] =1;
        ar[1][1]=0;
    }

    matrix expo(ll p)
    {
        if(p==1)
        {
            matrix r;
            r.rst();
            return r;
        }
        if(p&1)
        {
            return mul(expo(p-1LL) );
        }
        else
        {
            matrix g=expo(p/2LL);
            return g.mul(g);
        }
    }

    void prtn()
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
                printf("%d ",ar[i][j]);
            printf("\n");
        }
        pause;
    }


    matrix mul(matrix z)
    {
        matrix res;

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                res.ar[i][j]=0;
                for(int k=0;k<2;k++)
                    res.ar[i][j]=mod_v(mod_v(res.ar[i][j]+mod_v(ar[i][k]* z.ar[k][j ]) ) );
            }
        }
       // res.prtn();
        return res;
    }


};


ll m,n,k;
ll x,y;
matrix a,b,c;

bool ok(ll F,ll S,ll A1,ll B1,ll A2,ll B2)
{
    if(F<0 || S<0) return 0;
    if(x>y ) return 0;

    if( mod_v( mod_v(B1*F) + mod_v(A1*S) )  != mod_v(x) ) return 0;
    if( mod_v( mod_v(B2*F) + mod_v(A2*S) )  != mod_v(y) ) return 0;

    return 1;
}



int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;



    while(t--)
    {
        n=in<ll>();
        x=in<ll>();
        m=in<ll>();
        y=in<ll>();
        k=in<ll>();

        if(n>m)
        {
            swap(x,y);
            swap(n,m);
        }

        a.rst();
        b.rst();
        c.rst();

        a=a.expo(n);
      //  a.prtn();
      //  printf("\n------------------\n");
        b=b.expo(m);


      //  b.prtn();


        ll B1 = a.ar[0][0];
        ll B2 = b.ar[0][0];

        ll A1 = a.ar[0][1];
        ll A2 = b.ar[0][1];

//        what_is(A1) what_is(B1)
//        what_is(A2) what_is(B2)

//        ll S=mod_v( mod_v( mod_v( (ll) y*B1)-mod_v((ll)x*B2)) * modInverse( mod_v( mod_v(B1*A2)- mod_v(A1*B2)) ) );
//        ll F=mod_v( mod_v(x-mod_v(S*A1) ) * modInverse(B1) ) ;

        ll F=mod_v( ( y*A1-x*A2) * modInverse( mod_v( B2*A1- A2*B1) ) );
        ll S=mod_v( (y-F*B2 ) * modInverse(A2) ) ;


//        what_is(F)
//        what_is(S)

        printf("Case %d: ",tcase++);


        if( ok(F,S,A1,B1,A2,B2))
        {
            c=c.expo(k);
            printf("%lld\n",mod_v(mod_v((ll) c.ar[0][0]*F) + mod_v((ll)c.ar[0][1]*S ) ) );
        }
        else
            printf("Impossible\n");
    }

    return 0;
}


