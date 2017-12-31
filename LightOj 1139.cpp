/*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
 Last Update : 27-Jan-2015
*/ 

#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             10000007
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

//bool mark[10000009]={0};

class data
{
 public:
    int P[3][3];
    int h,g,f,r,c;


    void in()
    {
        h=g=f=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                scanf("%d",&P[i][j]);
                if(P[i][j]==0)
                {
                    r=i,c=j;
                }
            }
        }

    }

    void print()const
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                printf("%d ",P[i][j] );

            printf("\n");
        }
    }

    int heuristic()const
    {
        int v=0;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(P[i][j]!=0)
                {
                    v+=abs(i-(P[i][j]-1)/3 ) + abs(j-(P[i][j]-1)%3 );
                }
            }
        }

        return v;
    }

    bool checker()const
    {
        bool v=true;

        if(P[2][2]!=0) return false;

        int c=1;

        for(int i=0;i<3 && v;i++)
        {
            for(int j=0;j<3 && v;j++)
            {
              //  if(P[i][j]==0 || (i==2 && j==2)) continue;

                if(P[i][j]!=c && (i!=2 || j!=2) ) v=false;

                c++;
            }
        }

        return v;
    }

    bool solve_able()const
    {
        int c=0;

        for(int i=0;i<9;i++)
        {//printf("**** %d %d %d\n",(i)/3,(i)%3,P[(i)/3 ][(i)%3 ]);

            int l=i/3;
            int r=i%3;
            for(int j=0;j<i && P[l ][r ] ;j++)
            {
                int l1=j/3;
                int r1=j%3;

                if(P[l1 ][r1 ] &&  P[l1 ][r1 ]>P[l ][r ])
                {
                    //printf("%d %d\n",(j)/3,(j)%3 );
                                      c++;
                }

            }
        }

      //  what_is(c)

        return (c%2)==0;
    }

    ll hash_value()const
    {
        ll v=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                v=v*10+P[i][j];
//                v=mod_v(v*(ll) 31+(ll) P[i][j] );
            }
        }

        return v;
    }

    bool operator <(const data& p) const
    {
//        if(g!=p.g) return g>p.g;
  //      return f>p.f;
return f>p.f || (f==p.f && g>p.g);
    }

};

int x[]={-1,0,1,0};
int y[]={0,1,0,-1};


int solve(data& P)
{
    priority_queue<data>q;

    P.f=P.hash_value();

    q.push(P);

    data nw,sp;

    int ans;

    map<long long,int>mark;

    mark[P.hash_value() ]=true;
//    int XX=0;


    while(!q.empty())
    {
        nw=q.top();
        q.pop();

        if(nw.checker())
        {
            ans=nw.g;
            break;
        }

        for(int i=0;i<4;i++)
        {
            sp=nw;

            if(sp.r+x[i]>=0 && sp.c+y[i]>=0 && sp.r+x[i]<3 && sp.c+y[i]<3 )
            {
                swap(sp.P[sp.r][sp.c ],sp.P[sp.r+x[i] ][sp.c+y[i] ] );
                sp.r+=x[i],sp.c+=y[i];

                sp.f=nw.g+sp.heuristic();
                sp.g=nw.g+1;

                if(mark[sp.hash_value()]==false)
                {
                    mark[sp.hash_value()]=true;
                    q.push(sp);//XX++;
                   // sp.print(); what_is(sp.hash_value()) pause
                }
            }
        }

    }

    return ans;
}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
     //   freopen ( "out.txt", "w", stdout );
    #endif

    data res;

    int t=in<int>(),tcase=1;

    while(t--)
    {
        res.in();
     //   reset(mark,false);

        printf("Case %d: ",tcase++);

        if(res.solve_able())
            printf("%d\n",solve(res));
        else
            printf("impossible\n");
    }

    return 0;
}


