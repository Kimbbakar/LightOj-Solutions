/*
 Problem name : 1048 - Conquering Keokradong
 Algorithm : Binary Search
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 28-Oct-14
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

int camp[1001];

int k,n;
int l,r,mid,dis,night;

bool ok(int value)
{
    night=0;
    dis=0;
    for(int i=0;i<=n;i++)
    {
        if((k-night)==(n-i+1) && dis+camp[i]<=value)
        {
            night++;
            dis=0;
        }
        else if(dis+camp[i]<=value)
        {
            dis+=camp[i];
        }
        else if(dis+camp[i]>value)
        {
            dis=0;
            i--;
            night++;
        }
        if(night>k)
            break;
    }
    if(dis!=0)
        night++;

    return (night<=k);
}

int bi_search()
{
    while(l<r)
    {
        mid=(l+r)>>1;

        if(ok(mid))
            r=mid;
        else
            l=mid+1;
    }

    return r;
}

int main()
{
    int t,tcase=1,ans;

    t=in<int>();

    while(t--)
    {
        n=in<int>();
        k=in<int>();

        k++;
        l=r=0;

        for(int i=0;i<=n;i++)
        {
            camp[i]=in<int>();
            r+=camp[i];
        }

        ans=bi_search();

        printf("Case %d: %d\n",tcase++,ans);

        dis=0;
        night=0;
        for(int i=0;i<=n;i++)
        {
//            printf("%d %d\n",night,i);
            if((k-night)==(n-i+1) && dis+camp[i]<=ans)
            {
                printf("%d\n",dis+camp[i]);
                night++;
                dis=0;
            }
            else if(dis+camp[i]<=ans)
            {
                dis+=camp[i];
            }
            else if(dis+camp[i]>ans)
            {
                printf("%d\n",dis);
                dis=0;
                i--;
                night++;
            }
        }
        if(dis!=0)
            printf("%d\n",dis);
    }
    return 0;
}

