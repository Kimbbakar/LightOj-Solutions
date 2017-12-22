// Problem name : 1377 - Blade and Sword
// Algorithm : BFS
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Date : 26-Oct-14
// Comment : Whenever you start to believe  yourself, people also start to believe in you

#include<bits/stdc++.h>

#define pause system("pause");
#define FOR1(i,l) for(i=0;i<l;i++)
#define FOR2(i,l) for(i=1;i<=l;i++)
#define mod 1000000007
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define sqr(x) ( (x)* (x) )
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define pf printf
#define reset(x,v) memset(x,v,sizeof(x));
#define AND &&
#define OR ||

typedef long long ll;
typedef unsigned long long ull;

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
inline void memset1(vector<T>&v,T value)
{
    for(int i=0;i<sz(v);i++)
        v[i]=value;
}
template<class T>
inline void memset2(vector<vector<T> >&v,T value)
{
    for(int i=0;i<sz(v) ;i++)
        for(int j=0;j<sz(v[i]);j++)
            v[i][j]=value;
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
#  define print(x) 0;
#endif

//.......Code start from here ! ......

class nod
{
public:
    int x,y,c,f;

    nod()
    {
        x=y=c=f=0;
    }

    nod(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    nod(int x,int y,int c)
    {
        this->x=x;
        this->y=y;
        this->c=c;
    }
};


char graph[205][205];
int cost[205][205];
vector<nod>s;
nod source,des;

int n,m,x,y,num;

int ax[]={0,1,0,-1};
int ay[]={1,0,-1,0};

inline void input()
{
    //scanf("%d %d",&n,&m);
    n=in<int>();
    m=in<int>();

    for(int i=0;i<n;i++)
    {
        scanf("%s",graph[i]);
        for(int j=0;j<strlen(graph[i]);j++)
        {
            if(graph[i][j]=='P')
                source.x=i,source.y=j;
            else if(graph[i][j]=='D')
                des.x=i,des.y=j;
            else if(graph[i][j]=='*')
            {
                nod l;
                l.x=i;
                l.y=j;
                l.c=0;
                l.f=0;
                s.pb(l);
            }
        }
    }
}

inline int bfs()
{
    queue<nod>q;
    source.c=source.f=0;
    q.push(source);
    if(s.size()==1)
        graph[s[0].x][s[0].y]='#';

    cost[source.x][source.y]=1;
    cost[des.x][des.y]=0;
    bool flag=true;
    int ans=0;
    while(!q.empty())
    {
        nod nw=q.front();
        q.pop();
        bool fresh=true;//printf("now %d %d %d %d\n",nw.x,nw.y,nw.c,flag);
        if(graph[nw.x][nw.y]=='D')
        {
            ans=nw.c;
            break;
        }
        else if(graph[nw.x][nw.y]=='*' && flag==true)
        {
            if(nw.f==1)
            {
                nw.c+=1;//printf("nw %d %d %d\n",nw.x,nw.y,nw.c);
                nw.f=2;
                q.push(nw);//pause
            }
            else if(nw.f==2)
            {
                nod x=nw;
                x.c+=1;
                x.f=3;
                q.push(x);//printf("~~~~ %d %d %d\n",nw.x,nw.y,nw.c);

                for(int i=0;i<sz(s);i++)
                {
                    if(s[i].x==nw.x && s[i].y==nw.y) continue;
                    else
                    {
                        for(int j=0;j<4;j++)
                        {
                            nod my;
                            my.x=s[i].x+ax[j];
                            my.y=s[i].y+ay[j];
                            my.f=nw.f;
                            if(graph[s[i].x+ax[j]][s[i].y+ay[j]]=='*') cost[my.x ][my.y]=1;
                            else if(cost[s[i].x+ax[j]] [s[i].y+ay[j]]==0 && graph[s[i].x+ax[j]] [s[i].y+ay[j]]!='#'  )
                            {//pause;
                              //  printf("&& %d %d -> %d %d (%d,%d)\n",s[i].x,s[i].y,s[i].x+ax[j],s[i].y+ay[j],nw.c);
                                cost[s[i].x+ax[j]] [s[i].y+ay[j]]=1;

                                my.c=nw.c+1;
                                q.push(my);
                            }
                        }
                    }
                }
            }
            else
            {
                for(int i=0;i<4;i++)
                {
                    nod x=nw;
                    if(graph[nw.x+ax[i]] [nw.y+ay[i]]=='*')cost[nw.x+ax[i]] [nw.y+ay[i]]=1;
                    else if(cost[nw.x+ax[i]] [nw.y+ay[i]]==0 && graph[nw.x+ax[i]] [nw.y+ay[i]]!='#')
                    {
                       // printf("%d %d -> %d %d (%d,%d)\n",nw.x,nw.y,nw.x+ax[i],nw.y+ay[i],nw.c);
                        cost[nw.x+ax[i]] [nw.y+ay[i]]=1;
                        x.x+=ax[i];
                        x.y+=ay[i];
                        x.c+=1;
                        q.push(x);
                    }
                }
                flag=false;
            }
        }
        else
        {
            for(int i=0;i<4;i++)
            {//printf("* %d %d -> %d %d (%d)\n",nw.x,nw.y,nw.x+ax[i],nw.y+ay[i],cost[nw.x][nw.y]);
                if(cost[nw.x+ax[i]] [nw.y+ay[i]]==0 && graph[nw.x+ax[i]] [nw.y+ay[i]]!='#')
                {
                    //printf("** %d %d -> %d %d (%d)\n",nw.x,nw.y,nw.x+ax[i],nw.y+ay[i],cost[nw.x][nw.y]);
                    nod x=nw;
                    if(graph[nw.x+ax[i]] [nw.y+ay[i]]=='*')
                    {
                        x.f=1;
                    }
                    cost[nw.x+ax[i]] [nw.y+ay[i]]=1;//printf("Cost of %d\n",cost[nw.x+ax[i]][nw.y+ay[i]] );
                    x.x+=ax[i];
                    x.y+=ay[i];
                    x.c+=1;
                    q.push(x);
                }
            }
        }
    }

    return ans;
}

int main()
{
    int t,tcase;

     t=in<int>();
//    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            memset(cost,0,sizeof(cost));
            s.clear();

            input();

            printf("Case %d: ",tcase++);
            int ans=bfs();
            if(ans)
                printf("%d\n",ans);
            else
                printf("impossible\n");
        }
    }
    return 0;
}


