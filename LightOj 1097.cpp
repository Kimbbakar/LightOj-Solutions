/*
 Problem name : 1097 - Lucky Number
 Algorithm : Segment Tree
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 04-Apr-15
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

int tree[4*1500000];
int res[100005];

void build(int nod,int l,int r)
{
    if(l==r)
    {
        if((l%2) )
            tree[nod]=1;
        else
            tree[nod]=0;
        return;
    }

    int mid=(l+r)>>1;
    int left=2*nod;
    int right=2*nod+1;

    build(left,l,mid);
    build(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];
}

int k,x;
bool ok;

void qu(int nod,int l,int r)
{
  //  printf("%d %d %d %d\n",nod,l,r,k);
    if(l==r)
    {
        if(ok)
            tree[nod]=0;
        x=l;
        return;
    }

    int mid=(l+r)>>1;
    int left=2*nod;
    int right=2*nod+1;

    if(tree[left]>=k)
        qu(left,l,mid);
    else
    {
        k-=tree[left];
        qu(right,mid+1,r);
    }

    tree[nod]=tree[left]+tree[right];
}



int main()
{
 //    std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
 //       freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    build(1,1,1500000);

    res[1]=1;
    for(int i=2;i<=100000;i++)
    {
        ok=false;
        k=i;
        qu(1,1,1500000);
        res[i]=x;
        int kok=x;
//        printf("-> %d :",x);
        for(int j=0;j<=1429431;j+=(kok-1) )
        {
            k=kok+j;
            ok=true;
            qu(1,1,1500000);//printf(" %d",x);
        }
   //     printf("\n");pause;
    }

    int t=in<int>(),tcase=1;
    int n;

    while(t--)
    {
        n=in<int>();

        printf("Case %d: %d\n",tcase++,res[n] );
    }


    return 0;
}

