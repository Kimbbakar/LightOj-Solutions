/*
 Problem name : 1061 - N Queen Again
 Algorithm : DP
 Contest/Practice : Off Line Practice
 Source :  Light OJ
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 04-May-15
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

/******* ! Code start from here ! *******/

class point
{
public:
    int x[10],y[10];

};

point get[100],kp;
char s[12];
int t,tcase=1,nw;

int dp[10][260],done[10][260]={0},cc=1;

int pross(point gv,point nw,int g,int n)
{
    int x1=gv.x[g],y1=gv.y[g];
    int x2=nw.x[n],y2=nw.y[n];

    if(x1==x2 && y1==y2) return 0;

    if(x1==x2 || y1==y2 || abs(x1-x2)==abs(y1-y2) ) return 1;
    return 2;
}

int re(int p,int st,point a)
{
    if(p==8) return 0;

    if(done[p][st]==cc) return dp[p][st];

    done[p][st]=cc;
    dp[p][st]=inf;
 //what_is(p)
    for(int i=0;i<8;i++)
    {
        if( (st&(1<<i) ) ==0)
        {
            dp[p][st]=min(dp[p][st],pross(kp,a,p+1,i+1)+re(p+1,st|(1<<i) ,a) );
        }
    }

    return dp[p][st];
}

void print_res(int p,int st,point a,int lft)
{
    if(p==8) return ;

 //what_is(p)
    for(int i=0;i<8;i++)
    {
        if( (st&(1<<i) ) ==0 && lft==pross(kp,a,p+1,i+1)+re(p+1,st|(1<<i),a) )
        {
            printf("%d %d %d %d %d\n",p+1,i+1,pross(kp,a,p+1,i+1),kp.x[i+1],kp.y[i+1]);
            print_res(p+1,st|(1<<i) ,a,lft-pross(kp,a,p+1,i+1) );
            return;

        }
    }


}
bool ok(point p,int x,int y)
{
    for(int i=1;i<x;i++)
    {
        if(p.y[i]==y || (abs(p.x[i]-x) )==abs(p.y[i]-y)  ) return false;
    }
    return true;
}

void build(int p,point &x)
{
    if(p==9)
    {
        get[nw++]=x;
        return;
    }

    for(int i=1;i<=8;i++)
    {
        if(ok(x,p,i))
        {
            x.x[p]=p;
            x.y[p]=i;
            build(p+1,x);
        }
    }
}


int main()
{
     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    cin>>t;
    nw=1;
    build(1,kp);

    while(t--)
    {
        nw=1;
        for(int i=1;i<=8;i++)
        {
//            scanf("%s",s+1);
            cin>>(s+1);
            for(int j=1;j<=8;j++)
            {
                if(s[j]=='q')
                {
                    kp.x[nw]=i;
                    kp.y[nw]=j;
                    nw++;
                }

            }
        }

        int res=inf;



        for(int i=1;i<=92;i++)
        {
            int ss=re(0,0,get[i] );
            res=min(res,ss ); //print_res(0,0,get[8] ,ss);

            cc++;
        }

        cout<<"Case "<<tcase++<<": "<<res<<"\n";

    }

    return 0;
}


