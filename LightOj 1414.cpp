// Problem name : 1414 - February 29
// Algorithm : Implementation
// Contest/Practice :
// Source :
// Comment : Whenever you start to believe  yourself,people also start to believe in you
// Date : 02-Oct-14

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<assert.h>


#define pause system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
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
inline void memset1(vector<T>&v,int s,T value)
{
    for(int i=0;i<s;i++)
        v[i]=value;
}

template<class T>
inline void memset2(vector<vector<T> >&v,int s1,int s2,T value)
{
    for(int i=0;i<s1;i++)
        for(int j=0;j<s2;j++)
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

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define print(x) 0;
#endif

//.......Code start from here ! .......

map<string,int>maps;


int main()
{
//    "January", "February", "March", "April", "May","June", "July",
//    "August", "September", "October", "November" and "December"
    maps["January"]=1;
    maps["February"]=2;
    maps["March"]=3;
    maps["April"]=4;
    maps["May"]=5;
    maps["June"]=6;
    maps["July"]=7;
    maps["August"]=8;
    maps["September"]=9;
    maps["October"]=10;
    maps["November"]=11;
    maps["December"]=12;


    int year1,year2,y1,y2,date1,date2;
    string month1,month2;

    int t,tcase=1;

    scanf("%d",&t);
    while(t--)
    {
        cin>>month1;
        scanf("%d,%d",&date1,&year1);

        cin>>month2;
        scanf("%d,%d",&date2,&year2);

        y1=year1-1;


        int count=(year2/400+(year2/4 -year2/100) ) - (y1/400+(y1/4 -y1/100) );
        if(year1==year2)
        {
            if(year2%400==0 || (year2%100!=0 && year2%4==0))
            {
                if(maps[month2]<2 || maps[month1]>2)
                    count--;
                else if(maps[month2]==2 && date2<29)
                    count--;
                else if(maps[month1]==2 && date1>29)
                    count--;
            }
        }
        else
        {
            if(year1%400==0 || (year1%100!=0 && year1%4==0))
            {
                if(maps[month1]>2)
                    count--;
                else if(maps[month1]==2 && date1>29)
                    count--;
            }
            if(year2%400==0 || (year2%100!=0 && year2%4==0))
            {
                if(maps[month2]<2)
                    count--;
                else if(maps[month2]==2 && date2<29)
                    count--;
            }
        }
        printf("Case %d: %d\n",tcase++,count);
    }

    return 0;
}

