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

#define MAX 2005

int nod(int x)
{
    if(x<0)
    {
        return abs(x)+1000;
    }
    return x;
}

vector<int>lst[MAX];
vector<int>lst1[MAX];
vector<int>lst2[MAX];
int n,m,k;
int u,v;

int coun[6][4];
int visit[MAX];
int mark[MAX];
int col[MAX];
int taken[MAX];
stack<int>st;
int id,cl;

int scc(int p)
{
    visit[p]=1;
    mark[p]=id;
    int mn=id++;
    st.push(p);

    for(int j=0;j<sz(lst2[p] );j++)
    {
        int i=lst2[p][j];
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

bool found;
vector<int>res;
int cnt;

bool solve(int x)
{
    id=1;
    cl=1;

    for(int i=0;i<MAX;i++)
    {
        lst1[i].clear();
        lst2[i]=lst[i] ;
        mark[i]=0;
        visit[i]=0;
        col[i]=0;
    }

    for(int i=0;i<k;i++)
    {
        int q=x%3+1;

        if(coun[i][0]==1)
        {
            lst2[nod(-coun[i][q]) ].pb(coun[i][q]);
        }
        else
        {
            lst2[coun[i][q] ].pb(nod(-coun[i][q]));
        }

        x/=3;
    }

    bool ok=false;

    for(int i=1;i<=m;i++)
    {
        if(visit[i]==0)
            scc(i);
    }

    for(int i=1;i<=m && !ok;i++)
    {
        if(col[i]==col[nod(-i) ] )
        {
            ok=true;
        }
    }

    return !ok;
}

void print()
{
    for(int i=1;i<cl ;i++)
    {
        for(int j=0;j<sz(lst1[i] );j++)
        {
            int k=lst1[i][j];

            if(taken[k]) continue;

            if(k<=1000 )
            {
                taken[k]=1;
                taken[k+1000]=1;
                res.pb(k);
                cnt++;
            }
            else
            {
                taken[k]=1;
                taken[k-1000]=1;
            }
        }
    }
}

int sub_set[10];

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
       // freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1,tp;

    sub_set[0]=1;

    for(int i=1;i<=6;i++)
        sub_set[i]=3*sub_set[i-1];

    in(t);

    while(t--)
    {
        in(m),in(n),in(k);

        for(int i=0;i<MAX;i++)
        {
            lst[i].clear();
            taken[i]=0;
        }


        for(int i=0;i<n;i++)
        {
            in(tp),in(u),in(v);

            if(tp==2)
            {
                lst[nod(-u) ].pb(nod(-v) );
                lst[nod(v) ].pb(nod(u) );
            }
            else
            {
                if(tp!=3)
                {
                    lst[nod(-u) ].pb(nod(v) );
                    lst[nod(-v) ].pb(nod(u) );
                }
                if(tp!=1)
                {
                    lst[nod(u) ].pb(nod(-v) );
                    lst[nod(v) ].pb(nod(-u) );
                }
            }

        }
        for(int i=0;i<k;i++)
        {
            in(coun[i][0] );
            in(coun[i][1] );
            in(coun[i][2] );
            in(coun[i][3] );
        }



        printf("Case %d: ",tcase++);

        res.clear();

        bool abc=false;

        for(int i=0;i<sub_set[k];i++)
        {

            if(solve(i))
            {
                pf("Possible ");


                print();

                pf("%d",sz(res));
                sort(all(res) );

                for(int i=0;i<sz(res);i++)
                        pf(" %d",res[i] );
                pf(".\n");
                abc=true;
                break;
            }
        }

        if(!abc)
            pf("Impossible.\n");

    }



    return 0;
}





