#include <set>
#include <stdio.h>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#define size 1000001

using namespace std;

double ara[size];
int main()

{
    int i,j,k,t,tcase=1;
    long long ans,n,base;
    ara[0]=0;
    for(i=1;i<=size;i++){
      ara[i]=ara[i-1]+log(i);
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&base);
        ans=ara[n]/log(base);
        printf("Case %d: %lld\n",tcase++,ans+1);
    }
    return 0;
}
