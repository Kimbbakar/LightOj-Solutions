 /*
 Problem name : 1146 - CLOSEST DISTANCE
 Algorithm : Vector Geomerty + Ternary Search
 Contest/Practice :
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 24-Feb-15
 Last Update : 27-Jan-2015
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

class point
{
    public:
        double x,y;
        point(){}
        point(double x,double y):x(x),y(y){}
        void in()
        {
            scanf("%lf %lf",&x,&y);
        }
        double dis(point a)
        {
            return sqrt( sqr(a.x-x)+sqr(a.y-y) );
        }
} ;

class Vector
{
    public:

        double x,y;
        Vector(){}
        Vector(point A,point B)
        {
            x=(B.x-A.x);
            y=(B.y-A.y);
        }
        point unitvector()
        {
            return point( x/sqrt( sqr(x)+sqr(y) ),y/sqrt( sqr(x)+sqr(y) ) );
        }
};

point a,b,c,d;
double x,y;

double res()
{
    Vector A=Vector(a,b );
    Vector B=Vector(c,d );
    double l=0,r=max(a.dis(b),c.dis(d));

//    what_is(a.dis(b) );

//    what_is(c.dis(d) );

    point u1=A.unitvector();
    point u2=B.unitvector();

    double v1=a.dis(b)/max(a.dis(b),c.dis(d));
    double v2=c.dis(d)/max(a.dis(b),c.dis(d));

    double ans=10000000.0;

    while(r-l>eps)
    {
        double mid1=(2.0*l+r)/3.0;
        double mid2=(2.0*r+l)/3.0;


        point r1=point( a.x+v1*mid1*u1.x,a.y+v1*mid1*u1.y );
        point r2=point( c.x+v2*mid1*u2.x,c.y+v2*mid1*u2.y );

        point r3=point( a.x+v1*mid2*u1.x,a.y+v1*mid2*u1.y );
        point r4=point( c.x+v2*mid2*u2.x,c.y+v2*mid2*u2.y );


        if(r1.dis(r2)<r3.dis(r4) )
        {
            r=mid2;
            ans=min(ans,r1.dis(r2));
        }
        else
        {
            l=mid1;
            ans=min(ans,r3.dis(r4));
        }

    }

    return ans;
}



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
        a.in();
        b.in();
        c.in();
        d.in();

        printf("Case %d: %.10lf\n",tcase++,res());
    }


    return 0;
}


