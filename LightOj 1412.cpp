/*
 Problem name : 1412 - Visiting Islands
 Algorithm : BFS
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 27-Apr-15
 Last Update : 25-Mar-2015
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

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}


//template<class T>
//inline T in()
//{
//    register char c=0;
//    register T num=0;
//    bool n=false;
//    while(c<33)c=getchar();
//    while(c>33){
//        if(c=='-')
//            n=true;
//        else num=num*10+c-'0';
//        c=getchar();
//    }
//    return n?-num:num;
//}

template<class T>
 inline int in() {
     T x;
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}

/******* ! Code start from here ! *******/

int visit1[100005]={0},visit2[100005]={0},cc=1;
vector<int>aj_list[100005];
int get,ct,st;

pair<int,int>kp[100005];
int c;

void dfs1(int n,int cost)
{
    if(visit1[n]==cc) return ;
        visit1[n]=cc;

    if(cost>ct)
    {
        ct=cost;
        st=n;
    }


    for(int i=0;i<sz(aj_list[n]);i++)
    {
        int k=aj_list[n][i];

        if(visit1[k]!=cc)
        {
            dfs1(k,cost+1);
        }
    }
}


void dfs2(int n,int cost)
{
    if(visit2[n]==cc) return ;
        visit2[n]=cc;

    if(cost>ct)
    {
        ct=cost;
        st=n;
    }


    for(int i=0;i<sz(aj_list[n]);i++)
    {
        int k=aj_list[n][i];

        if(visit2[k]!=cc)
        {
            dfs2(k,cost+1);
            get++;
        }
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
    int n,m,q;
    int u,v;

    while(t--)
    {
        n=in<int>();
        m=in<int>();

        fill(aj_list,aj_list+n+2,vector<int>());

        for(int i=1;i<=m;i++)
        {
            u=in<int>();
            v=in<int>();

            aj_list[u].pb(v);
            aj_list[v].pb(u);
        }

        c=0;
        int mx=-1;

        for(int i=1;i<=n;i++)
        {
            if(visit1[i]!=cc)
            {
                ct=-1,st=i;
                dfs1(i,0);

                get=1,ct=-1;
                dfs2(st,1);

                kp[c].F=get;
                kp[c].S=ct;

                mx=max(mx,ct);

                c++;
            }
        }

        q=in<int>();

        sort(kp,kp+c,greater<pair<int,int> >());

        printf("Case %d:\n",tcase++);

    //    printf("%d %d %d\n",c,kp[0].F,kp[0].S);

        while(q--)
        {
            u=in<int>();

            if(u<=mx)
                printf("%d\n",u-1);

            else if(kp[0].F<u)
                printf("impossible\n");
            else
            {
                int res=inf;
                for(int i=0;i<c && kp[i].F>=u ;i++)
                    res=min(res,(kp[i].S-1)+2*(u-kp[i].S) );

                printf("%d\n",res);
            }
        }

        cc++;
    }

    return 0;
}


