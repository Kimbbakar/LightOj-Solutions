// Problem name : 1316 - A Wedding Party
// Algorithm : Bit Mask DP
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself, people also start to believe in you
// Date : 21-Oct-14

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

class nod
{
public:
    int to,cost;
    nod(int to,int cost)
    {
        this->to=to;
        this->cost=cost;
    }

    bool operator <(const nod& a)const
    {
        return cost<a.cost;
    }
};



int call[20];
int cost[505][505];
int n,m,s,num,shop;
vector<nod>aj_list[505];
int dp[20][1<<15];


inline void clr()
{
    for(int i=0;i<20;i++)
    {
        call[i]=-1;
    }


    for(int i=0;i<505;i++)
        for(int j=0;j<505;j++)
             cost[i][j]=100000000;
    for(int i=0;i<505;i++)
        aj_list[i].clear();
}



inline void input()
{

    scanf("%d %d %d",&n,&m,&s);

    //.....shop....

    for(int i=0;i<s;i++)
    {
        scanf("%d",&num);
        call[i]=num;
    }

    //.....Edge.....

    int from,to,cost;

    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&from,&to,&cost);

        aj_list[from].pb(nod(to,cost));
    }

}

inline void dijkstra()
{
    // Calculate ssp for s nod

    int temp[505];
    priority_queue<nod>q;
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<n;j++)
            temp[j]=100000000;
        q.push(nod(call[i],0));

        temp[ call[i] ] = cost[ call[i] ][ call[i] ]  = 0;

        while(!q.empty())
        {
            int nw=q.top().to;
            int c=q.top().cost;

            q.pop();


            for(int j=0;j<aj_list[nw].size();j++)
            {
                 if(temp[aj_list[nw][j].to] > aj_list[nw][j].cost+c )
                 {
                     temp[aj_list[nw][j].to] = aj_list[nw][j].cost+c;

                     q.push( nod( aj_list[nw][j].to,temp[aj_list[nw][j].to] ) );
                 }
            }
        }
        for(int j=0;j<n;j++)
            cost[ call[i] ][j]=temp[j];

    }

    // from source

        for(int j=0;j<n;j++)
            temp[j]=100000000;
        q.push(nod(0,0));

        temp[ 0 ] = cost[ 0 ][ 0 ]  = 0;

        while(!q.empty())
        {
            int nw=q.top().to;
            int c=q.top().cost;

            q.pop();


            for(int j=0;j<aj_list[nw].size();j++)
            {
                 if(temp[aj_list[nw][j].to] > aj_list[nw][j].cost+c )
                 {
                     temp[aj_list[nw][j].to] = aj_list[nw][j].cost+c;

                     q.push( nod( aj_list[nw][j].to,temp[aj_list[nw][j].to] ) );
                 }
            }
        }
        for(int j=0;j<n;j++)
            cost[ 0 ][j]=temp[j];
}


int re1(int from,int mark)
{
    if(mark==(1<<s)-1)
    {
        return (cost[ call[from] ] [n-1]<1000000)? 0:-100000000;
    }

    int &r=dp[from][mark];
    bool done=false;

    if(r!=-1) return r;

    r=0;
    for(int i=0;i<s;i++)
    {
        bool ch=check(mark,i);

        if(!ch)
        {
            int smpl=mark;

            if(mark==0 && cost[0][ call[i] ] < 100000000 )
            {
                smpl=on(smpl,i);

                r=max(r,re1(i,smpl)+ 1 );

                done=true;
            }

            else if(mark > 0 && cost[ call[from] ][ call[i] ] < 100000000)
            {
                smpl=on(smpl,i);

                r=max(r,re1(i,smpl)+ 1 );

                done=true;
            }
        }
    }

    if( done==false || r==0)
        if(cost[ call[from] ][ n-1 ]>=100000000)
            r = -100000000;

    return r;

}


int re2(int from,int mark,int count)
{
    if(count==shop)
    {
        return (cost[ call[from] ] [n-1]<1000000)? cost[ call[from] ] [n-1]:100000000;
    }

    int &r=dp[from][mark];
    bool done=false;

    if(r!=-1) return r;

    r=100000000;
    for(int i=0;i<s;i++)
    {
        bool ch=check(mark,i);

        if(!ch)
        {
            int smpl=mark;

            if(mark==0 && cost[0][ call[i] ] < 100000000 )
            {
                smpl=on(smpl,i);

                r=min(r,re2(i,smpl,count+1)+ cost[0][ call[i] ] );

                done=true;
            }

            else if(mark > 0 && cost[ call[from] ][ call[i] ] < 100000000)
            {
                smpl=on(smpl,i);

                r=min(r,re2(i,smpl,count+1)+ cost[ call[from] ][ call[i] ] );

                done=true;
            }
        }
    }

    if( done==false || r==100000000)
        if(cost[ call[from] ][ n-1 ]>=100000000)
            r = 100000000;

    return r;

}


int main()
{
    int t,tcase=1;

    scanf("%d",&t);

    while(t--)
    {
        clr();

        input();

        dijkstra();

        memset(dp,-1,sizeof(dp) );
        shop=re1(0,0);


        printf("Case %d: ",tcase++);

        if(shop<=0)
            printf("Impossible\n");

        else
        {
            memset(dp,-1,sizeof(dp) );
            printf("%d %d\n",shop,re2(0,0,0));
        }
    }

    return 0;
}


