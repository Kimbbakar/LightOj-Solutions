/*
 Problem name : 1128 - Greatest Parent
 Algorithm : RMQ
 Contest/Practice : Off Line Practice
 Source : Lilght Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 11-Mar-15
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

int val[100008] ;
int table[100005][17];
int n,q,k,v,p,s,lim,res;

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;

    while(t--)
    {
        n=in<int>();
        q=in<int>();

        reset(table,-1);

        table[0][0]=-1;
        val[0] =1;

        for(int i=1;i<=n-1;i++)
        {
            p=in<int>();
            s=in<int>();

            table[i][0]=p;
            val[i]=s;
        }


        lim=log2(n);

        for(int j=1;j<=lim;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(table[i][j-1]!=-1 )
                {
                    table[i][j]=table[table[i][j-1] ] [j-1];
                }

            }
        }



        res=-1;

        printf("Case %d:\n",tcase++);
 
        for(int l=1;l<=q;l++)
        {
            k=in<int>();
            v=in<int>();
            s=k;

            for(int j=lim;j>=0;j--)
            {
                if(table[k][j]!=-1 && val[table [k][j] ]>=v)
                { //what_is(k) what_is(j) what_is(table[k][j]) what_is(val[table [k][j] ])
                    k=table[k][j];
                }

            }


            printf("%d\n",k);

        }

    }

    return 0;
}

