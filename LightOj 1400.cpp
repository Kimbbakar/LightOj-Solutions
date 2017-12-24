// Problem name : 1400 - Employment
// Algorithm : Stable Marrige
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself, people also start to believe in you
// Date : 24-Oct-14

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

int oder[105][105]; // Company preferance
vector<int>aj_list[105]; //
int sol[105];

int n,num;

inline void input_1()
{
    for(int i=0;i<=n;i++)
        aj_list[i].clear();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&num);
            aj_list[i].pb(num);
        }
    }
}

inline void input_2()
{

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&num);
            oder[i][num]=j;
        }
    }
}

inline void stable_marrige()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
        q.push(i);
    while(!q.empty())
    {
        int i=q.front();
        for(int j=0;j<n;j++)
        {//printf("%d %d %d %d\n",aj_list[i][j],sol[aj_list[i][j]-n],oder[aj_list[i][j]-n][i],oder[aj_list[i][j]-n][sol[aj_list[i][j]-n]]);
            if(sol[aj_list[i][j]-n]==0)
            {
                sol[aj_list[i][j]-n]=i;
                q.pop();
                break;
            }
            else if(oder[aj_list[i][j]-n][i]< oder[aj_list[i][j]-n][sol[aj_list[i][j]-n]])
            {
                q.push(sol[aj_list[i][j]-n]);
                sol[aj_list[i][j]-n]=i;
                q.pop();
                break;
            }

        }
//        for(int j=1;j<=n;j++)
//            printf("%d) %d ",j+n, sol[j]);
//        printf("\n");
    }
}


int main()
{
    int t,tcase=1;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        memset(oder,0,sizeof(oder));
        memset(sol,0,sizeof(sol));

        input_1();
        input_2();
        stable_marrige();

        printf("Case %d: ",tcase++);

        for(int i=1;i<=n;i++)
        {
            printf("(%d %d)",sol[i],i+n);

            if(i<n)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
