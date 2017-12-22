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

int main()
{
    long long n,w,x,y,t,tcase=1,min,count,ara[50005];
    int i,j;
    scanf("%lld",&t);
    while(t--){
        cin>>n>>w;
        j=0;
        for(i=1;i<=n;i++){
            scanf("%lld %lld",&x,&y);
            ara[j++]=y;
        }
        sort(ara,ara+n);
        count=1;
        min=ara[0];
        for(i=1;i<n;i++){
            if(min+w<ara[i]){
                count++;
                min=ara[i];
            }
        }
        printf("Case %lld: %lld\n",tcase++,count);
    }
    return 0;
}
