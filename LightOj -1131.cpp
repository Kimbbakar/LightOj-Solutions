// Problem name : 1131 - Just Two Functions
// Algorithm : Matirx Expo
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself, people also start to believe in you
// Date : 10-Oct-14

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cstring>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>
#include<assert.h>


#define pause system("pause");
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
//#define mod 1000000007
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define sqr(x) ( (x)* (x) )
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define pf printf
#define reset(x,v) memset(x,v,sizeof(x));
#define AND &&
#define OR ||

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int mod;
template<class T>
inline T mod_v(T num)
{
    return (num%mod+mod)%mod;
}

template<class T>
inline void memset1(vector<T>&v,T value)
{
    for(int i=0;i<sz(v);i++)
        v[i]=value;
}

template<class T>
inline void memset2(vector<vector<T> >&v,T value)
{
    for(int i=0;i<sz(v) ;i++)
        for(int j=0;j<sz(v[i]);j++)
            v[i][j]=value;
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

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! ......


class matrix
{
    public:
        int v[6][6];
        matrix()
        {
            for(int i=0;i<6;i++)
                for(int j=0;j<6;j++)
                    this->v[i][j]=0;
        }
};


matrix mul(matrix A,matrix B)
{

    matrix Z;

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            int sum=0;
            for(int k=0;k<6;k++)
                sum=mod_v(sum + mod_v(A.v[i][k]*B.v[k][j]));
            Z.v[i][j]=sum;
        }
    }

    return Z;
}

matrix expo(matrix X,ll p)
{
    if(p==1) return X;

    if(p%2)
    {
        return mul(X,expo(X,p-1));
    }
    else
    {
        matrix X2=expo(X,p/2);
        return mul(X2,X2);
    }
}


int main()
{
    int t,q,a1,b1,c1,a2,b2,c2,fog[6],tcase=1,sum;
    ll num;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d",&a1,&b1,&c1);
        scanf("%d %d %d",&a2,&b2,&c2);

        scanf("%d %d %d",&fog[0],&fog[1],&fog[2]);
        scanf("%d %d %d",&fog[3],&fog[4],&fog[5]);

        scanf("%d",&mod);
        scanf("%d",&q);

        printf("Case %d:\n",tcase++);

/*
a1, b1, 0, 0, 0, c1,
1, 0, 0, 0, 0, 0,
0, 1, 0, 0, 0, 0,
0, 0, c2, a2, b2, 0,
0, 0, 0, 1, 0, 0,
0, 0, 0, 0, 1, 0} ;
*/
        matrix f_g;

            f_g.v[0][0]=a1%mod;
            f_g.v[0][1]=b1%mod;
            f_g.v[0][5]=c1%mod;

            f_g.v[1][0]=1;
            f_g.v[2][1]=1;

            f_g.v[3][2]=c2%mod;
            f_g.v[3][3]=a2%mod;
            f_g.v[3][4]=b2%mod;

            f_g.v[4][3]=1;
            f_g.v[5][4]=1;
        swap(fog[0],fog[2]);
        swap(fog[3],fog[5]);

        matrix smpl;

        while(q--)
        {
            scanf("%lld",&num);

            if(num<3)
            {
                if(num==0)
                    printf("%d %d\n",fog[2]%mod,fog[5]%mod);
                else if(num==1)
                    printf("%d %d\n",fog[1]%mod,fog[4]%mod);
                else if(num==2)
                    printf("%d %d\n",fog[0]%mod,fog[3]%mod);
            }
            else
            {
                smpl=expo(f_g,num-2);

                sum=0;
                for(int i=0;i<6;i++)
                {
                    sum=mod_v(sum+mod_v(smpl.v[0][i]*fog[i]) );
                }
                printf("%d ",sum);

                sum=0;
                for(int i=0;i<6;i++)
                {
                    sum=mod_v(sum+mod_v(smpl.v[3][i]*fog[i]) );
                }

                printf("%d\n",sum);
            }
        }
    }


    return 0;
}

