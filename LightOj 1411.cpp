/*
 Problem name : 1411 - Rip Van Winkle`s Code
 Algorithm : Segment Tree
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 09-Apr-2015
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

ll tree[4*250009];
ll lazyA[4*250009];
ll lazyB[4*250009];
ll lazyC[4*250009];
bool ok[4*250009];
ll cntA[4*250009];
ll cntB[4*250009];

ll s[250009];
ll vl,sm;
int u,v;

void updateA(int nod,int l,int r)
{
    if(v<l || r<u) return;
//printf("%d %d\n",l,r);
    if(u<=l && r<=v)
    {
        ll sum=s[r]-s[l-1];
    //    printf("sum %d prv = %d\n",(sum-(r-l+1)*vl+(r-l+1) ),tree[nod]);
        tree[nod]+=(sum-(r-l+1)*vl+(r-l+1) );

        lazyA[nod]+=vl;
        cntA[nod]++;
        return;
    }

    int mid=(l+r)>>1;
    int left=nod<<1;
    int right=left|1;

    if(ok[nod])
    {
        tree[left]=(mid-l+1)*lazyC[nod];
        tree[right]=(r-mid)*lazyC[nod];

        lazyC[left]=lazyC[nod];
        lazyC[right]=lazyC[nod];
        lazyA[left]=lazyA[right]=lazyB[left]=lazyB[right]=lazyC[nod]=cntA[left]=cntB[right]=cntA[right]=cntB[left]=0;
        ok[nod] =false;
        ok[left]=ok[right]=true;
    }
    if(lazyA[nod])
    {
        ll sum=s[mid]-s[l-1];
        tree[left]+=(cntA[nod]* sum-(mid-l+1)*lazyA[nod] +cntA[nod]*(mid-l+1) );

        sum=s[r]-s[mid];
        tree[right]+=(cntA[nod]*sum-(r-mid)*lazyA[nod] +cntA[nod]*(r-mid) );

        lazyA[left]+=lazyA[nod];
        lazyA[right]+=lazyA[nod];

        cntA[left]+=cntA[nod];
        cntA[right]+=cntA[nod];

   //     printf("L = %d R = %d lazy= %d\n",tree[left],tree[right],lazyA[nod]);

        lazyA[nod]=cntA[nod]=0;
    }

    if(lazyB[nod])
    {
        ll sum=s[mid]-s[l-1];
        tree[left]+=((mid-l+1)*lazyB[nod]-cntB[nod]*sum +cntB[nod]*(mid-l+1) );

        sum=s[r]-s[mid];
        tree[right]+=((r-mid)*lazyB[nod]-cntB[nod]*sum +cntB[nod]*(r-mid) );

        lazyB[left]+=lazyB[nod];
        lazyB[right]+=lazyB[nod];

        cntB[left]+=cntB[nod];
        cntB[right]+=cntB[nod];

        lazyB[nod]=cntB[nod]=0;
    }

    updateA(left,l,mid);
    updateA(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];
}

void updateB(int nod,int l,int r)
{
    if(v<l || r<u) return;
//printf("%d %d\n",l,r);
    if(u<=l && r<=v)
    {
        ll sum=s[r]-s[l-1];
  //      printf("prv = %lld\n",tree[nod] );
        tree[nod]+=((r-l+1)*vl-sum+(r-l+1) );
    //    printf("tree[nod] = %lld \n",tree[nod]);
        lazyB[nod]+=vl;
        cntB[nod]++;
        return;
    }

    int mid=(l+r)>>1;
    int left=nod<<1;
    int right=left|1;

    if(ok[nod])
    {
        tree[left]=(mid-l+1)*lazyC[nod];
        tree[right]=(r-mid)*lazyC[nod];

        lazyC[left]=lazyC[nod];
        lazyC[right]=lazyC[nod];
        lazyA[left]=lazyA[right]=lazyB[left]=lazyB[right]=lazyC[nod]=cntA[left]=cntB[right]=cntA[right]=cntB[left]=0;
        ok[nod] =false;
        ok[left]=ok[right]=true;
    }
    if(lazyA[nod])
    {
        ll sum=s[mid]-s[l-1];
        tree[left]+=(cntA[nod]* sum-(mid-l+1)*lazyA[nod] +cntA[nod]*(mid-l+1) );

        sum=s[r]-s[mid];
        tree[right]+=(cntA[nod]*sum-(r-mid)*lazyA[nod] +cntA[nod]*(r-mid) );

        lazyA[left]+=lazyA[nod];
        lazyA[right]+=lazyA[nod];

        cntA[left]+=cntA[nod];
        cntA[right]+=cntA[nod];

   //     printf("L = %d R = %d lazy= %d\n",tree[left],tree[right],lazyA[nod]);

        lazyA[nod]=cntA[nod]=0;
    }

    if(lazyB[nod])
    {
        ll sum=s[mid]-s[l-1];
        tree[left]+=((mid-l+1)*lazyB[nod]-cntB[nod]*sum +cntB[nod]*(mid-l+1) );

        sum=s[r]-s[mid];
        tree[right]+=((r-mid)*lazyB[nod]-cntB[nod]*sum +cntB[nod]*(r-mid) );

        lazyB[left]+=lazyB[nod];
        lazyB[right]+=lazyB[nod];

        cntB[left]+=cntB[nod];
        cntB[right]+=cntB[nod];

        lazyB[nod]=cntB[nod]=0;
    }


    updateB(left,l,mid);
    updateB(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];
}


void updateC(int nod,int l,int r)
{
    if(v<l || r<u) return;

    if(u<=l && r<=v)
    {

        tree[nod]=(r-l+1)*vl ;

        lazyC[nod]=vl;
        lazyA[nod]=lazyB[nod]=0;
        cntA[nod]=cntB[nod]=0;
        ok[nod]=true;
        return;
    }

    int mid=(l+r)>>1;
    int left=nod<<1;
    int right=left|1;

    if(ok[nod])
    {
        tree[left]=(mid-l+1)*lazyC[nod];
        tree[right]=(r-mid)*lazyC[nod];

        lazyC[left]=lazyC[nod];
        lazyC[right]=lazyC[nod];
        lazyA[left]=lazyA[right]=lazyB[left]=lazyB[right]=lazyC[nod]=cntA[left]=cntB[right]=cntA[right]=cntB[left]=0;
        ok[nod] =false;
        ok[left]=ok[right]=true;
    }
    if(lazyA[nod])
    {
        ll sum=s[mid]-s[l-1];
        tree[left]+=(cntA[nod]* sum-(mid-l+1)*lazyA[nod] +cntA[nod]*(mid-l+1) );

        sum=s[r]-s[mid];
        tree[right]+=(cntA[nod]*sum-(r-mid)*lazyA[nod] +cntA[nod]*(r-mid) );

        lazyA[left]+=lazyA[nod];
        lazyA[right]+=lazyA[nod];

        cntA[left]+=cntA[nod];
        cntA[right]+=cntA[nod];

   //     printf("L = %d R = %d lazy= %d\n",tree[left],tree[right],lazyA[nod]);

        lazyA[nod]=cntA[nod]=0;
    }

    if(lazyB[nod])
    {
        ll sum=s[mid]-s[l-1];
        tree[left]+=((mid-l+1)*lazyB[nod]-cntB[nod]*sum +cntB[nod]*(mid-l+1) );

        sum=s[r]-s[mid];
        tree[right]+=((r-mid)*lazyB[nod]-cntB[nod]*sum +cntB[nod]*(r-mid) );

        lazyB[left]+=lazyB[nod];
        lazyB[right]+=lazyB[nod];

        cntB[left]+=cntB[nod];
        cntB[right]+=cntB[nod];

        lazyB[nod]=cntB[nod]=0;
    }

    updateC(left,l,mid);
    updateC(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];
}

void query(int nod,int l,int r)
{
    if(v<l || r<u) return;
//printf("%d %d\n",l,r);
    if(u<=l && r<=v)
    { //printf("sum %d\n",tree[nod]);
        sm+=tree[nod];

        return;
    }

    int mid=(l+r)>>1;
    int left=nod<<1;
    int right=left|1;

    if(ok[nod])
    {
        tree[left]=(mid-l+1)*lazyC[nod];
        tree[right]=(r-mid)*lazyC[nod];

        lazyC[left]=lazyC[nod];
        lazyC[right]=lazyC[nod];
        lazyA[left]=lazyA[right]=lazyB[left]=lazyB[right]=lazyC[nod]=cntA[left]=cntB[right]=cntA[right]=cntB[left]=0;
        ok[nod] =false;
        ok[left]=ok[right]=true;
    }
    if(lazyA[nod])
    {
        ll sum=s[mid]-s[l-1];
        tree[left]+=(cntA[nod]* sum-(mid-l+1)*lazyA[nod] +cntA[nod]*(mid-l+1) );

        sum=s[r]-s[mid];
        tree[right]+=(cntA[nod]*sum-(r-mid)*lazyA[nod] +cntA[nod]*(r-mid) );

        lazyA[left]+=lazyA[nod];
        lazyA[right]+=lazyA[nod];

        cntA[left]+=cntA[nod];
        cntA[right]+=cntA[nod];

   //     printf("L = %d R = %d lazy= %d\n",tree[left],tree[right],lazyA[nod]);

        lazyA[nod]=cntA[nod]=0;
    }

    if(lazyB[nod])
    {
        ll sum=s[mid]-s[l-1];
        tree[left]+=((mid-l+1)*lazyB[nod]-cntB[nod]*sum +cntB[nod]*(mid-l+1) );

        sum=s[r]-s[mid];
        tree[right]+=((r-mid)*lazyB[nod]-cntB[nod]*sum +cntB[nod]*(r-mid) );

        lazyB[left]+=lazyB[nod];
        lazyB[right]+=lazyB[nod];

        cntB[left]+=cntB[nod];
        cntB[right]+=cntB[nod];

        lazyB[nod]=cntB[nod]=0;
    }

    query(left,l,mid);
    query(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];
}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;
    int q,n;
    char ch;

    s[0]=0;

    for(ll i=1;i<=250009;i++)
        s[i]=s[i-1]+i;

    while(t--)
    {
        q=in<int>();
        n=250000;

//        reset(tree,0);
//        reset(lazyA,0);
//        reset(cntA,0);
//        reset(cntB,0);
//        reset(lazyB,0);
//        reset(lazyC,0);

        reset(ok,false);

        u=1,v=n;
        vl=0;
        updateC(1,1,n);

        printf("Case %d:\n",tcase++);

        while(q--)
        {
            scanf(" %c",&ch);

            if(ch=='A')
            {
                u=in<int>();
                v=in<int>();

                vl=(ll) u;
                updateA(1,1,n);
            }
            else if(ch=='B')
            {
                u=in<int>();
                v=in<int>();

                vl=(ll) v;
                updateB(1,1,n);
            }
            else if(ch=='C')
            {
                u=in<int>();
                v=in<int>();
                vl=in<ll>();

                updateC(1,1,n);
            }
            else
            {
                sm=0;

                u=in<int>();
                v=in<int>();

                query(1,1,n);

                printf("%lld\n",sm);

            } //pause
        }
    }

    return 0;
}


