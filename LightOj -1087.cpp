/*
 Problem name : 1087 - Diablo
 Algorithm : Segment Tree
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 24-Mar-2015
 Last Update : 27-Jan-2015
*/

/*
"
    Well you only need the light when it's burning low
    Only miss the sun when it starts to snow
    Only know you love her when you let her go

    Only know you've been high when you're feeling low
    Only hate the road when youâre missin' home
    Only know you love her when you let her go
    And you let her go


    Staring at the bottom of your glass
    Hoping one day you'll make a dream last
    But dreams come slow and they go so fast

    You see her when you close your eyes
    Maybe one day you'll understand why
    Everything you touch surely dies

    But you only need the light when it's burning low
    Only miss the sun when it starts to snow
    Only know you love her when you let her go

    Only know you've been high when you're feeling low
    Only hate the road when you're missin' home
    Only know you love her when you let her go

    Staring at the ceiling in the dark
    Same old empty feeling in your heart
    'Cause love comes slow and it goes so fast
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

class data
{
	public:
	int ok;
	int v;
};

data tree[4*150005];

int n,q;
int value[150005];


void build(int nod,int l,int r)
{
	if(l==r)
	{
		value[l]==-1?tree[nod].ok=1:tree[nod].ok=0;
		tree[nod].v=value[l];
		return;
	}

	int left=2*nod;
	int right=2*nod+1;
	int mid=(l+r)>>1;

	build(left,l,mid);
	build(right,mid+1,r);

	tree[nod].ok=tree[left].ok+tree[right].ok;
	return;
}

void update(int nod,int l,int r,int x,int va)
{
	if(x<l || r<x) return ;


	if(l==r && x==l)
	{

		va==-1?tree[nod].ok=1:tree[nod].ok=0;//printf("** %d %d %d %d (%d)\n",nod,l,x,va,tree[nod].ok);
		tree[nod].v=va;
		return;
	}

	int left=2*nod;
	int right=2*nod+1;
	int mid=(l+r)>>1;
	//printf("-> %d %d %d\n",l,r,tree[nod].ok );
	update(left,l,mid,x,va);
	update(right,mid+1,r,x,va);

	tree[nod].ok=tree[left].ok+tree[right].ok;	//printf("** %d %d %d\n",l,r,tree[nod].ok );
	return;
}


int kk;
int qu(int nod,int l,int r,int i,int j)
{
	if(j<l || r<i) return 0;
	if(i<=l && r<=j)
	{
		kk=tree[nod].v;
		return tree[ nod].ok;
	}

	int left=2*nod;
	int right=2*nod+1;
	int mid=(l+r)>>1;

	int res=0;
	res+=qu(left,l,mid,i,j);
	res+=qu(right,mid+1,r,i,j);

	return res;
}


int main()
{
   //  std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

	int t=in<int>(),tcase=1;

	while(t--)
	{
		n=in<int>();

		q=in<int>();

		char ch;
		int s=n,z;

		reset(tree,-1);
		reset(value,-1);

		for(int i=1;i<=n;i++)
			value[i]=in<int>();

	build(1,1,n+q);

	printf("Case %d:\n",tcase++);

		for(int i=0;i<q;i++)
		{
			scanf(" %c",&ch);
			//printf("** %c\n",ch);
			if(ch=='a')
			{ //printf("HIsdfsdf\n");
				z=in<int>();
				s++;
				update(1,1,n+q,s,z);

			}

			else
			{
				int l=1,r=n+q;
				z=in<int>();


				while(l<r)
				{
					int mid=(l+r)>>1;

					int get=qu(1,1,n+q,l,mid);

				//	printf("%d %d %d xx= %d z = %d\n",l,r,get,mid-l+1-get,z);

					if(mid-l+1-get<z)
					{
						z-=(mid-l+1-get);
						l=mid+1;
					}
					else
					r=mid;
				}

				qu(1,1,n+q,l,l);
//			//	printf("l = %d %d\n",l ,kk);
				if(kk!=-1 )
				{
					printf("%d\n",kk);
					update(1,1,n+q,l,-1);
				}
				else
					printf("none\n");

			}
		}



	}

    return 0;
}

