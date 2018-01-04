/*
 Problem name : 1417 - Forwarding Emails
 Algorithm : SCC (Tarjan)
 Contest/Practice : Off Line Practice
 Source : Light OJ
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 23-Mar-15
 Last Update : 27-Jan-2015
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

class data
{
public:
    int mn,cnt;
};

int visit[50006]={0};
data scc[50006];
int lv[50006];
int mark[50006];
int cc,id,dk;
vector<int>aj_list[50006];
vector<int>aj_list_2[50006];
int n,ans,cans;
stack<int>st;
int cnt,mm;
inline void input()
{
    n=in<int>();
    int a,b;

    for(int i=0;i<=n;i++)
        aj_list[i].clear();

    for(int i=0;i<n;i++)
    {
        a=in<int>();
        b=in<int>();
        aj_list[a].pb(b);
    }
}





int tarjan(int nod)
{
    st.push(nod);

    lv[nod]=id++;
    int mn=lv[nod];
    visit[nod]=cc;

    for(int i=0;i<sz(aj_list[nod] );i++ )
    {
        int k=aj_list[nod][i];
        int xxx=1212112;
        if(visit[k]!=cc )
        {
            mn=min(mn,tarjan(k) );

        }
        else if(lv[k] )
        {
            mn=min(mn,lv[k] );
        }

    }

    if(lv[nod]==mn)
    {
        cnt=0,mm=inf;

        dk++;

        while(1)
        {
            int o=st.top();
            st.pop();
//            printf("%d ",o);
            cnt++;
            mm=min(o,mm);

            lv[o]=0;

            mark[o]=dk;

            if(o==nod)
                break;
        }   //printf("\n*********\n");

        scc[dk].mn=mm;
        scc[dk].cnt=cnt;

    }

    return mn;
}

void dfs(int nod)
{
    visit[nod]=cc;

   // printf("Nw %d\n",nod);

    for(int i=0;i<sz(aj_list_2[nod] );i++)
    {
        if(visit[aj_list_2[nod] [i] ]!=cc)
        {//    printf("k %d\n",aj_list_2[nod] [i]);
            cnt+=scc[aj_list_2[nod] [i] ].cnt;
          //  mm=min(mm,scc[aj_list_2[nod] [i] ].mn);
            dfs(aj_list_2[nod] [i] );
        }
    }

}

int main()
{
    // std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;
    cc=1;
    while(t--)
    {
        id=1,cans=-1,ans=inf,dk=0;
        input();

        for(int i=1;i<=n;i++)
        {
            if(visit[i]!=cc)
            {
                tarjan(i);
            }

        }
        cc++;

        for(int i=0;i<=dk;i++)
            aj_list_2[i] .clear();

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<sz(aj_list[i] );j++ )
            {
                if(mark[i]!=mark[aj_list[i][j] ] )
                {
                    aj_list_2[mark[i] ].pb(mark[aj_list[i][j] ]);
                }

            }
        }

        for(int i=1;i<=dk;i++)
        {
            cnt=scc[i].cnt ,mm=scc[i].mn;
            dfs(i);
//            what_is(cnt)
            if(cans<=cnt)
            {
                if(cans==cnt)
                ans=min(mm,ans);
                else
                    ans=mm;
                cans=cnt;

            }
            cc++;
        }

        printf("Case %d: %d\n",tcase++,ans);
    }

    return 0;
}

