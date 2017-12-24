/*
 Problem name : 1348 - Aladdin and the Return Journey
 Algorithm : Segment Tree + RMQ
 Contest/Practice : Off Line Practice
 Source : light OJ
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
    Only hate the road when youre missin' home
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

#define MAX  30005

int tree[4*MAX];
int lazy[4*MAX];
vector<int>aj_list[MAX];
int kp[MAX],mark[MAX],cnt[MAX],value[MAX],xa[MAX],depth[MAX] ;
int table[MAX][15];

int u,v,n,m,q,id,c,sum,x,y;
bool ok;

int dfs(int nod)
{
    kp[nod]=id;
    mark[id++]=nod;

    for(int i=0;i<sz(aj_list[nod] );i++)
    {
        int k=aj_list[nod][i];

        if(!kp[k])
        {
            table[k][0]=nod;
            depth[k]=depth[nod]+1;
            value[k]+=value[nod];
            cnt[nod]+=dfs(k);

        }
    }
    cnt[nod]+=1;

    return cnt[nod];
}

void build(int nod,int l,int r )
{
    if(l==r)
    {
        tree[nod]=value[mark[l]];
        lazy[nod]=0;
        return;
    }

    int mid=(l+r)>>1;
    int left=2*nod;
    int right=2*nod+1;

    build(left,l,mid);
    build(right,mid+1,r);

	lazy[nod]=0;
    tree[nod]=tree[left]+tree[right];
}

void update(int nod,int l,int r )
{
    if(v<l || r<u) return;
    if(u<=l && r<=v)
    {
        tree[nod]+=(r-l+1)*c ;
        lazy[nod]+=c; //printf("%d %d %d\n",l,r,c);
        return;
    }

    int mid=(l+r)>>1;
    int left=2*nod;
    int right=2*nod+1;

    if(lazy[nod])
    {
        lazy[left]+=lazy[nod];
        lazy[right]+=lazy[nod];


        tree[left]+=(mid-l+1)*lazy[nod];
        tree[right]+=(r-mid)*lazy[nod];
        lazy[nod]=0;
    }

    update(left,l,mid);
    update(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];
}


void query(int nod,int l,int r )
{
    if(u<l || r<u) return;
    if(l==r && l==u )
    {
        if(ok)
        sum+=tree[nod];

        else
        sum-=2*tree[nod];
        return;
    }

    int mid=(l+r)>>1;
    int left=2*nod;
    int right=2*nod+1;

    if(lazy[nod])
    {
        lazy[left]+=lazy[nod];
        lazy[right]+=lazy[nod];

        tree[left]+=(mid-l+1)*lazy[nod];
        tree[right]+=(r-mid)*lazy[nod];
        lazy[nod]=0;
    }

    query(left,l,mid);
    query(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];
}

inline void spars()
{
    for(int j=1;(1<<j) <=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(table[i][j-1]!=-1)
            {
                table[i][j]=table[table[i][j-1]][j-1];
               // printf("%d %d %d\n",i,j,table[i][j] );
            }
        }
    }
}

int find_par(int a,int b)
{
	int next,log;
    if(depth[a]<depth[b])
        swap(a,b);
//printf("** %d %d\n",a,b);
   log=0;
       
        while(1)
        {
            next=1+log;
            if((1<<next)>depth[a] )
            break;
            log++;
        }
  
    for(int i=log;i>=0;i--)
    {
        if(depth[a]-(1<<i)>=depth[b])
        {
            a=table[a][i];
        }
    }

    if(a==b) return a;

    for(int i=log;i>=0;i--)
    {
        if(table[a][i]!=table[b][i] && table[a][i]!=-1 && table[b][i]!=-1)
        {
            a=table[a][i];
            b=table[b][i];//printf("%d %d %d\n",a,b,i);
        }
    }

    return table[a][0];

}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;

    while(t--)
    {
        n=in<int>();
// Now....
        id=1;
        reset(table,-1);
        reset(kp,0);
        reset(cnt,0);
        depth[0]=0;
        fill(aj_list,aj_list+n+5,vector<int>() );


        for(int i=0;i<n;i++)
        {
            value[i]=in<int>();
            xa[i]=value[i];
        }

        for(int i=1;i<n;i++)
        {
            u=in<int>();
            v=in<int>();

            aj_list[u].pb(v);
            aj_list[v].pb(u);
        }
// Up
        dfs(0);
        build(1,1,n);
        spars();

        q=in<int>();

        int a;

        printf("Case %d:\n",tcase++);

        for(int i=0;i<q;i++)
        {
            a=in<int>();

            if(a) // update
            {
                int k=in<int>();
                u=kp[k];
                v=u+cnt[k]-1;
//what_is(u) what_is(v)
                c=-xa[k];
                update(1,1,n);

                c=in<int>();
                update(1,1,n);

                xa[k]=c;

            }
            else
            {
                ok=true;
                sum=0;
                int x=in<int>();
                int y=in<int>();

                u=kp[x];

                query(1,1,n); //what_is(sum)


                u=kp[y];

                query(1,1,n);

                a=find_par(x,y);

                ok=false;

                u=kp[a];

                query(1,1,n);//what_is(sum)

                printf("%d\n",sum+xa[a] );
            }
        }


    }

    return 0;
}



