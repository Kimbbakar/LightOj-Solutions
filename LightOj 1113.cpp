#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define F first
#define S second
#define eps 1e-12
 
using namespace std;
int T;
 
 void solve(int i)
  {
   stack <string> back, forw;
   string current="http://www.lightoj.com/",cmd,url;
 
   current="http://www.lightoj.com/";
   url=cmd="";
   while (cmd!="QUIT")
   {
       cin>>cmd; cout<<"\n";
       if (cmd=="QUIT" && i==T) break; 
 
       if (cmd=="BACK")
        {
          if (!back.empty())
           {
            forw.push(current);
            current=back.top();
            back.pop();
            cout<<current;
      //      printf("%s",current.c_str());
           } else cout<<"Ignored";
//         printf("Ignored");
        }
 
       if (cmd=="FORWARD")
        {
          if (!forw.empty())
           {
            back.push(current);
            current=forw.top();
            forw.pop();
            cout<<current;
//          printf("%s",current.c_str());
           } else cout<<"Ignored";
//         printf("Ignored");
        }
 
       if (cmd=="VISIT")  
        {
          cin>>url;
          back.push(current);
          current=url;
          while (!forw.empty()) forw.pop();
          cout<<current;
//              printf("%s",current.c_str());
        }
    }
  }
 
int main()
{
 #ifndef ONLINE_JUDGE
 freopen("input.txt","rt",stdin);
 freopen("output.txt","wt",stdout);
 #endif
 scanf("%d\n",&T);
  FOR(TT,1,T)
   {
    printf ("Case %d:",TT);
    solve(TT);
   }
 
 fclose(stdin); fclose(stdout);
 return 0;
}
