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
#define inf             1<<29
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
    return fast_pow(n,mod-2LL);
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

vector<pair<int,int> >tmp[105];
vector<int >lst[105];
int dp[102][102];
int done[102][102],cc=1;
int n,k;
int pr[104];
int cst[104][104];

void dfs(int nod,int par){
    pr[nod]=par;
  //  pf("%d %d\n",nod,par);

    for(int j=0;j<sz(tmp[nod]);j++){
        pair<int,int>i = tmp[nod][j];

//    for(auto i : tmp[nod]){
        if(i.F==par)
            continue;

        lst[nod].pb(i.F);
        cst[nod][i.F] = i.S;
        dfs(i.F,nod);
    }
}

int re(int nod,int cost,int c){

//    pf("** %d %d %d  %d\n",nod,cost,c ,cost-cst[pr[nod] ] [nod]);
 

    int &res = dp[nod][cost];

    if(done[nod][cost]==cc)
        return res;
    
    done[nod][cost]=cc;
    res =inf;
    int tmp;
 

    for(int i=cst[pr[nod] ][nod] ;i<=cost;i++){
        tmp = 0;
 
     //   pf("%d %d %d %d %d (%d)\n",nod,i,i-cst[pr[nod] ][nod],k-i,cost,res);

        if(sz(lst[nod])  ){ 
            tmp += re(lst[nod][0],i-cst[pr[nod] ][nod],1);
        }
        
        if(sz(lst[pr[nod] ] )>=c+1)
            tmp += re(lst[pr[nod] ][c] ,cost-i ,c+1);

        res=min(res,tmp);


    }

    tmp = 0;
  
    if(sz(lst[nod])){
 
        tmp =1;
        tmp += re(lst[nod][0],k,1);

        if(sz(lst[pr[nod] ] )>=c+1 )
            tmp += re(lst[pr[nod] ][c] ,cost ,c+1); 

        res = min(tmp,res);       
    }
    else{ 
        tmp =1;
        if(sz(lst[pr[nod] ] )>=c+1 ){ 
            tmp += re(lst[pr[nod] ][c] ,cost ,c+1); 

        }

        res = min(tmp,res);       
    } 
 

    return res;

}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;

    in(t);
    int u,v,w;
    lst[0].pb(1);

    while(t--){
        in(n),in(k);

        for(int i=1;i<=n;i++){
            lst[i].clear();
            tmp[i].clear();            
        }

        for(int i=1;i<n;i++){
            in(u), in(v),in(w);

            tmp[u].pb(mp(v,w) );
            tmp[v].pb(mp(u,w) );
        }
        dfs(1,0);

        pf("Case %d: %d\n",tcase++,1+re(1,k,1) );

        cc++;
    }

 
    return 0;
}