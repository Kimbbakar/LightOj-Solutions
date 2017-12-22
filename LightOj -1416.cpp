 /*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
 Last Update : 25-Mar-2015
*/

/*
    Am I wrong for thinking out the box from where I stay?
    Am I wrong for saying that I choose another way?

    I ain't tryna do what everybody else doing
    Just cause everybody doing what they all do
    If one thing I know, I'll fall but I'll grow
    I'm walking down this road of mine, this road that I call home

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


string a,b,c;

pair<int,int> dp[105][105][305];
int don[105][105][305]={0},cc=1;
int x[105][30];
int y[105][30];
int z[305][30];

pair<int,int> re(int l,int r,int p)
{
   // pf("%d %d %d\n",l,r,p);
    if( (sz(a)>l || sz(b)>r)  && p==sz(c) ) return mp(inf,0);
    if(sz(a)==l && sz(b)==r) return mp(0,1);

    pair<int,int> &res=dp[l][r][p];

    if(don[l][r][p]==cc) return res;

    don[l][r][p]=cc;
    res=mp(inf,0);
    pair<int,int>g;

    for(int i=0;i<26;i++)
    {
        if(x[l][i]!=-1 && y[r][i]!=-1 && z[p][i]!=-1  )
        {
            g=re(x[l][i]+1,y[r][i]+1,z[p][i]+1);
            g.F++;

            if(g.F==res.F)
                res.S=(res.S+g.S);
            else if(res.F>g.F)res=g;

        }
//        what_is(re(x[l][i]+1,y[r][i],z[p][i]+1))

        else if(x[l][i]!=-1 && z[p][i]!=-1 )
        {
            g=re(x[l][i]+1,r,z[p][i]+1);
            g.F++;

            if(g.F==res.F)
                res.S=(res.S+g.S);
            else if(res.F>g.F)res=g;

        }
        else if(y[r][i]!=-1 && z[p][i]!=-1  )
        {
            g=re(l,y[r][i]+1,z[p][i]+1);
            g.F++;

            if(g.F==res.F)
                res.S=(res.S+g.S);
            else if(res.F>g.F)res=g;
        }

    }

    res.S=mod_v(res.S);

    return res;
}
string s;

void fuck(int l,int r,int p,int val)
{
    if(val==0) return ;
    bool ok=true;



    for(int i=0;i<26;i++)
    {
        if(x[l][i]!=-1 && y[r][i]!=-1 && z[p][i]!=-1 && val==1+re(x[l][i]+1,y[r][i]+1,z[p][i]+1).F )
        {
            if(ok)
            {
                s.pb(i+'a');
                ok=false;
            }

            fuck(x[l][i]+1,y[r][i]+1,z[p][i]+1,val-1);
            return;
        }
//        what_is(re(x[l][i]+1,y[r][i],z[p][i]+1))

        if(x[l][i]!=-1 && z[p][i]!=-1 && val==1+re(x[l][i]+1,r,z[p][i]+1).F )
        {
            if(ok)
            {
                s.pb(i+'a');
                ok=false;
            }

            fuck(x[l][i]+1,r,z[p][i]+1,val-1);
            return;
        }
        if(y[r][i]!=-1 && z[p][i]!=-1 && val==1+re(l,y[r][i]+1,z[p][i]+1).F )
        {
            if(ok)
            {
                s.pb(i+'a');
                ok=false;
            }

            fuck(l,y[r][i]+1,z[p][i]+1,val-1);
            return;
        }

    }


}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;

    in(t);

    while(t--)
    {
        cin>>a>>b>>c;

        reset(x,-1);
        reset(y,-1);
        reset(z,-1);

        for(int i=sz(a)-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
                x[i][j]=z[i+1][j];

            x[i][a[i]-'a']=i;
        }

        for(int i=sz(b)-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
                y[i][j]=z[i+1][j];

            y[i][b[i]-'a']=i;
        }

        for(int i=sz(c)-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
                z[i][j]=z[i+1][j];

            z[i][c[i]-'a']=i;
        }
        s.clear();

        pair<int,int> g=re(0,0,0);

        pf("Case %d: ",tcase++);

        if(g.F==inf)
        {
            pf("0\nNOT FOUND\n");
        }
        else
        {
            pf("%d\n",g.S);
            fuck(0,0,0,g.F);

            cout<<s<<"\n";
        }

        cc++;


    }


    return 0;
}



