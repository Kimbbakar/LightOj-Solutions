/*
 Problem name : 1098 - A New Function
 Algorithm : Number Theory
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 12-May-15
 Last Update : 25-Mar-2015
*/

/*
"
      সেই কবে থেকে
        – হুমায়ুন আজাদ
        সেই কবে থেকে জ্বলছি
        জ্ব’লে জ্ব’লে নিভে গেছি ব’লে
        তুমি দেখতে পাও নি ।
        সেই কবে থেকে দাঁড়িয়ে রয়েছি
        দাঁড়িয়ে দাঁড়িয়ে বাতিস্তম্ভের মতো ভেঙে পড়েছি ব’লে
        তুমি লক্ষ্য করো নি ।
        সেই কবে থেকে ডাকছি
        ডাকতে ডাকতে স্বরতন্ত্রি ছিঁড়ে বোবা হয়ে গেছি ব’লে
        তুমি শুনতে পাও নি ‘।
        সেই কবে থেকে ফুটে আছি
        ফুটে ফুটে শাখা থেকে ঝ’রে গেছি ব’লে
        তুমি কখনো তোলো নি ।
        সেই কবে থেকে তাকিয়ে রয়েছি
        তাকিয়ে তাকিয়ে অন্ধ হয়ে গেছি ব’লে
        একবারো তোমাকে দেখি নি ।
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


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
//        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;
    ll sum,num,lim,g;


    while(t--)
    {
        num=in<ll>();

        lim=sqrt(num);

        sum=0;

        for(ll i=2;i<=lim;i++)
        {
            sum+=i; //  i is come from i*i pair

            g = num/i; // Maximum

            if(g<=i) continue;

            else
            {
                sum+=(g-i)*i;

                sum+=(g*(g+1)/2 );
                sum-=(i*(i+1)/2 );
            }


        }

        printf("Case %d: %lld\n",tcase++,sum);
    }

    return 0;
}


