/*
 Problem name : 1235 - Coin Change (IV)
 Algorithm : Binary Search (Meet In The middle)
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 27-Nov-14
*/

#include<bits/stdc++.h>

#define pause           system("pause");
#define                 rep(i,n) for(int i=0; i<(int)n; i++)
#define                 repv(i,n) for(int i=n-1; i>=0; i--)
#define                 repl(i,n) for(int i=1; i<=(int)n; i++)
#define                 replv(i,n) for(int i=n; i>=1; i--)
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

int coin[40];
int take[1<<18];

vector<int>res1;
vector<int>res2;

int n,k;

void re1(int l,int r,int sum)
{//printf("%d %d\n",l,r);pause
    if(l==r)
    {
        res1.pb(sum);
        return;
    }

    for(int i=0;i<3;i++)
    {
        re1(l+1,r,sum+coin[l]*i );
    }

    return;
}

void re2(int l,int r,int sum)
{
    if(l==r)
    {
        res2.pb(sum);
        return;
    }

    for(int i=0;i<3;i++)
    {
        re2(l+1,r,sum+coin[l]*i );
    }

    return;
}

int main()
{
    int t,tcase=1,c;

    t=in<int>();

    while(t--)
    {
        n=in<int>();
        k=in<int>();

        for(int i=0;i<n;i++)
        {
            coin[i]=in<int>();
        }


        res1.clear();

        res2.clear();

        re1(0,n/2,0);
        re2(n/2,n,0);


        sort(all(res2));

        bool ans=false;

        for(int i=0;i<sz(res1);i++)
        {
            int l=0,r=sz(res2)-1;


            while(l<=r)
            {
                int mid=(l+r)>>1;


                if(res1[i]+res2[mid]==k)
                {
                    ans=true;
                    break;
                }

                else if(res1[i]+res2[mid]>k)
                    r=mid-1;
                else
                    l=mid+1;
            }

            if(ans)
                break;
        }

        if(ans)
            printf("Case %d: Yes\n",tcase++);
        else
            printf("Case %d: No\n",tcase++);

    }
    return 0;
}


