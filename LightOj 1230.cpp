/*
 Problem name : 1230 - Placing Lampposts
 Algorithm : Minimum vertex cover
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 06-Nov-14
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
#define lcm(x,y) (x/gcd(x,y))*y
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

class nod
{
public:
    int value,d;

    nod()
    {
        value=d=0;
    }
};

nod dp[1006][3];
int par[1006];
int mark[1006];
vector<int>aj_list[1006];
int n,m;
nod ans,smpl;


inline void input()
{
    int x,y;

    for(int i=0;i<=n+2;i++)
        aj_list[i].clear();


    for(int i=0;i<m;i++)
    {
        x=in<int>();
        y=in<int>();

        aj_list[x+1].pb(y+1);
        aj_list[y+1].pb(x+1);
    }
}



nod re(int pos,int take)
{
    nod &r=dp[pos][take];

    if(r.value!=-1) return r;

    r.value=r.d=0;
    nod r1,r2;
    int sm;

    for(int i=0;i<sz(aj_list[pos]);i++)
    {
        sm=aj_list[pos][i];
        mark[sm]=1;
        if(sm!=par[pos])
        {
            if(take)
            {
                par[sm]=pos;
                r1=re(sm,1);
                r1.value+=1;
                if(pos!=0)
                    r1.d+=1;
                r2=re(sm,0);
//                printf("* %d %d\n",pos,take);
//                printf("%d %d %d %d\n",r1.value,r1.d,r2.value,r2.d);
                if(r1.value<r2.value)
                {
                    r.value+=r1.value;
                    r.d+=r1.d;
                }
                else if(r1.value==r2.value && r1.d>r2.d)
                {
                    r.value+=r1.value;
                    r.d+=r1.d;

                }
                else
                {
                    r.value+=r2.value;
                    r.d+=r2.d;
                }
            }

            else
            {
//                printf("** %d %d\n",pos,take);
//                printf("%d %d \n",r1.value,r1.d);
                par[sm]=pos;
                r1=re(sm,1);
                r.value+=(r1.value+1);
                r.d+=r1.d;
            }
        }
    }

    return r;
}

int main()
{
    int t,tcase=1;

    t=in<int>();

    while(t--)
    {
        n=in<int>();
        m=in<int>();

        input();
        reset(mark,0);
        reset(dp,-1);
        ans.value=ans.d=0;

        for(int i=1;i<=n;i++)
        {
            if(mark[i]==0)
            {
                mark[i]=1;

                aj_list[0].clear();
                aj_list[0].pb(i);

                dp[0][1].value=dp[0][1].d=dp[0][0].value=dp[0][0].d=-1;

                smpl=re(0,1);
                ans.d+=smpl.d;
                ans.value+=smpl.value;

            }
        }

        printf("Case %d: %d %d %d\n",tcase++,ans.value,ans.d,m-ans.d);
    }

    return 0;
}

