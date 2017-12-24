 /*
 Problem name : 1073 - DNA Sequence
 Algorithm : DP + String
 Contest/Practice : Off Line Practice
 Source : Light OJ
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 15-Oct-15
 Last Update : 25-Mar-2015
*/

/*
    SO STEP INSIDE/ SEE THE DEVIL IN I
    Too many times, we’ve let it come to this
    STEP INSIDE/ SEE THE DEVIL IN I
    Oh, when all that’s left does not make sense
    STEP INSIDE/ SEE THE DEVIL IN I
    I know you’ll find your answers in the end
    STEP INSIDE/ SEE THE DEVIL IN I
    You’ll realize I’m not your Devil… anymore

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

string s;
vector<string>lst;
int n;


int cmp(string a,string b)
{
    int res=0;

    for(int i=0;i<sz(a);i++)
    {
        int cnt=0;
        int j;
        for(j=0;j+i<sz(a) && j<sz(b);j++)
        {
            if(a[i+j]!=b[j]) break;
            cnt++;
        }

        if(j==sz(b) || j+i==sz(a))
        res=max(cnt,res);
    }

    return res;
}

int dp[1<<16][20];
int pre[20][20];

int done[1<<16][20]={0},cc=1;

int re(int mask,int last)
{
    if(mask==(1<<n)-1) return 0;


    if(done[mask][last]==cc) return dp[mask][last];

    done[mask][last]=cc;

    int &r=dp[mask][last];
    r=inf;
    int g;

    for(int i=0;i<n;i++)
    {
        if( !(mask&(1<<i) ) )
        {
            g=pre[last][i] ;

            if(g==sz(lst[i]) && sz(lst[last])>sz(lst[i]) )
                r=min(r,re(mask|(1<<i),last ));
            else
                r=min(r,sz(lst[i])-g+ re(mask|(1<<i),i ));
        }
    }

    return r;
}

void print_res(int mask,int last,int val)
{
    if(mask==(1<<n)-1 || (val<=0))
    {
        pf("\n");
        return;
    }

    int g;
    string mn="Z";
    int idx;

    for(int i=0;i<n;i++)
    {
        if( !(mask&(1<<i) ) )
        {
            g=pre[last][i] ;

            if(g==sz(lst[i]) && sz(lst[last])>sz(lst[i]) && re(mask|(1<<i),last )==val)
            {
                print_res(mask|(1<<i),last,val );
                return;
            }

            else if(sz(lst[i])-g+ re(mask|(1<<i),i )==val)
            {
                string smpl=lst[i].substr(g,lst[i].length() );
                if(smpl<mn)
                {
                    mn=smpl;
                    idx=i;
                }
            }
        }
    }
    //what_is(mn)
    cout<<mn;
    print_res(mask|(1<<idx),idx,val-sz(mn) );
    return;

}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;
    reset(done,0);

    in(t);

    while(t--)
    {
        in(n);
        lst.clear();

        for(int i=1;i<=n;i++)
        {
            cin>>s;

            lst.pb(s);
        }

        sort(all(lst) );

        n=unique(all(lst) )-lst.begin();


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;

                pre[i][j]=cmp(lst[i],lst[j]);
            }
        }

        int res=inf;

        for(int i=0;i<n;i++)
        {
            res=min(res,sz(lst[i])+re((1<<i),i ));

        }

        pf("Case %d: ",tcase++ );


        for(int i=0;i<n;i++)
        {
            if(res==sz(lst[i])+re((1<<i),i ))
            {
                cout<<lst[i];
                print_res((1<<i),i,res-sz(lst[i]));

                break;
            }

        }

        cc++;
    }


    return 0;
}


