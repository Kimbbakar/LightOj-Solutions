/*
 Problem name : 1154 - Penguins
 Algorithm : Max Flow
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 22-Mar-15
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

int n,total;
double d;

class data
{
public:
    int x,y;
    int p,j;

    void input()
    {
        x=in<int>();
        y=in<int>();
        p=in<int>();
        total+=p;
        j=in<int>();
    }

    bool dis(data a)
    {
        if(d>=sqrt(sqr(x-a.x)+sqr(y-a.y) ) )
            return true;
        return false;
    }
};

data nod[105];
int cap[305][305];
int cap_s[305][305];
vector<int>aj_list[305];

inline void take()
{
    n=in<int>();
    scanf("%lf",&d);
    total=0;

    for(int i=0;i<=300;i++)
        aj_list[i].clear();

    for(int i=1;i<=n;i++)
    {
        nod[i].input();
    }

    for(int i=1;i<=n;i++)
    {

        aj_list[0].pb(i);
        aj_list[i].pb(0);

        cap[0][i]=nod[i].p;


        aj_list[i].pb(i+n);
        aj_list[i+n].pb(i);

        cap[i][i+n]=nod[i].j;

        for(int j=1;j<=n;j++)
        {
        	if(i==j) continue;
            if(nod[i].dis(nod[j] ))
            {
                aj_list[i+n].pb(j);
                aj_list[j].pb(i+n);

                cap[i+n][j]=inf;
//                printf("%d - > %d  %d\n",i+n,j,cap[i+n][j]);
//				aj_list[j].pb(i+n);
//                aj_list[i+n].pb(j);
//
//                cap[j][i+n]=nod[j].p;
//                cap[i+n][j]=0;

            }
        }
    }
}
int visit[305];
int path[305];
int cost[305];

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
	    reset(cap,0);
	    reset(cap_s,0);
		take();
		reset(visit,0);

		int cc=1,z=0;

		printf("Case %d:",tcase++);

		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n+n+5;j++)
				for(int k=0;k<=n+n+5;k++)
					cap_s[j][k]=cap[j][k];

			bool ok=true;
			int ans=0;

			while(ok && ans<total )
			{
				ok=false;

				stack<int>s;

				s.push(0);

				path[0]=-1;
				cost[0]=inf;


				while(!s.empty() )
				{
					int nw=s.top();
					s.pop();
					visit[nw]=cc;

					if(nw==i)
					{
						int l=nw;
						ans+=cost[nw];//printf("ans %d\n",ans);
						while(l!=0)
						{
							cap_s[path[l]][l]-=cost[nw];
							cap_s[l][path[l]]+=cost[nw];
			//				printf("(%d) ",l);
							l=path[l];
						} //printf("\n");

						break;
					}
//					printf("nw %d\n",nw);
					for(int x=0;x<sz(aj_list[nw] ) && !ok ;x++)
					{
						int o=aj_list[nw][x];
						if(visit[o]!=cc && cap_s[nw][o])
						{
//                        printf("o %d cap_s[nw][o] %d\n",o,cap_s[nw][o]);

							path[o]=nw;
							cost[o]=min(cost[nw],cap_s[nw][o] );
							s.push(o);

							if(o==i)
                                ok=true;

						}
					}
				}

				cc++;
			}
	//			printf("i = %d ans =  %d\n",i,ans);
			if(ans>=total)
				printf(" %d",i-1),z=1;
		}

		if(!z)
		printf(" -1");
		printf("\n");
	}

    return 0;
}

