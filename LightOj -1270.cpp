/*
 Problem name : 1270 - Tiles (II)
 Algorithm : Broken Profile DP
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 19-Nov-14
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

int n,m;

llu dp[1<<8] [10] [105] [2];
int take[1<<8] [10] [105] [2];
int cc;
char grid[105][105];


llu re(int mask,int col,int row, bool oka,int what )
{
//    printf("%d %d %d %d %d\n",mask,row,col,oka,what); pause
    if(row==n) return 1;

    llu &res=dp[mask][col][row][oka];

    if(take[mask][col][row][oka]==cc) return dp[mask][col][row][oka];

    res=0;
    int smpl;

    if(col>=m)
    {
        take[mask][col][row][oka]=cc;
        return res=re(mask,0,row+1,0,0);
    }

    if(col==0 && mask==(1<<m)-1 )
    {
        take[mask][col][row][oka]=cc;
        return res=re(0,0,row+1,0,-1);
    }


    if(check(mask,col)|| grid[row][col]=='#' )
    {
        take[mask][col][row][oka]=cc;
        smpl=mask;
        if(oka==true)on(smpl,col);
        else if(check(mask,col)) smpl-=(1<<col);
        return res=re(smpl,col+1,row,0,-2);
    }

    if(col+1<m) // --
    {
        if(!check(mask,col) && !check(mask,col+1) && grid[row][col]!='#' && grid[row][col+1]!='#' )
        {
            smpl=mask;
            if(oka==true)on(smpl,col);
            res+=re(smpl,col+2,row,false,1);
        }
    }
    if(!oka && !check(mask,col ) && row+1<n) // |
    {
        if(grid[row][col]!='#' && grid[row+1][col]!='#')
        {
            smpl=mask;
            on(smpl,col);
            res+=re(smpl,col+1,row,false,2);
        }

    }


    if(col+1<m && row+1<n)
    {
        if(!oka && !check(mask,col) && grid[row][col]!='#' && grid[row+1][col]!='#' && grid[row+1][col+1]!='#') //L
        {
            smpl=mask;
            on(smpl,col);
            res+=re(smpl,col+1,row,true,3);
        }
    }


    if(col+1<m && row+1<n)
    {
        if(!check(mask,col) && !check(mask,col+1) && grid[row][col]!='#' && grid[row][col+1]!='#' && grid[row+1][col+1]!='#') //
        {
            smpl=mask;
            if(oka==true)on(smpl,col);
            on(smpl,col+1);
            res+=re(smpl,col+2,row,false,4);
        }
    }
    if(col+1<m && row+1<n)
    {
        if(!oka && !check(mask,col) && !check(mask,col+1) && grid[row][col]!='#' && grid[row][col+1]!='#' && grid[row+1][col]!='#') //
        {
            smpl=mask;
            on(smpl,col);
            res+=re(smpl,col+2,row,false,5);
        }
    }
    if(col-1>=0 && row+1<n)
    {
        if(!oka && !check(mask,col-1) && !check(mask,col) && grid[row][col]!='#' && grid[row+1][col]!='#' && grid[row+1][col-1]!='#') //
        {
            smpl=mask;
            on(smpl,col-1);
            on(smpl,col);
            res+=re(smpl,col+1,row,false,6);
        }
    }

    take[mask][col][row][oka]=cc;

    return res;

}

int main()
{
    int t,tcase=1;

    t=in<int>();
    cc=1;

    reset(dp,0);
    reset(take,0);

    while(t--)
    {
        n=in<int>();
        m=in<int>();

        if(m>8)
        {
            char s[105];

            for(int i=0;i<n;i++)
            {
                scanf("%s",s);
                for(int j=0;j<m;j++)
                    grid[j][i]=s[j];
            }
            swap(n,m);
        }
        else
        {
            for(int i=0;i<n;i++)
                scanf("%s",grid[i]);
        }


        printf("Case %d: %llu\n",tcase++,re(0,0,0,0,0));

        cc++;
    }


    /*
11
2 3
...
...
2 3
..#
...
5 5
.....
.....
.....
.....
.....
8 10
..........
..........
..........
..........
..........
..........
..........
..........
    */

    return 0;
}

