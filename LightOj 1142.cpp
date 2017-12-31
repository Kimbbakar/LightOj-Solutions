/*
 Problem name : 1142 - Summing up Powers (II)
 Algorithm : Matrix Expo
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 04-Mar-15
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


int n,k;

class matrix
{
public:
    int M[35][35];


    void inp()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                M[i][j]=in<int>();
        }
    }

    matrix mul(matrix X)
    {
        matrix res;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                res.M[i][j]=0;
                for(int k=0;k<n;k++)
                {
                    res.M[i][j]=(res.M[i][j]+(M[i][k]*X.M[k][j]) )%10;
                }
            }
        }

        return res;
    }

    void print()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%d ",M[i][j]);
            printf("\n");
        }
    }

    matrix add()
    {
        matrix res;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                res.M[i][j]=( (i==j) +M[i][j])%10;
            }

        }

//        printf("---- > 1\n");
//
//        res.print();

        return res;
    }

    matrix add(matrix x)
    {
        matrix res;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                res.M[i][j]=(x.M[i][j]+M[i][j])%10;
        }
//printf("---- > 2\n");
//        res.print();

        return res;
    }

};

matrix fast_pow(matrix n , int p)
{
    if(p==1) return n;
    if(p&1)
    {
        return  n.mul(fast_pow(n,p-1) );
    }
    else
    {
        matrix g=fast_pow(n,p/2);
        g=g.mul(g) ;
        return g;
    }
}

matrix expo(matrix n,int p)
{
    if(p==1) return n;

    if(p&1)
    {
        return (expo(n,p/2).mul(fast_pow(n,p/2).add() ) ).add(fast_pow(n,p))  ;
//        return (expo(n,p/2).mul(fast_pow(n,p/2).add() ) )  ;
    }

    else
    {//printf("Hi..\n");
        return (expo(n,p/2).mul(fast_pow(n,p/2).add() ) ) ;
    }
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;

    matrix nw,res;

    while(t--)
    {
        n=in<int>();
        k=in<int>();

        nw.inp();

        res=expo(nw,k);

        printf("Case %d:\n",tcase++);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%d",res.M[i][j]);
            printf("\n");
        }
    }

    return 0;
}

