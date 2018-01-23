/*
 Problem name : 1184 - Marriage Media
 Algorithm : Max Flow
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 30-Mar-15
 Last Update : 25-Mar-2015
*/

/*
"
    Well you only need the light when it's burning low
    Only miss the sun when it starts to snow
    Only know you love her when you let her go

    Only know you've been high when you're feeling low
    Only hate the road when you’re missin' home
    Only know you love her when you let her go
    And you let her go

    Staring at the bottom of your glass
    Hoping one day you'll make a dream last
    But dreams come slow and they go so fast

    You see her when you close your eyes
    Maybe one day you'll understand why
    Everything you touch surely dies

    But you only need the light when it's burning low
    Only miss the sun when it starts to snow
    Only know you love her when you let her go

    Only know you've been high when you're feeling low
    Only hate the road when you're missin' home
    Only know you love her when you let her go

    Staring at the ceiling in the dark
    Same old empty feeling in your heart
    'Cause love comes slow and it goes so fast
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

class nod
{
public:
    int y,h,d;
};

int n,m;
int cap[205][205];
vector<int>aj_list[205];
nod kp[105];
int visit[205]={0},par[205],cc;

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;
    cc=1;

    while(t--)
    {
        reset(cap,0);
        fill(aj_list,aj_list+203,vector<int>() );

        n=in<int>();

        m=in<int>();

        for(int i=1;i<=n;i++)
        {
            kp[i].h=in<int>();
            kp[i].y=in<int>();
            kp[i].d=in<int>();

            if(!cap[0][i] )
                aj_list[0].pb(i);
            cap[0][i]=inf;

            if(!cap[i][i+n+m])
            {
                aj_list[i].pb(i+n+m);
                aj_list[i+n+m].pb(i);
            }
            cap[i][i+n+m]++;

        }


        for(int i=n+1;i<=n+m;i++)
        {
            kp[i].h=in<int>();
            kp[i].y=in<int>();
            kp[i].d=in<int>();

            if(!cap[i+n+m][203] )
                aj_list[i+n+m].pb(203);
            cap[i+n+m][203]=inf;

            if(!cap[i][i+n+m])
            {
                aj_list[i].pb(i+n+m);
                aj_list[i+n+m].pb(i);
            }
            cap[i][i+n+m]++;
     //       cap[i+n+m][i]++;
        }


        for(int i=1;i<=n;i++)
        {
            for(int j=n+1;j<=n+m;j++)
            {
                if( abs(kp[i].y-kp[j].y )<=5 && abs(kp[i].h-kp[j].h )<=12 && (kp[i].d-kp[j].d )==0  )
                {
                    if(!cap[i+n+m][j])
                    {
                        aj_list[i+n+m].pb(j);
                        aj_list[j].pb(i+n+m);

                    }
                    cap[i+n+m][j]++;
//                    cap[j][i+n+m]++;
                }
            }
        }

        bool ok=true;
        int ans=0;
        par[0]=-1;

        while(ok)
        {
            ok=false;

            stack<int>st;

            st.push(0);

            while(!st.empty() )
            {
                int nw=st.top();
                visit[nw]=cc;

                st.pop();

                if(nw==203)
                {
                    ans++;

                    while(nw!=0)
                    {
                        cap[par[nw]][nw]--;
                        cap[nw][par[nw]]++;
                       // printf("%d ",nw);
                        nw=par[nw];
                    } //printf("\n");
                    ok=true;
                    break;

                }
//printf("nw %d\n",nw);
                for(int i=0;i<sz(aj_list[nw] );i++ )
                {
                    int k=aj_list[nw][i];

                    if(visit[k]!=cc && cap[nw][k])
                    {
//printf("k %d\n",k);
                        par[k]=nw;
                        st.push(k);
                    }
                }// pause
            }
            cc++;
        }

        printf("Case %d: %d\n",tcase++,ans);

    }


    return 0;
}


