/*
 Problem name : 1132 - Summing up Powers
 Algorithm : Matrix Expo
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 27-Feb-15
 Last Update : 27-Jan-2015
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
    return num;
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


int k;
ll n;

unsigned int nCr[55][55];


class matrix
{
public:
    unsigned int m[55][55];

    matrix()
    {
        reset(m,0);
    }

    void re_set()
    {
        m[0][0]=1;
        for(int i=1;i<=k+1;i++)
        {
            for(int j=i;j<=k+1;j++)
                m[i][j]=nCr[k-i+1][j-i];
        }
        for(int i=1;i<=k+1;i++)
            m[0][i]=nCr[k][i-1];
    }


    matrix mul(matrix x)
    {
        matrix res;
        for(int i=0;i<=k+1;i++)
        {
            for(int j=0;j<=k+1;j++)
            {
                res.m[i][j]=0;
                for(int l=0;l<=k+1;l++)
                {
                    res.m[i][j]+=(m[i][l]*x.m[l][j] );
                }
            }
        }

        return res;
    }

};

matrix expo(matrix x,ll p)
{
    if(p==1) return x;
    if(p&1)
    {
        return x.mul(expo(x,p-1) );
    }
    else
    {
        matrix g=expo(x,p/2);

        return g.mul(g);
    }
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif


    nCr[0][0]=1;

    for(int i=1;i<=50;i++)
    {
        nCr[i][0]=1;
        for(int j=1;j<=i;j++)
            nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
    }

    int t=in<int>(),tcase=1;
    matrix res;
    unsigned int ans;


    while(t--)
    {
        n=in<ll>();

        k=in<int>();

        printf("Case %d: ",tcase++);

        if(n==1)
            printf("%lu\n",fast_pow(1,k));

        else
        {
            res.re_set();


            matrix x=expo(res,n-1);
 
            ans=0;

            for(int i=0;i<=k+1;i++)
            {
                ans+=(x.m[0][i]);
               // p*=(unsigned ) k;
            }

            printf("%lu\n",ans);
        }
    }

    return 0;
}


