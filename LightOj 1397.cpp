/*
 Problem name : 1397 - Sudoku Solver
 Algorithm : Not Sure Yet
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 30-May-15
 Last Update : 25-Mar-2015
*/

/*
"
    When I look into your eyes
    It's like watching the night sky
    Or a beautiful sunrise
    Well, there's so much they hold
    And just like them old stars
    I see that you've come so far
    To be right where you are
    How old is your soul?

    Well, I won't give up on us
    Even if the skies get rough
    I'm giving you all my love
    I'm still looking up

    And when you're needing your space
    To do some navigating
    I'll be here patiently waiting
    To see what you find

    'Cause even the stars they burn
    Some even fall to the earth
    We've got a lot to learn
    God knows we're worth it
    No, I won't give up

    I don't wanna be someone who walks away so easily
    I'm here to stay and make the difference that I can make
    Our differences they do a lot to teach us how to use
    The tools and gifts we got, yeah, we got a lot at stake
    And in the end, you're still my friend at least we did intend
    For us to work we didn't break, we didn't burn
    We had to learn how to bend without the world caving in
    I had to learn what I've got, and what I'm not, and who I am

    I won't give up on us
    Even if the skies get rough
    I'm giving you all my love
    I'm still looking up, I'm still looking up.

    Well, I won't give up on us (no I'm not giving up)
    God knows I'm tough enough (I am tough, I am loved)
    We've got a lot to learn (we're alive, we are loved)
    God knows we're worth it (and we're worth it)

    I won't give up on us
    Even if the skies get rough
    I'm giving you all my love
    I'm still looking up
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

bool ok;
char g[15][15];

bool chek(int x,int y,char ch)
{
    bool res=true;

    for(int i=1;i<=9 && res;i++)
    {

        if(g[x][i]==ch || g[i][y]==ch)
        {
            res=false;
        }
    }

    x=( (x-1) /3) *3;
    y=( (y-1) /3) *3;

    for(int i=1;i<=3 && res;i++)
    {
        for(int j=1;j<=3 && res;j++)
        {
            if(g[x+i][y+j]==ch)
                res=false;
        }
    }

    return res;
}

void print()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            printf("%c",g[i][j]);
        }
        printf("\n");
    }
}

bool cnt(int &x,int &y)
{
    int c=110,bst;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            bst=0;

            if(g[i][j]=='.')
            {
                for(int k='1';k<='9';k++)
                {
                    if(chek(i,j,k))
                        bst++;
                }

                if(c>bst)
                {
                    c=bst;
                    x=i;
                    y=j;
                }
            }

        }
    }

    if(c<10) return true;
    return false;
}

void re()
{
    if(!ok) return;

    //print();pause
    int x,y;
    if(!cnt(x,y))
    {


        print();
        ok=false;
        return;
    } //printf("*** %d %d \n",x,y);


    for(char i='1';i<='9' && ok;i++)
    {
      //  printf("** %c (%d %d) \n",i,x,y);
        if(chek(x,y,i))
        {
            g[x][y]=i;
            re();

        }
        g[x][y]='.';
    }
    return;

}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;


    while(t--)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
                scanf(" %c",&g[i][j]);

        }

            // print();


        ok=true;
        printf("Case %d:\n",tcase++);
        re();
    }


    return 0;
}


