/*
 Problem name : 1093 - Ghajini
 Algorithm : Segment Tree
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 31-Oct-14
*/

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
#define check(x,w) (x&(1<<w))
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
#  define print(x) 0;
#endif

//.......Code start from here ! ......
#define MAX 100000

class node
{
public:
    int mn,mx;
};

node tree[3*MAX];
int kp[MAX+5];
int n,d;

node build(int nod,int l,int r)
{
    if(l==r)
    {
        tree[nod].mn=kp[l];
        tree[nod].mx=kp[l];
        return tree[nod];
    }

    int left=2*nod;
    int right=left+1;

    int mid=(l+r)>>1;

    node r1=build(left,l,mid);
    node r2=build(right,mid+1,r);

    tree[nod].mn=min(r1.mn,r2.mn);
    tree[nod].mx=max(r1.mx,r2.mx);

    return tree[nod];
}

int get_max(int nod,int i,int j,int l,int r)
{
    if(r<i || j<l)
        return -inf;
    if(i<=l && j>=r)
        return tree[nod].mx;

    int left=2*nod;
    int right=left+1;

    int mid=(l+r)>>1;

    int r1=get_max(left,i,j,l,mid);
    int r2=get_max(right,i,j,mid+1,r);

    return max(r1,r2);
}


int get_min(int nod,int i,int j,int l,int r)
{
    if(r<i || j<l)
        return inf;
    if(i<=l && j>=r)
        return tree[nod].mn;

    int left=2*nod;
    int right=left+1;

    int mid=(l+r)>>1;

    int r1=get_min(left,i,j,l,mid);
    int r2=get_min(right,i,j,mid+1,r);

    return min(r1,r2);
}

int main()
{
    int t,tcase=1;

    t=in<int>();

    while(t--)
    {
        n=in<int>();
        d=in<int>();

        for(int i=0;i<n;i++)
            kp[i]=in<int>();

        build(1,0,n-1);
        int ans=0;

        for(int i=0;i<n;i++)
        {
            ans=max(ans, abs(get_max(1,i,min(i+d-1,n-1),0,n-1)-get_min(1,i,min(i+d-1,n-1),0,n-1) ) );
        }

        printf("Case %d: %d\n",tcase++,ans);
    }

    return 0;
}


