// Problem name : 1074 - Extended Traffic
// Algorithm : Bellman Ford
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself, people also start to believe in you
// Date : 16-Oct-14

#include<bits/stdc++.h>

#define pause system("pause");
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define mod 1000000007
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


template<class T>
inline T mod_v(T num)
{
    if(num>=0)
        return num%mod;
    else
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

class nod
{
public:
    int u,v,w;
    nod(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

int nd,edge,q,num,tcase;
int cost[205];
int neg[205];
vector<nod>path;
int busy[205];


inline void clr()
{
    for(int i=0;i<205;i++)
    {
        cost[i]=100000000;
        neg[i]=0;
    }
    path.clear();
}

inline void input()
{
    scanf("%d",&nd);

    for(int i=1;i<=nd;i++)
        scanf("%d",&busy[i]);

    scanf("%d",&edge);

    int u,v,w;

    for(int i=1;i<=edge;i++)
    {
        scanf("%d %d",&u,&v);

        w=pow(busy[v]-busy[u],3);

        path.pb(nod(u,v,w));

    }

}

inline void bellman()
{
    cost[1]=0;

    for(int i=1;i<nd;i++)
    {
        for(int j=0;j<sz(path);j++)
        {
            if(cost[path[j].u]+path[j].w <cost[path[j].v ] && cost[path[j].u]<100000000)
            {
                cost[path[j].v]=cost[path[j].u]+path[j].w;
            }
        }
    }
}

inline void check_neg_cycl()
{
    for(int i=1;i<nd;i++)
    {
        for(int j=0;j<sz(path);j++)
        {
            if(cost[path[j].u]+path[j].w <cost[path[j].v ] && cost[path[j].u]<100000000)
            {
                cost[path[j].v]=cost[path[j].u]+path[j].w;
                neg[path[j].v]=1;
            }
        }
    }
}

inline void queries()
{
    scanf("%d",&q);

    printf("Case %d:\n",tcase++);
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&num);

        if(neg[num]!=1 && cost[num]>=3 && cost[num]<100000000)
            printf("%d\n",cost[num]);
        else
            printf("?\n");
    }
}

int main()
{
    int t;
    tcase=1;
    scanf("%d",&t);
    while(t--)
    {
        clr();
        input();
        bellman();
        check_neg_cycl();
        queries();
    }
    return 0;
}


