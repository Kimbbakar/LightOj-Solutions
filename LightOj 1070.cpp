/*
 Problem name : 1070 - Algebraic Problem
 Algorithm : Matrix Exponential
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 24-Nov-14
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
#define gcd(x,y)         __gcd(x,y)
#define lcm(x,y)        (x/gcd(x,y))*y
#define on(x,w)         x=x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||

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

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define p(x) 0;
#endif

/*...... ! Code start from here ! ......*/


llu p,q;
int n;


class matrix
{
public:
    llu mat[2][2];

    matrix()
    {
        mat[0][0]=1,mat[0][1]=1;
        mat[1][0]=1,mat[1][1]=0;
    }

    inline matrix mul(matrix a)
    {
        matrix res;

        reset(res.mat,0);

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    res.mat[i][j]+=(mat[i][k]*a.mat[k][j]);
                }
            }
        }

        return res;
    }

};


matrix expo(matrix x,int n)
{
    if(n==1) return x;

    if(n%2)
    {
        return x.mul(expo(x,n-1));
    }
    else
    {
        matrix sm=expo(x,n/2);

        return sm.mul(sm);
    }
}



int main()
{
    int t,tcase=1;

    t=in<int>();

    while(t--)
    {
       p=in<llu>();
       q=in<llu>();

       n=in<int>();

       matrix sol;

       sol.mat[0][0]=p;
       sol.mat[0][1]=-q;

        printf("Case %d: ",tcase++);

        if(n==0)
            printf("2\n");
        else if(n==1)
            printf("%llu\n",p);

        else
        {
           sol=expo(sol,n-1);

           printf("%llu\n", sol.mat[0][0]*p+sol.mat[0][1]*2 );
        }


    }

    return 0;
}

