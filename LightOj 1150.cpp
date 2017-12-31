/*
 Problem name : 1150 - Ghosts!
 Algorithm : Max-Flow
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 10-Apr-15
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

int cost[205][205];
int c[205][205];
int visit[205][205];
int cap[205][205];
int cap_p[205][205];
int n;
char g[30][30];
int mark[30][30];
vector<int>aj_list[205];
pair<int,int>point[55];

int x[]={1,0,-1,0};
int y[]={0,1,0,-1};

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
        fill(aj_list,aj_list+205,vector<int>());
        int h=0,gs=0;

        reset(cost,inf);
        reset(mark,-1);

        int G=0,H=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf(" %c",&g[i][j]);

                if(g[i][j]=='G')
                    G++;
                else if(g[i][j]=='H')
                    H++;
            }

        }
        int N=n;
        n=G+H;

        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(g[i][j]=='G')
                {
                   gs++;
                   mark[i][j]= gs;
                   aj_list[0].pb(gs);
                   aj_list[gs].pb(0);

                   cap[0][gs]=1;
                   cap[gs][0]=0;

                   c[0][gs]=0;
                   c[gs][0]=0;

                   aj_list[gs].pb(n+gs);
                   aj_list[n+gs].pb(gs);

                   cap[gs][n+gs]=1;
                   cap[n+gs][gs]=0;

                   c[gs][n+gs]=0;
                   c[n+gs][gs]=0;

                    point[gs].F=i;
                    point[gs].S=j;
                }
                else if(g[i][j]=='H')
                {
                   h++;
                   mark[i][j]=h;

                   aj_list[n+G+h].pb(2*n+1);
                   aj_list[2*n+1].pb(n+G+h);

                   cap[n+G+h][2*n+1]=1;
                   cap[2*n+1][n+G+h]=0;

                   c[n+G+h][2*n+1]=0;
                   c[2*n+1][n+G+h]=0;
                  //  printf("%d ->  %d\n",G+h,n+G+h);
                   aj_list[G+h].pb(n+G+h);
                   aj_list[n+G+h].pb(G+h);

                   cap[G+h][n+G+h]=1;
                   cap[n+G+h][G+h]=0;

                   c[G+h][n+G+h]=0;
                   c[n+G+h][G+h]=0;
                }

            }
        }

        int cc=1,mx=0;

        reset(visit,0);

        for(int i=1;i<=gs;i++)
        {


            queue<pair<int,int> >q;

            q.push(point[i]);
            visit[q.front().F][q.front().S]=cc;
            cost[q.front().F][q.front().S]=0;
//what_is(point[i].F );
//what_is(point[i].S );
            while(!q.empty())
            {
                pair<int,int>nw=q.front();
                q.pop();

                for(int j=0;j<4;j++)
                {
                    pair<int,int>k=make_pair(nw.F+x[j],nw.S+y[j]);
                    if(visit[k.F][k.S]!=cc && k.F>0 && k.S>0 && k.F<=N && k.S<=N && g[k.F][k.S]!='#')
                    {
                        visit[k.F][k.S]=cc;
                        cost[k.F][k.S]=1+cost[nw.F][nw.S];

                        if(g[k.F][k.S]=='H')
                        {
                         //   printf("%d %d %d\n",k.F,k.S,cost[k.F][k.S] );
                            aj_list[mark[point[i].F ][point[i].S ]+n].pb(mark[k.F ][k.S ]+G);
                            aj_list[mark[k.F ][k.S ]+G].pb(mark[point[i].F ][point[i].S ]+n);

                            cap[mark[point[i].F ][point[i].S ]+n ][mark[k.F ][k.S ]+G ]=1;
                            cap[mark[k.F ][k.S ]+G ][mark[point[i].F ][point[i].S ]+n ]=0;

                            c[mark[point[i].F ][point[i].S ]+n ][mark[k.F ][k.S ]+G ]=cost[k.F][k.S];
                            c[mark[k.F ][k.S ]+G] [mark[point[i].F ][point[i].S ]+n ]=cost[k.F][k.S];

                            mx=max(mx,cost[k.F][k.S]); //what_is(mx)
                        }
                        q.push(k);

                    }
                }
            }
            cc++;
        }
//pause
        int l=1,r=mx;

        int par[205];
        int ans=inf;// what_is(mx)


        while(l<=r)
        {
            int mid=(l+r)>>1;// what_is(mid)

            for(int i=0;i<=2*n+2;i++)
                for(int j=0;j<=2*n+2;j++)
                cap_p[i][j]=cap[i][j];

            bool ok=true;
            int cnt=0;


            int mn=0;
            while(ok && cnt<h)
            {
                queue<int>q;
                q.push(0);
                visit[0][0]=cc;
                ok=false;

                par[0]=-1;

                while(!q.empty())
                {
                    int nw=q.front();
                    q.pop();
//printf("nw : %d\n",nw);
                    for(int i=0;i<sz(aj_list[nw] ) && !ok;i++)
                    {
                        int k=aj_list[nw][i];
//printf("k : %d c= %d\n",k,c[nw][k]);
                        if(visit[0][k]!=cc && cap_p[nw][k] && c[nw][k]<=mid )
                        {
                            visit[0][k]=cc;
                            par[k]=nw;

                            q.push(k);

                            if(k==2*n+1)
                            {
                                ok=true;

                                while(k!=0)
                                {
                                    cap_p[par[k]][k]--;
                                    cap_p[k][par[k]]++;

                                    mn=max(mn,2*c[par[k] ][k]);

                                    k=par[k];

                                }
cnt++;
                                break;
                            }
                        }
                    } //pause
                }
                cc++;
            } //what_is(cnt)

            if(cnt>=h)
            {
                r=mid-1;
                ans=min(mn,ans);
            }
            else
                l=mid+1;
        }

        printf("Case %d: ",tcase++);
        if(ans+2<inf)
            printf("%d\n",ans+2);
        else
            printf("Vuter Dol Kupokat\n");
    }


    return 0;
}


