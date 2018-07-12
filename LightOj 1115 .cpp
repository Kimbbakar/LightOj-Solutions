 

#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000000007
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())//vector must be sorted
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
 

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}

#define debug(args...) {dbg,args; cerr<<endl;}

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int nextInt() { int n; scanf("%d", &n); return n; }
long long nextLong() { long long n; scanf("%lld", &n); return n; }
void print(int n){ printf("%d", n); }
void println(int n){ printf("%d\n", n); }
void println(long long n){ printf("%lld\n", n); }



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

#define MAX 103

int Mark[MAX][MAX];
char inputMap[MAX][MAX];
int n,m;

int dirX[] = {0,1,0,-1,1,-1,1,-1};
int dirY[] = {1,0,-1,0,1,1,-1,-1};

pair<int,int> operator + (pair<int,int>a,pair<int,int>b){
    return {a.F+b.F,a.S+b.S};
}

bool colorBucket(char color,int x,int y){

    queue<pair<int,int> >q;

    q.push({x,y});
    Mark[x][y] = 1;
    bool ok = true;

    while(!q.empty()){
        pair<int,int> nw = q.front();
        q.pop();

        for(int i=0;i<8;i++){
            pair<int,int> nxt = nw + mp(dirX[i],dirY[i] ) ;

            if(nxt.F<0 or nw.S<0 or nxt.F>=n or nxt.S>=m){
                ok = false;
                continue;
            }  
            if(Mark[nxt.F][nxt.S] or inputMap[nxt.F][nxt.S]==color) continue;
 
            Mark[nxt.F][nxt.S] = 1;
            q.push(nxt);            
        }
    }


    return ok;
}


void paint(char color,int x,int y){

    queue<pair<int,int> >q;

    q.push({x,y});
    inputMap[x][y]=color;
    Mark[x][y]=2;

    while(!q.empty()){
        pair<int,int> nw = q.front();
        q.pop();

        for(int i=0;i<8;i++){
            pair<int,int> nxt = nw + mp(dirX[i],dirY[i] ) ;

            if(Mark[nxt.F][nxt.S]==2 or inputMap[nxt.F][nxt.S]==color) continue;

            inputMap[nxt.F][nxt.S] = color;
            Mark[nxt.F][nxt.S] = 2;
            q.push(nxt);            
        }
    }


}

vector<char>st;

void solve(){

    for(int k=0;k<sz(st);k++ ){
        char ch = st[k];
        reset(Mark,0);  

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(Mark[i][j] or inputMap[i][j]==ch ) continue;  
                if(colorBucket(ch,i,j) ) 
                    paint(ch,i,j);  
            }
        }
    }
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
        freopen ( "E:/Code/out.txt", "w", stdout );
    #endif

    int t,tcase=1;

    in(t);

    while(t--){
        in(n),in(m);
        assert(1<=n and n<=50);
        assert(1<=m and m<=50);
        st.clear();

        for(int i=0;i<n;i++){
            scanf("%s",inputMap[i]);
            for(int j=0;j<m;j++)
                if(inputMap[i][j]!='.')
                    st.pb(inputMap[i][j] );            
        }
 
        sort(all(st) );
        UNIQUE(st);

        solve();

        pf("Case %d:\n",tcase++);

        for(int i=0;i<n;i++)
            pf("%s\n",inputMap[i] );
    }


    return 0;
}



