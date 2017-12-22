/*
 Problem name : 1075 - Finding Routes
 Algorithm : Not Sure Yet
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 21-Dec-14
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


int main()
{
    int t,tcase=1,s;
    int mark[340];
    int cnt[340];
    string s1,s2;

    t=in<int>();

    while(t--)
    {
        scanf("%d",&s);

        reset(mark,0);
        reset(cnt,0);

        map<string,int>name1;
        map<int,string>name2;

        int c=1,nw;

        for(int i=1;i<s;i++)
        {
            cin>>s1>>s2;

            if(!name1[s1])
            {
                name1[s1]=c;
                name2[c]=s1;
                c++;
            }
            if(!name1[s2])
            {
                name1[s2]=c;
                name2[c]=s2;
                c++;
            }

            mark[name1[s1]]=name1[s2];
            cnt[name1[s1]]++;
            cnt[name1[s2]]++;
        }

        for(int i=1;i<c;i++)
            if(mark[i] && cnt[i]==1)
            {
                nw=i;
                break;
            }


        printf("Case %d:\n",tcase++);

        for(int i=1;i<=s;i++)
        {
            cout<<name2[nw]<<"\n";

            nw=mark[name1[name2[nw] ]];
        }

        printf("\n");

    }

    return 0;
}

