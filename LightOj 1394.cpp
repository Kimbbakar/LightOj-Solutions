  /*
 Problem name : 1394 - Disable the Wand
 Algorithm : Digit DP
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 18-Sep-15
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

string s1,s2,idls;
int start,ed,maxone,idel,k;

pair<ll,ll> dp[32][32][32][3][7][2] ;
int done[32][32][32][3][7][2] ;
int cc=0;


pair<ll,ll> re(int p,int one, int dif,int thr,int svn,int ok )
{
    if(one>maxone) return mp(0,0);
    if(dif>k) return mp(0,0);

    if(p==32)
    {
        if(thr==0 && svn ) return mp(0,1);
        return mp(0,0);
    }

    if(done[p][one][dif][thr][svn][ok]==cc ) return dp[p][one][dif][thr][svn][ok];

    done[p][one][dif][thr][svn][ok]=cc;
    pair<ll,ll> &r=dp[p][one][dif][thr][svn][ok];
    r=mp(0,0);
    pair<ll,ll>get;

    if(ok)
    {
        // re-place 1

        get=re(p+1,one+1,dif+('1' !=idls[p]), (thr*2+ 1 )%3,(svn*2+ 1 )%7 ,ok  );
        r.F+=( fast_pow(2LL,31LL-p )*get.S + get.F );
        r.S+=get.S;

        // replace 0

        get=re(p+1,one,dif+('0' !=idls[p]), (thr*2 )%3,(svn*2 )%7 ,ok  );
        r.F+=( get.F );
        r.S+=get.S;

    }
    else
    {
        if(s1[p]=='1' )
        {

            // re-place 1

            get=re(p+1,one+1,dif+('1' !=idls[p]), (thr*2+ 1 )%3,(svn*2+ 1 )%7 ,ok  );
            r.F+=( fast_pow(2LL,31LL-p )*get.S + get.F );
            r.S+=get.S;


            // replace 0

            get=re(p+1,one,dif+('0' !=idls[p]), (thr*2 )%3,(svn*2 )%7 ,1  );
            r.F+=(get.F );
            r.S+=get.S;

        }
        else
        {
            get=re(p+1,one,dif+('0' !=idls[p]), (thr*2 )%3,(svn*2 )%7 ,ok  );
            r.F+=(get.F );
            r.S+=get.S;
        }

    }

    return r;


}

//vector<int>xx;

pair<ll,ll> re1(int p,int one, int dif,int thr,int svn,int ok )
{
    if(one>maxone) return mp(0,0);
    if(dif>k) return mp(0,0);

    if(p==32)
    {
//        for(int i=0;i<sz(xx);i++)
//            pf("%d",xx[i]);
//        pf("\n"); what_is(thr) what_is(svn)

        if(thr==0 && svn ) return mp(0,1);
        return mp(0,0);
    }


    if(done[p][one][dif][thr][svn][ok]==cc ) return dp[p][one][dif][thr][svn][ok];

    done[p][one][dif][thr][svn][ok]=cc;
    pair<ll,ll> &r=dp[p][one][dif][thr][svn][ok];
    r=mp(0,0);

    pair<ll,ll>get;

    if(ok)
    {
        // re-place 1

      //  xx.pb(1);

        get=re1(p+1,one+1,dif+('1' !=idls[p]), (thr*2+ 1 )%3,(svn*2+ 1 )%7 ,ok  );

        r.F+=( fast_pow(2LL,31LL-p )*get.S + get.F );
        r.S+=get.S;

       // xx.ppb();

        // replace 0
        //xx.pb(0);

        get=re1(p+1,one,dif+('0' !=idls[p]), (thr*2 )%3,(svn*2 )%7 ,ok  );

        r.F+=(get.F );
        r.S+=get.S;

//xx.ppb();
    }
    else
    {
        if(s2[p]=='1' )
        {
        //xx.pb(1);
            // re-place 1
            get=re1(p+1,one+1,dif+('1' !=idls[p]), (thr*2+ 1 )%3,(svn*2+ 1 )%7 ,ok  );

            r.F+=( fast_pow(2LL,31LL-p )*get.S + get.F );
            r.S+=get.S;

       // xx.ppb();
       // xx.pb(0);
            // replace 0
            get=re1(p+1,one,dif+('0' !=idls[p]), (thr*2 )%3,(svn*2 )%7 ,1  );

            r.F+=( get.F );
            r.S+=get.S;

//xx.ppb();
        }
        else
        {
            get=re1(p+1,one,dif+('0' !=idls[p]), (thr*2 )%3,(svn*2 )%7 ,ok  );
            r.F+=( get.F );
            r.S+=get.S;
        }

    }

    return r;


}



ll res1,res;

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;
    cc=1;
    reset(done,0);

    in(t);

    while(t--)
    {
        in(start),in(ed),in(maxone),in(idel),in(k);

        s1.clear();
        s2.clear();
        idls.clear();



        while(ed>0)
        {
            s2.pb(ed%2+'0' );
            ed/=2;
        }

        if(start)
            start--;

        while(start>0)
        {
            s1.pb(start%2+'0' );
            start/=2;
        }

        while(idel>0)
        {
            idls.pb(idel%2+'0' );
            idel/=2;
        }

        for(int i=sz(s1)+1;i<=32;i++)
        {
            s1.pb('0');
        }

        for(int i=sz(s2)+1;i<=32;i++)
        {
            s2.pb('0');
        }

        for(int i=sz(idls)+1;i<=32;i++)
        {
            idls.pb('0');
        }

        reverse(all(s1) );
        reverse(all(s2) );
        reverse(all(idls) );

//        what_is(s1)
//        what_is(s2)
//        what_is(idls)

        res1=re1(0,0,0,0,0,0).F;
        cc++;
        res=re(0,0,0,0,0,0).F;

        cc++;







        pf("Case %d: %lld\n",tcase++,res1-res);


    }


    return 0;
}
