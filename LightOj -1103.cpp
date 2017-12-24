/*
 Problem name : 1103 - Castle Walls
 Algorithm : Segment Tree
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 03-Apr-15
 Last Update : 25-Mar-2015
*/

/*
"
    তোমার জন্যে পাপ করব
.................................

    ভাবছি,
    সজ্ঞানে তোমার সাথে আমি একটা পাপ করবো।
    জানতে চাও কেনো?
    তাহলে আমাকে আর স্বর্গে যেতে হবে না;
    স্বর্গে গেলেই তো পড়বো হুরপরীদের খপ্পরে।
    তুমিতো জানোই আমি মানুষ,
    ওদের ঐ ভীষণ রূপ
    আমাকে ভাসিয়ে নিয়ে যাবে
    তোমার থেকে দূরে, অনেক দূরে।
    তারচেয়ে বরং নরকের আগুনে অনন্তকাল জ্বলতে জ্বলতে
    তোমাকে যদি মিস করি,
    তোমার কাছে কি সেটাই বেশি রোমান্টিক নয়?
    তাই ভাবছি এবার সত্যি সত্যি তোমার সাথে একটা পাপ করবো ।
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
    ll b,r;
};

nod tree[4*200005];

ll sum;
int u,v,n,m;

void update(int nod,int l,int r,int k)
{
    if(u<l || r<u) return;

    if(l==r && l==u)
    {
        if(k==1)
            tree[nod].b=1;
        else
            tree[nod].r=1;
        return;
    }

    int mid=(l+r)>>1;
    int left=2*nod;
    int right=2*nod+1;

    update(left,l,mid,k);
    update(right,mid+1,r,k);

    tree[nod].b=tree[left].b+tree[right].b;
    tree[nod].r=tree[left].r+tree[right].r;
    return;
}

void query(int nod,int l,int r,int k)
{
    if(v<l || r<u) return;

    if(u<=l && r<=v)
    {
        if(k==1)
            sum+=tree[nod].b;
        else
            sum+=tree[nod].r;
        return;
    }

    int mid=(l+r)>>1;
    int left=2*nod;
    int right=2*nod+1;

    query(left,l,mid,k);
    query(right,mid+1,r,k);
    return;
}

pair<int,int> mark[200007];


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
        m=in<int>();

        reset(tree,0);

        for(int i=1;i<=n;i++)
        {
            u=in<int>();
            v=in<int>();

            mark[u].F=1;//blue
            mark[u].S=v;
        }
        for(int i=1;i<=m;i++)
        {
            u=in<int>();
            v=in<int>();

            mark[u].F=2;//red
            mark[u].S=v;
        }
        sum=0;

        for(int i=1;i<=n+m;i++)
        {
            if(mark[i].F==1)
            {
                u=mark[i].S;
                v=n+m;
                query(1,1,n+m,2);

                u=mark[i].S;
                update(1,1,n+m,1);
            }
            else
            {
                u=mark[i].S;
                v=n+m;
                query(1,1,n+m,1);

                u=mark[i].S;
                update(1,1,n+m,2);
            }
        }

        printf("Case %d: %lld\n",tcase++,sum);

    }


    return 0;
}

