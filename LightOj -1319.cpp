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
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-10
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define INF 1<<29
#define db double
#define pb push_back
#define pii pair<int64 ,int64 >
#define NL puts("")
#define mx 2000005
//{
//Intput_Output
#define II ({ int a; scanf("%d",&a); a;})
#define IL ({ int64 a; scanf("%lld",&a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;})
#define OC printf("Case %d:",cs);
#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);
//}
//}
template <class T, class U> inline T max (T &a, U &b) {
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b) {
    return a < b ? a : b;
}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

int64 Pow(int64  b,int64  p) {
    int64  ret = 1;
    while(p) {
        if(p&1) ret *= b ;
        p >>= (1LL) , b *= b ;
    }
    return ret ;
}

pair<int64 ,pair<int64 ,int64 > > eea(int64 a, int64 b) {
    int64 gcd,x=0,y=1;
    int64 u=1, v=0, m, n, q, r;
    gcd = b;
    while (a!=0) {
        q=gcd/a;
        r=gcd%a;
        m=x-u*q;
        n=y-v*q;
        gcd=a;
        a=r;
        x=u;
        y=v;
        u=m;
        v=n;
    }
    return make_pair(gcd,make_pair(x,y));
}

int64 BigMod(int64 B,int64 P,int64 M) {
    int64 R=1;    //compute b^p%m
    while(P>0)  {
        if(P%2==1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return (int64)R;
}
int64 modInverse_prime(int64 B,int64 P) {
    return BigMod(B,P-1,P);
}
int64 modInverse_relativePrime(int64 B,int64 P) {
    return eea(B,P).second.first;
}

int64 mod;
int64 fact[mx+5];
vector<pii >primeDivisors;
vector<int64 >L;
vector<int64>N ;
vector<int64>R ;
vector<int64>M ;
vector<int64>N_js ;
vector<int64>M_js ;
vector<int64>R_js;
vector<int64 >e;
void generatefactorial(int64 p) {
    fact[0] = fact[1 ]= 1;
    int64 i;
    for (i = 2; i < mod; i++) {
        if(i%p==0) fact[i] = fact[i-1];
        else fact[i] =  (fact[i - 1] * i)%mod;
    }
}

vector<int64 >v;
vector<int64 > tobase(int64 a,int64 b) {
    v.clear();
    while(a) {
        v.pb(a%b);
        a /= b;
    }
    return v;
}
vector<int64 >tmp;
vector<int64 > compute_js(vector<int64 >v,int64 p,int64 q) {
    int64 len = v.size();
    tmp.clear();
    tmp.resize(len);
    rep(i,len) {
        int64 a = 0,P = 1;
        for(int64 j = i; j<len && j < i+q ; j++) {
            a += (v[j]*P);
            P *= p;
        }
        tmp[i] = a;
    }
    return tmp;
}

vector<int64 > computeE(int64 len,vector<int64 >M,vector<int64 >R,int64 p) {
    int64 m = M.size(),r = R.size(),c = 0;
    tmp.clear();
    tmp.resize(len);
    forab(i,m,len-1) M.pb(0);
    forab(i,r,len-1) R.pb(0);
    rep(i,len) {
        c += M[i];
        c += R[i];
        c /= p;
        tmp[i] = c;
    }
    per(i,len-1) tmp[i] = tmp[i] + tmp[i+1];
    return tmp;
}



int64 generelize_lucas_theoram(int64 n,int64 r,int64 p,int64 q) {
    int64 m = (n-r);
    N = tobase(n,p);
    R = tobase(m,p);
    M = tobase(r,p);
    N_js = compute_js(N,p,q);
    M_js = compute_js(M,p,q);
    R_js = compute_js(R,p,q);
    int64 n_len = N.size() , m_len = M.size() , r_len = R.size();
    e =computeE(n_len,R,M,p);
    int64 ans = 1;
    mod = Pow(p,q);
    generatefactorial(p);
    rep(i,e[0]) ans = (ans*p)%mod;
    rep(i,n_len) ans = (ans*fact[N_js[i]%mod])%mod;
    rep(i,m_len) ans = (ans*modInverse_relativePrime(fact[M_js[i]%mod],mod))%mod;
    rep(i,r_len) ans = (ans*modInverse_relativePrime(fact[R_js[i]%mod],mod))%mod;
    if((p != 2 || q<3) && (q<=e.size() && e[q-1]%2)) ans = (-1*ans)%mod;
    return ans<0?ans+mod:ans;
}

void generate_primeDivisors(int64 n) {
    primeDivisors.clear();

    int64 cnt = 0 ;

    while(n % 2 == 0 ) {
        n>>=1 , cnt++;
    }

    if(cnt) primeDivisors.push_back( pii(2,cnt) );

    int sq = sqrt(n) + 1 ;

    for( int i = 3 ; i <= sq ; i += 2 ) {
        cnt = 0 ;
        while(n % i == 0 ) n /= i , cnt++ ;
        if(cnt) primeDivisors.push_back( pii(i,cnt) );
    }

    if(n > 1 ) primeDivisors.push_back( pii(n,1) ) ;
}


int64 Chinese_Remainder_Theorem(int64 m) {
    int i = 0;
    int64 ans = 0;
    forstl(it,primeDivisors) {
        int64 p = Pow((*it).first,(*it).second);
        //cout << p << endl;
        int64 e = ((m/p) * modInverse_relativePrime(m/p,p))%m;
        ans = (ans + (L[i] * e)%m)%m;
        i++;
    }
    //cout << ans << endl;
    return ans<0?ans+m:ans;
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
    int n;
    ll m;
    ll b,a;

    while(t--){
        primeDivisors.clear();
        L.clear();
        m = 1;

        in(n);

        for(int i=0;i<n;i++){
            in(a),in(b);
            primeDivisors.pb(mp(a,1));
            L.pb(b);
            
            m*=a;          
        }

        pf("Case %d: %lld\n",tcase++,Chinese_Remainder_Theorem(m));

    }


    return 0;
}