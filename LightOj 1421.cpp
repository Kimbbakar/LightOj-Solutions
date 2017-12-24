/*
 Problem name : 1421 - Wavio Sequence
 Algorithm : LIS
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 16-Nov-14
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
#define gcd(x,y)         __gcd(x,y)
#define lcm(x,y)        (x/gcd(x,y))*y
#define on(x,w)         x=x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||

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

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define p(x) 0;
#endif

/*...... ! Code start from here ! ......*/

#define MAX 100000

int I[MAX+5];
int Sequence[MAX+5];
int ans[MAX+5];
int n,sol;

inline void LisIncer()
{ // which runs the NlogK LIS algorithm

    I[0] = -100000009; // I[0] = -infinite

    int LisLength = 0; // keeps the maximum position where a data is inserted

    for(int i = 0; i < n; i++ )
    { // iterate left to right
        int low, high, mid; // variables to perform binary search
        low = 0; // minimum position where we to put data in I[]
        high = LisLength; // the maximum position

        while( low <= high ) { // binary search to find the correct position
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;//printf("%d %d %d %d\n",low,mid,high,I[mid]);
        }
        // observe the binary search carefully, when the binary search ends
        // low > high and we put our item in I[low]
       I[low] = Sequence[i];
        ans[i]=low;
//        printf("%d ",low);
        if( LisLength < low ) // LisLength contains the maximum position
            LisLength = low;
    }
}

inline void LisDcre()
{ // which runs the NlogK LIS algorithm

//    printf("\n");

    I[0] = -100000009; // I[0] = -infinite

    int LisLength = 0; // keeps the maximum position where a data is inserted

    for(int i = n-1; i >=0 ; i-- )
    { // iterate left to right
        int low, high, mid; // variables to perform binary search
        low = 0; // minimum position where we to put data in I[]
        high = LisLength; // the maximum position

        while( low <= high ) { // binary search to find the correct position
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        // observe the binary search carefully, when the binary search ends
        // low > high and we put our item in I[low]
        I[low] = Sequence[i];

        sol=max(sol,min(ans[i],low)*2 );

 //       printf("%d ",low);
        if( LisLength < low ) // LisLength contains the maximum position
            LisLength = low;
    }
}


int main()
{
    int t,tcase=1;

    t=in<int>();

    while(t--)
    {
        n=in<int>();

        for(int i=0;i<n;i++)
            Sequence[i]=in<int>();

        sol=0;
        reset(I,100000009);
        reset(ans,0);
        reset(I,100000009);
        LisIncer();
        LisDcre();
//        printf("\n");
        printf("Case %d: %d\n",tcase++,sol-1);
    }
    return 0;
}


