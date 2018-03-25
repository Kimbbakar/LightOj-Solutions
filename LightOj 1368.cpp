 /*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
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

int ax[]={0,1,0,-1,1,-1,1,-1};
int ay[]={1,0,-1,0,1,1,-1,-1};

int mark[205][205] ;
int block[205][205][10] ;
double val[205][205] ;

double cost[50005];

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    char s[110][110];
    int q;

    int r,c;





    int t,tcase=1;

    in(t);

    while(t--)
    {

        in(r),in(c);

        for(int i=0;i<r;i++)
        {
            scanf("%s",s[i] );
        }

        reset(cost,0);
        reset(mark,0);
        reset(block,0);
        reset(val,0.0);
        int col=2;

        for(int x=0,i=0;i<r;i++,x+=2)
        {
            for(int y=0,j=0;j<c;j++,y+=2)
            {
                mark[x+1][y]=1;
                mark[x][y+1]=1;
                mark[x+1][y+2]=1;
                mark[x+2][y+1]=1;

                val[x+1][y+1]+=2.429203674;


                if(s[i][j]=='0')
                {
                    val[x][y]+=0.785398163;
                    block[x][y][4] =1;

                    val[x+2][y+2]+=0.785398163;
                    block[x+2][y+2][7] =1;

                    block[x+1][y+1][7]=1;
                    block[x+1][y+1][4]=1;


                }
                else
                {
                    val[x+2][y]+=0.785398163;
                    block[x+2][y][5] =1;

                    val[x][y+2]+=0.785398163;
                    block[x][y+2][6] =1;

                    block[x+1][y+1][5]=1;
                    block[x+1][y+1][6]=1;
                }
            }
        }

        in(q);

        int x,y;

        pf("Case %d:\n",tcase++);

        while(q--)
        {
            in(x),in(y);


            if(!mark[x][y])
            {
                queue<pair<int,int> >q;
                q.push(mp(x,y) );

                mark[x][y]=col;

                cost[col]+=val[x][y];

                while(!q.empty())
                {
                    pair<int,int>nw=q.front();
                    q.pop();
//                    pf("** %d %d %lf\n",nw.F,nw.S,cost[col]);


                    for(int i=0;i<8;i++)
                    {
                        int kx=nw.F+ax[i];
                        int ky=nw.S+ay[i];

                        if(kx<0 || ky<0 || kx>2*r || ky>2*c || mark[kx][ky] || block[nw.F][nw.S][i] ) continue;
  //                      pf("->>>> %d %d\n",kx,ky);

                        cost[col]+=val[kx][ky];

                        mark[kx][ky]=col;

                        q.push(mp(kx,ky) );


                    }

                }
                col++;
            }
            pf("%0.10lf\n",cost[mark[x][y]] );

        }

    }




    return 0;
}




