/*
 Problem name : 1055 - Going Together
 Algorithm : BFS
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 17-May-15
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

class nod
{
public:
    int x1,x2,x3,y1,y2,y3;

    nod()
    {

    }

    nod(int x1,int x2,int x3,int y1,int y2,int y3)
    {
        this->x1=x1;
        this->x2=x2;
        this->x3=x3;

        this->y1=y1;
        this->y2=y2;
        this->y3=y3;
    }
};


int visit[12][12][12][12][12][12];

char g[12][12];
int x[]={1,0,-1,-0};
int y[]={0,1,-0,-1};

bool chk(int x1,int x2,int x3,int y1,int y2,int y3)
{
	if(g[x1][y1]=='X' && g[x2][y2]=='X' && g[x3][y3]=='X' )
		return true;
	return false;
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
//        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t=in<int>(),tcase=1;
    int n;
    nod st,ds;
    int x1,x2,x3,y1,y2,y3;
    bool ok;

    while(t--)
    {
        n=in<int>();
        int c=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf(" %c",&g[i][j] );

                if(g[i][j]=='A')
                {
                    st.x1=i;
                    st.y1=j;
                }
                else if(g[i][j]=='B')
                {
                    st.x2=i;
                    st.y2=j;
                }
                else if(g[i][j]=='C')
                {
                    st.x3=i;
                    st.y3=j;
                }
                else if(g[i][j]=='X')
                {
                	if(c==0)
                	{
                		ds.x1=i;
                		ds.x1=j;

                	}
					else if(c==1)
                	{
                		ds.x2=i;
                		ds.x2=j;

                	}                	
					else if(c==3)
                	{
                		ds.x3=i;
                		ds.x3=j;

                	}
                	c++;
                }
            }
        }

        queue<nod>q;
        ok=false;
        
        reset(visit,0);
	    visit[st.x1][st.y1][st.x2][st.y2][st.x3][st.y3]=1;

        q.push(st);            
        int res=0;
        //nod nw=q.front();
	      //  printf("nw = %d %d %d %d %d %d\n",nw.x1,nw.y1,nw.x2,nw.y2,nw.x3,nw.y3);
        while(!q.empty() && !ok)
        {
            nod nw=q.front();
            q.pop();

	       // printf("nw = %d %d %d %d %d %d\n",nw.x1,nw.y1,nw.x2,nw.y2,nw.x3,nw.y3);
            for(int i=0;i<4 && !ok;i++)
            {
                x1=nw.x1+x[i];
                y1=nw.y1+y[i];

                x2=nw.x2+x[i];
                y2=nw.y2+y[i];

                x3=nw.x3+x[i];
                y3=nw.y3+y[i];
                
              // printf("k2 = %d %d %d %d %d %d\n",x1,y1,x2,y2,x3,y3);

                if( (x1<1 || y1<1 || x1>n || y1>n) || (g[x1][y1]=='#' && x1>=1 && y1>=1 && x1<=n && y1<=n) )
                { 
                    x1=nw.x1;
                    y1=nw.y1; 
                    
                    //printf("hi %d %d %d %c %d\n",n,x1,y1,g[x1][y1],(x1<1 || y1<1 || x1>n || y1>n) || (g[x1][y1]=='#' && x1>=1 && y1>=1 && x1<=n && y1<=n));
                    
                    if(x2==x1 && y2==y1)
                    {
		                x2=nw.x2;
		                y2=nw.y2;                    	
						if(x3==x2 && y3==y2)
	                    {
		                    x3=nw.x3;
		                    y3=nw.y3;                    	
	                    }
                    }
                    if(x3==x1 && y3==y1)
                    {
	                    x3=nw.x3;
	                    y3=nw.y3;                    	
	                    if(x2==x3 && y2==y3)
	                    {
			                x2=nw.x2;
			                y2=nw.y2;                    	
	                    }
                    }
                }
                if(x2<1 || y2<1 || x2>n || y2>n || (g[x2][y2]=='#' && x2>=1 && y2>=1 && x2<=n && y2<=n) )
                {
                    x2=nw.x2;
                    y2=nw.y2;

                    if(x1==x2 && y1==y2)
                    {
	                    x1=nw.x1;
	                    y1=nw.y1;
	                    if(x3==x1 && y3==y1)
	                    {
		                    x3=nw.x3;
		                    y3=nw.y3;                    	
		                 
	                    }
                    }
                    if(x3==x2 && y3==y2)
                    {
	                    x3=nw.x3;
	                    y3=nw.y3;
	                    if(x1==x3 && y1==y3)
	                    {
		                    x1=nw.x1;
		                    y1=nw.y1;
	                    }
                    }

                }
                if(x3<1 || y3<1 || x3>n || y3>n || (g[x3][y3]=='#' && x3>=1 && y3>=1 && x3<=n && y3<=n) )
                {
                    x3=nw.x3;
                    y3=nw.y3;
                    if(x1==x3 && y1==y3)
                    {
	                    x1=nw.x1;
	                    y1=nw.y1;
                    	if(x2==x1 && y2==y1)
	                    {
			                x2=nw.x2;
			                y2=nw.y2;                    	
	                    }
                    }
                    if(x2==x3 && y2==y3)
                    {
		                x2=nw.x2;
		                y2=nw.y2;
		                if(x1==x2 && y1==y2)
	                    {
		                    x1=nw.x1;
		                    y1=nw.y1;
		                    
	                    }
                    }
                }
                // printf("k = %d %d %d %d %d %d\n",x1,y1,x2,y2,x3,y3);
 				if(chk(x1,x2,x3,y1,y2,y3))
 				{
					res = visit[nw.x1][nw.y1][nw.x2][nw.y2][nw.x3][nw.y3] ; 					
 					ok=true;
 					break;
 				}
 				else if(!visit[x1][y1][x2][y2][x3][y3] )
				{//printf("Im ok\n");
					visit[x1][y1][x2][y2][x3][y3] = 1+visit[nw.x1][nw.y1][nw.x2][nw.y2][nw.x3][nw.y3] ;
					q.push( nod(x1,x2,x3,y1,y2,y3));
				} 

            }

        }
         
        if(ok)
	        printf("Case %d: %d\n",tcase++,res);
    	else 
	        printf("Case %d: trapped\n",tcase++);
    }


    return 0;
}

