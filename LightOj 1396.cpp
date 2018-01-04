/*
 Problem name : 1396 - Palindromic Numbers (III)
 Algorithm : Greedy
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 10-Apr-15
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

char s[100005],res[100005];

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
        freopen ( "out2.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;

    while(t--)
    {
        scanf("%s",s);

        int z=strlen(s);

        for(int i=0;i<(z+1)/2;i++)
            res[z-i-1]=res[i]=s[i];
        res[z]='\0';
        bool grtr=false;

        for(int i=0;i<z;i++)
        if(res[i]>s[i])
        {
            grtr=true;
            break;
        }
        else if(res[i]<s[i])
            break;

        printf("Case %d: ",tcase++);

        if(grtr)
            printf("%s\n",res);
        else
        {
            for(int i=(z+1)/2-1;i>=0;i--)
            {
                if(res[i]<'9')
                {
                    res[i]++;
                    break;
                }
                else
                    res[i]='0';
            }
            if(res[0]=='0')
            {
                for(int i=1;i<=z;i++)
                    res[i]='0';

                res[0]=res[z]='1';
                res[z+1]='\0';
            }
            else
            {
                for(int i=0;i<(z+1)/2;i++)
                res[z-i-1]=res[i];
            }
            printf("%s\n",res);
        }
    }

    return 0;
}

