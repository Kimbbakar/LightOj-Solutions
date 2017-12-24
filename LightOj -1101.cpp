/*
 Problem name : 1101 - A Secret Mission
 Algorithm : LCA + MST
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 05-Mar-15
 Last Update : 27-Jan-2015
*/
 
/*
    "   কষ্ট নেবে কষ্ট
        হরেক রকম কষ্ট আছে
        কষ্ট নেবে কষ্ট !
        লাল কষ্ট নীল কষ্ট কাঁচা হলুদ রঙের কষ্ট
        পাথর চাপা সবুজ ঘাসের সাদা কষ্ট,
        আলোর মাঝে কালোর কষ্ট
     ‘মাল্টি-কালার’ কষ্ট আছে
        কষ্ট নেবে কষ্ট ।
        ঘরের কষ্ট পরেরর কষ্ট পাখি এবং পাতার কষ্ট
        দাড়ির কষ্ট
        চোখের বুকের নখের কষ্ট,
        একটি মানুষ খুব নীরবে নষ্ট হবার কষ্ট আছে
        কষ্ট নেবে কষ্ট ।
        প্রেমের কষ্ট ঘৃণার কষ্ট নদী এবং নারীর কষ্ট
        অনাদর ও অবহেলার তুমুল কষ্ট,
        ভুল রমণী ভালোবাসার
        ভুল নেতাদের জনসভার
        হাইড্রোজনে দুইটি জোকার নষ্ট হবার কষ্ট আছে
        কষ্ট নেবে কষ্ট ।
        দিনের কষ্ট রাতের কষ্ট
        পথের এবং পায়ের কষ্ট
        অসাধারণ করুণ চারু কষ্ট ফেরীঅলার কষ্ট
        কষ্ট নেবে কষ্ট ।
        আর কে দেবে আমি ছাড়া
        আসল শোভন কষ্ট,
        কার পুড়েছে জন্ম থেকে কপাল এমন
        আমার মত ক’জনের আর
        সব হয়েছে নষ্ট,
        আর কে দেবে আমার মতো হৃষ্টপুষ্ট কষ্ট ।  "
 
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
 
 
class edge
{
public:
    int s,t,w;
 
    void inp()
    {
        s=in<int>();
        t=in<int>();
        w=in<int>();
    }
};
 
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
 
int par[50008];
int dep[50008];
vector<edge>aj_list[50008];
 
 
int union_finder(int x)
{
    if(par[x]==x) return x;
 
    return par[x]=union_finder(par[x]);
}
 
edge edge1[1000008];
//edge edge2[1000008];
int n,m,q;
int table[50008][20];
int res[50008][20];
 
 
void prim()
{
    sort(edge1,edge1+m,cmp);
 
 
    int k=0,i=0;
   
   
 
    while(k<n-1 && i<m)
    {
        edge smpl=edge1[i];
        i++;
 
        int y=union_finder(smpl.s );
        int z=union_finder(smpl.t );
           // printf("->>>> %d %d %d %d %d\n",smpl.s,smpl.t,smpl.w,y,z);
 
        if(y!=z)
        {
            par[z] =y ;
 
         //   printf("**** %d %d %d\n",smpl.s,smpl.t,smpl.w);
 
            aj_list[smpl.s ].pb(smpl);
            //edge2[k++]=smpl;
 
            swap(smpl.s,smpl.t );
 
            aj_list[smpl.s ].pb(smpl);
            k++;
        }
    }
}
 
void bfs()
{
    dep[1]=0;
    par[1]=-1;
 
    queue<int>q;
 
    q.push(1);
 
    while(!q.empty())
    {
        int nw=q.front();
        q.pop();
 
        for(int i=0;i<sz(aj_list[nw] );i++)
        {
            if(dep[aj_list[nw][i] .t]==-1)
            {
                q.push(aj_list[nw][i] .t);
                dep[aj_list[nw][i] .t]=1+dep[nw] ;
                table[aj_list[nw][i] .t][0]=par[aj_list[nw][i] .t]=nw;
                res[aj_list[nw][i] .t][0]=aj_list[nw][i] .w;
//                what_is(aj_list[nw][i] .s) what_is(aj_list[nw][i] .t)
//                what_is(table[aj_list[nw][i] .t][0])
            }
        }
    }
}
 
void sp_table()
{
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(table[i][j-1]!=-1)
            {
                table[i][j]=table[table[i][j-1]][j-1];
//                if(table[i][j]!=-1)
                res[i][j]=max(res[i][j-1],res[table[i][j-1]][j-1] );
            }
        }
    }
 
}
 
int lca(int a,int b)
{
    int next,log;
 
    if(dep[a]<dep[b])
        swap(a,b);
 
    log=0;
   
    while(1)
    {
        next=1+log;
        if((1<<next)>dep[a] )
        break;
        log++; 
    }
 
    int ans=0;
   
  //  printf("%d = %d %d = %d\n",a,dep[a],b,dep[b]);
    
   
    for(int j=log;j>=0;j--)
    {
        if(dep[a]-(1<<j)>=dep[b])
        {
            ans=max(ans,res[a][j]);
            a=table[a][j];
        }
    }
  //  printf("%d = %d %d = %d ans = %d\n",a,dep[a],b,dep[b],ans);
    if(a==b) return ans;
 
 	int p;
    for(int j=log;j>=0;j--)
    {// printf("%d %d = %d %d = %d %d\n",j,a,table[a][j],b,table[b][j],ans);
        if(table[a][j]!=-1 && table[a][j]!=table[b][j])
        {
        	ans=max(ans,res[a][j] );
            ans=max(ans,res[b][j] );
            a=table[a][j];
            b=table[b][j];
        }
        if(table[a][j]!=-1 && table[a][j]==table[b][j])
        {//printf("hi %d\n",p); 
            //a=table[a][j];
           // b=table[b][j];
            p=j; 
        }
 
    }
 
    return ans=max(ans,max(res[a][p],res[b][p] ) );
}
 
 
 
int main()
{
//     std::ios_base::sync_with_stdio(false);
 
    #ifndef ONLINE_JUDGE
 //       freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif
 
    int t=in<int>(),tcase=1;
    int a,b;
 
    while(t--)
    {
        n=in<int>();
        m=in<int>();
 
        for(int i=0;i<m;i++)
            edge1[i].inp();
 
        for(int i=0;i<=n;i++)
            aj_list[i].clear();
 
        for(int i=1;i<=n;i++)
            par[i]=i;
 
        prim();
        reset(dep,-1);
        reset(table,-1);
        reset(res,0);
 
        bfs();
        sp_table();
        q=in<int>();
       
       // for(int i=0;i<n-1;i++)
        //  printf("%d %d %d\n",edge2[i].s,edge2[i].t,edge2[i].w);    
 
        printf("Case %d:\n",tcase++);
 
        while(q--)
        {
            a=in<int>();
            b=in<int>();
 
            printf("%d\n",lca(a,b) );
        }
 
    }
 
 
    return 0;
}
