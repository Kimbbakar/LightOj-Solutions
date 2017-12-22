/*
 Problem name : 1254 - Prison Break
 Algorithm : Bellman Ford
 Contest/Practice : Off Line Practice
 Source : Light OJ
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 19-May-15
 Last Update : 25-Mar-2015
*/

/*
"
    When I look into your eyes
    It's like watching the night sky
    Or a beautiful sunrise
    Well, there's so much they hold
    And just like them old stars
    I see that you've come so far
    To be right where you are
    How old is your soul?

    Well, I won't give up on us
    Even if the skies get rough
    I'm giving you all my love
    I'm still looking up

    And when you're needing your space
    To do some navigating
    I'll be here patiently waiting
    To see what you find

    'Cause even the stars they burn
    Some even fall to the earth
    We've got a lot to learn
    God knows we're worth it
    No, I won't give up

    I don't wanna be someone who walks away so easily
    I'm here to stay and make the difference that I can make
    Our differences they do a lot to teach us how to use
    The tools and gifts we got, yeah, we got a lot at stake
    And in the end, you're still my friend at least we did intend
    For us to work we didn't break, we didn't burn
    We had to learn how to bend without the world caving in
    I had to learn what I've got, and what I'm not, and who I am

    I won't give up on us
    Even if the skies get rough
    I'm giving you all my love
    I'm still looking up, I'm still looking up.

    Well, I won't give up on us (no I'm not giving up)
    God knows I'm tough enough (I am tough, I am loved)
    We've got a lot to learn (we're alive, we are loved)
    God knows we're worth it (and we're worth it)

    I won't give up on us
    Even if the skies get rough
    I'm giving you all my love
    I'm still looking up
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

class nod
{
public:
    int k,c,r;
    nod(){}
    nod(int k,int c,int r)
    {
        this->k=k;
        this->c=c;
        this->r=r;
    }
};

vector<nod>aj_list[108];
int val[108],cost[108][108] ,u,v,w,cap;
bool operator <(nod a,nod b)
{
    return (a.c>b.c);
}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;
    int n,m,q;

    while(t--)
    {
        n=in<int>();
        m=in<int>();

        fill(aj_list,aj_list+n,vector<nod>());

        for(int i=0;i<n;i++)
        {
            val[i]=in<int>();
        }

        for(int i=0;i<m;i++)
        {
            u=in<int>();
            v=in<int>();
            w=in<int>();

            aj_list[u].pb( nod(v,w,0) );
            aj_list[v].pb( nod(u,w,0) );
        }

        q=in<int>();

        printf("Case %d:\n",tcase++);

        while(q--)
        {
            cap=in<int>();
            u=in<int>();
            v=in<int>();
            bool ok=false;

            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=cap;j++)
                    cost[i][j]=inf;
            }

            priority_queue<nod>q;

            q.push(nod(u,0,0));
            cost[u][0]=0;
            int ans;

            while(!q.empty())
            {
                nod nw = q.top();
                q.pop();
                // printf("nw %d : %d\n",nw.k,nw.r);

                if(v==nw.k)
                {
                    ans=nw.c;
                    ok=true;
                    break;
                }

                for(int i=0;i<sz(aj_list[nw.k] );i++)
                {
                    nod k=aj_list[nw.k][i];

                    if(nw.r>=k.c)
                    { //printf("ki %d %d\n",cost[nw.k][nw.r],cost[k.k][nw.r-k.c]);
                        if(cost[nw.k][nw.r]<cost[k.k][nw.r-k.c])
                        { //printf("k %d\n",k.k);
                            cost[k.k][nw.r-k.c]=cost[nw.k][nw.r];
                            q.push(nod(k.k,cost[k.k][nw.r-k.c],nw.r-k.c) );
                        }
                    }
                }

                if(nw.r+1<=cap && cost[nw.k][nw.r+1]>cost[nw.k][nw.r]+val[nw.k])
                {
                    cost[nw.k][nw.r+1]=cost[nw.k][nw.r]+val[nw.k];
                    q.push(nod(nw.k,cost[nw.k][nw.r+1] ,nw.r+1) );
                }
            }

            if(ok)
                printf("%d\n",ans);
            else
                printf("impossible\n");

        }
    }

    return 0;
}

