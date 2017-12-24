 /*
 Problem name : 1089 - Points in Segments (II)
 Algorithm : Array Compression + Segment Tree
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 02-Apr-15
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

int tree[4* 50009];
int lazy[4* 50009];
int mark[50009];
int qr[50009];
int n,q;
pair<int,int> kp[50009];

int u,v,sum;

void update(int nod,int l,int r)
{
    if(v<mark[l] || mark[r]<u) return;

    if(u<=mark[l] && mark[r]<=v)
    {
        tree[nod]+= (r-l+1); //printf("%d %d %d(%d) %d(%d) (%d)\n",u,v,mark[l],l,mark[r],l,tree[nod]);pause
        lazy[nod]++;
        return;
    }

    int mid=(l+r)>>1;
    int left=2*nod;
    int right=2*nod+1;

    if(lazy[nod])
    {
        lazy[left]+=lazy[nod] ;
        lazy[right]+=lazy[nod] ;
        //printf("->  %d(%d) %d(%d) %d\n",l,mark[l],r,mark[r] ,lazy[nod] );
        tree[left]+=(mid-l+1)*lazy[nod];
        tree[right]+=(r-mid)*lazy[nod];
        lazy[nod]=0;
    }

    update(left,l,mid);
    update(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];

    return;
}

void query(int nod,int l,int r)
{
    if(u<l || r<u) return;

    if(l==r && u==l)
    {
        sum+=tree[nod];
        return;
    }

    int mid=(l+r)>>1;
    int left=2*nod;
    int right=2*nod+1;

    if(lazy[nod])
    {
        lazy[left]+=lazy[nod] ;
        lazy[right]+=lazy[nod] ;

        tree[left]+=(mid-l+1)*lazy[nod];
        tree[right]+=(r-mid)*lazy[nod];
        lazy[nod]=0;
    }

    query(left,l,mid);
    query(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];

    return;
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;
    int id;

    while(t--)
    {
        n=in<int>();
        q=in<int>();
        id=1;

        reset(tree,0 );


        for(int i=0;i<n;i++)
        {
            kp[i].F=in<int>();
            kp[i].S=in<int>();
        }

        map<int,int>mp;
        vector<int>ss;

        for(int i=0;i<q;i++)
        {
            qr[i]=in<int>();
            ss.pb(qr[i] );
        }

        sort(all(ss) );

        for(int i=0;i<q;i++)
        {
            if(!mp[ss[i]])
            {
                mp[ss[i]]=id;
                mark[id++]=ss[i];
            }
        }reset(lazy,0 );
        for(int i=0;i<n;i++)
        {
            u=kp[i].F;
            v=kp[i].S;

            update(1,1,id-1);
        }

        printf("Case %d:\n",tcase++);

        for(int i=0;i<q;i++)
        {
            u=mp[qr[i] ];
            sum=0;
            query(1,1,id-1);

            printf("%d\n",sum);
        }

    }


    return 0;
}

