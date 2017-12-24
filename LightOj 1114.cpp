/*
 Problem name : 1114 - Easily Readable
 Algorithm : Trie
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 12-Mar-15
 Last Update : 27-Jan-2015
*/

/**

 "  Well you only need the light when it's burning low
    Only miss the sun when it starts to snow
    Only know you love her when you let her go

    Only know you've been high when you're feeling low
    Only hate the road when you’re missin' home
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
    'Cause love comes slow and it goes so fast . "

**/

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


char s1[100005],s[100006];

int trie[100006][55],id,nw,last,len;
int cnt[100006];

void add()
{

    int cur=0;

    for(int i=0;i<len;i++)
    {
        if(s1[i]>='A' && s1[i]<='Z' )
            id=s1[i]-'A';
        else
            id=s1[i]-'a'+26;

        if(trie[cur][id]==-1)
        {
            trie[cur][id]=last++;
        }
        cur=trie[cur][id];
    }
//printf("%s %d %d %d\n",s1,cur,last,cnt[cur]);
    cnt[cur]++;
}

int res()
{
    int cur=0;

    for(int i=0;i<len;i++)
    {
        if(s1[i]>='A' && s1[i]<='Z' )
            id=s1[i]-'A';
        else
            id=s1[i]-'a'+26;

        if(trie[cur][id]==-1)
        {
            return 0;
        }
        cur=trie[cur][id];
    }
//printf("%s %d %d %d\n",s1,cur,last,cnt[cur]);
    return cnt[cur];
}

int main()
{

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
    #endif

    int t=in<int>() ,tcase=1;
    int n;

    while(t--)
    {
        reset(trie,-1);
        reset(cnt,0);
        last=1;

        n=in<int>();

        for(int i=0;i<n;i++)
        {
            scanf("%s",s1);

            len=strlen(s1);

            if(len>2)
            sort(s1+1,s1+len-1);

            add();
        }

        n=in<int>();
        int ans;

        printf("Case %d:\n",tcase++);

        for(int i=0;i<n;i++)
        {
            gets(s);
            ans=1;

            int k=0;

            int len1=strlen(s);
            for(int j=0;j<len1;j++)
            {
                if(s[j]==' ')
                {
                    len=k;
                    s1[k]='\0';

                    if(len>2)
                    sort(s1+1,s1+len-1);

                    if(k)
                        ans*=res();
  //                  printf("%s\n",s1);
    //                what_is(ans)
                    k=0;
                }
                else
                    s1[k++]=s[j];
            }
            if(k)
            {
                len=k;
                s1[k]='\0';

                if(len>2)
                sort(s1+1,s1+len-1);

                if(k)
                    ans*=res();

                k=0;
            }

            printf("%d\n",ans);
        }
    }

}
