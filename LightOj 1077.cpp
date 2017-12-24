#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;


long Gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return Gcd(b, a%b);
}

int main()
{
    long long int a,b,c,d,x,y,i,j,t,tcase=1,r;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        r=Gcd(abs(a-c),abs(b-d))+1;
        printf("Case %lld: %lld\n",tcase++,r);
    }
    return 0;
}
