#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef unsigned un;
typedef long long lol;
typedef unsigned long long ulol;

#define pf printf
#define sf scanf
#define pause system("pause")
#define pmin int,vector<int>,greater<int>
#define checkBit(n,p) (bool)(n&(1<<p))
#define setBit(n,p) (n|=(1<<p))
#define resetBit(n,p) (n&=~(1<<p))
#define toggleBit(n,p) (n^=1<<p)
#define init(arr,start,end) memset(arr+start,-1,(end-start+1)*sizeof(arr[0]))
#define PI acos(-1.0)
#define MAX 2147483647
#define UMAX 4294967295u
#define LMAX 9223372036854775807ll
#define ULMAX 18446744073709551615llu
#define gcd(x,y) (__gcd((lol)abs(x),(lol)abs(y)))
#define lcm(x,y) abs(x)/__gcd((lol)abs(x),(lol)abs(y))*abs(y)
#define sqr(x) ((lol)x*x)

int dirK[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1}};
int dir8[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};
int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

/*============================================================================//
              cause nothing lasts forever even cold November rain
//============================================================================*/

bool found;
struct node
{
    bool endMark = false;
    node *next[40] = {NULL};
}*root;

int getVal(char ch)
{
    if(ch>=65&&ch<=90)
    {
        return ch - 55;
    }
    else if(ch>=97&&ch<=122)
    {
        return ch - 87;
    }
    else
    {
        return ch - 48;
    }
}

void insert(string s)
{
    int i,value;
    node *current = root;
    for(i=0;i<s.length();i++)
    {
        if(current->endMark)
        {
            found = true;
        }
        value = getVal(s[i]);
        if(current->next[value]==NULL)
        {
            current->next[value] = new node();
        }
        current = current->next[value];
    }
    if(current->endMark)
    {
        found = true;
    }
    current->endMark = true;
}

bool search(string s)
{
    int i,value;
    node *current = root;
    for(i=0;i<s.length();i++)
    {
        value = getVal(s[i]);
        if(current->next[value]==NULL)
        {
            return false;
        }
        current = current->next[value];
    }
    return current->endMark;
}

void del(node *current)
{
    int i;
    for(i=0;i<40;i++)
    {
        if(current->next[i])
        {
            del(current->next[i]);
        }
    }
    delete(current);
}

string toString(lol num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

vector<string>pos(10005);

int main()
{
    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    //pf("Hello World!\n");
    int t,i,j,k,n;
    sf("%d",&t);
    //getchar();
    for(i=0;i<t;i++)
    {
        int n;
        sf("%d",&n);
        found = false;
        root = new node();
        for(j=0;j<n;j++)
        {
            cin>>pos[j];
        }
        sort(pos.begin(),pos.begin()+n);
        for(j=0;j<n;j++)
        {
            insert(pos[j]);
        }
        del(root);
        if(found)
        {
            pf("Case %d: NO\n",i+1);
        }
        else
        {
            pf("Case %d: YES\n",i+1);
        }
    }
}
