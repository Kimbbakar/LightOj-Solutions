 /*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
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
#define sf              scanf
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

    while(b) b ^= a ^= b ^= a %= b;
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


template<class T>
inline int in(register T& num)
{
    register char c=0;
    num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    num=n?-num:num;
    return 1;
}

/******* ! Code start from here ! *******/

#define MAX 40005

int nod(int x)
{
    if(x<0)
    {
        return abs(x)+20000;
    }
    return x;
}

vector<int>lst[MAX];
vector<int>lst1[MAX];
int n,m;
int u,v;

int visit[MAX];
int mark[MAX];
int col[MAX];
int taken[MAX];
stack<int>st;
int id,cl;
bool ok;

int scc(int p)
{
    visit[p]=1;
    mark[p]=id;
    int mn=id++;
    st.push(p);

    for(int j=0;j<sz(lst[p] );j++)
    {
        int i=lst[p][j];
        if(visit[i]==0)
        {
            mn=min(mn,scc(i) );
        }
        else if(visit[i]==1)
        {
            mn=min(mn,mark[i] );
        }
    }

    visit[p]=2;

    if(mn==mark[p])
    {
        while(st.top()!=p)
        {
            col[st.top()]=cl;
            lst1[cl].pb(st.top());
            st.pop();
        }
        lst1[cl].pb(st.top());
        col[st.top()]=cl;
        st.pop();

        cl++;

    }

    return mark[p]=mn;
}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
       // freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;

    in(t);

    while(t--)
    {
        in(n),in(m);

        for(int i=0;i<MAX;i++)
        {
            lst[i].clear();
            lst1[i].clear();
            mark[i]=0;
            visit[i]=0;
            col[i]=0;
            taken[i]=0;
        }
        id=1;
        cl=1;
        ok=false;


        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&u,&v);

            lst[nod(-u) ].pb(nod(v) );
            lst[nod(-v) ].pb(nod(u) );

        }

        for(int i=1;i<=m;i++)
            if(visit[i]==0)
            {
                scc(i);
            }

        int cnt=0;

        printf("Case %d: ",tcase++);

        vector<int>res;


        for(int i=1;i<=m && !ok;i++)
        {
            if(col[i]==col[nod(-i) ] )

            {
                ok=true;
            }
        }


        for(int i=1;i<cl && !ok;i++)
        {
            for(int j=0;j<sz(lst1[i] );j++)
            {
                int k=lst1[i][j];

                if(taken[k]) continue;

                if(k<20000 )
                {
                    taken[k]=1;
                    taken[k+20000]=1;
                    res.pb(k);
                    cnt++;
                }
                else
                {
                    taken[k]=1;
                    taken[k-20000]=1;
                }
            }
        }



        if(ok)
            pf("No\n");
        else
        {
            pf("Yes\n");


            pf("%d",cnt);
            sort(all(res) );

            for(int i=0;i<sz(res);i++)
                    pf(" %d",res[i] );
            pf("\n");
        }
    }



    return 0;
}





