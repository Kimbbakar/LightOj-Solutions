/*
 Problem name : 1188 - Fast Queries
 Algorithm : Segment Tree
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 13-Dec-14
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
#define on(x,w)         x|(1<<w)
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

class nod
{
public:
    int type,x,y,s;
} ;


bool cmp(nod a,nod b)
{
    if(a.y!=b.y)
    return a.y<b.y;

    return a.type<b.type;
}

nod kp[150008];
int tree[3* 100008 ];
int mark[100008];
int ans[100008];
int n,q;

int build(int nod,int l,int r,int c,int v)
{//printf("-> %d %d %d \n",nod,l,r);pause;

    if(l>c || r<c) return tree[nod];
    if(l==r && c==r)
        return tree[nod]=v ;

    int mid=(l+r)>>1;

    int left=2*nod;
    int right=2*nod+1;


    return tree[nod]=build(left,l,mid,c,v) + build(right,mid+1,r,c,v);

}

int query(int nod,int l,int r,int i,int j)
{//printf("->>> %d %d %d %d %d\n",nod,l,r,i,j);pause
    if(i>r || j<l) return 0;

    if(i<=l && j>=r) return tree[nod];

    int mid=(l+r)>>1;

    int left=2*nod;
    int right=2*nod+1;


    return query(left,l,mid,i,j) + query(right,mid+1,r,i,j);
}




int main()
{
    int t,tcase=1;
    t=in<int>();

    while(t--)
    {
        n=in<int>();
        q=in<int>();

        reset(tree,0);
        reset(mark,-1);

        for(int i=0;i<n;i++)
        {
            kp[i].type=1;
            kp[i].x=in<int>() ;
            kp[i].y=i;//printf("*** %d) %d %d %d\n",i,kp[i].type,kp[i].x,kp[i].y);
        }

        for(int i=n,j=0;i<n+q;i++,j++)
        {
            kp[i].type=2;
            kp[i].x=in<int>()-1;
            kp[i].y=in<int>()-1;//printf("%d\n",i);
            kp[i].s=j;
        }

        sort(kp,kp+n+q,cmp);

        printf("Case %d:\n",tcase++);

        for(int i=0;i<n+q;i++)
        {
            if(kp[i].type==1)
            {//printf("** %d %d %d\n",kp[i].x,kp[i].y,kp[i].type);
                if(mark[kp[i].x]!=-1)
                {
                    build(1,0,n,mark[kp[i].x],0);
                }

                mark[kp[i].x]=kp[i].y;
                build(1,0,n,mark[kp[i].x],1);

            }
            else
            {
                ans[kp[i].s]=query(1,0,n,kp[i].x,kp[i].y );
            }
        }
        for(int i=0;i<q;i++)
            printf("%d\n",ans[i]);
    }

    return 0;
}

