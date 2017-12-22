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
#define max 10000005

bool ara[max];
vector<long long>v;
void seive()
{
    long long i,j;
    memset(ara,true,sizeof(ara));
    ara[0]=ara[1]=false;
    for(i=2;i<=sqrt(max);i++){
        for(j=2;i*j<=max;j++){
            if(ara[i*j]==true){
                ara[i*j]=false;
            }
        }
    }
    for(i=0,j=0;i<max;i++){
        if(ara[i]==true)
            v.push_back(i);
    }
}

int main()
{
    long long n,i,j,k,count;
    int t,tcase=1;
    seive();
    scanf("%d",&t);
    while(t--){
        count=0;
        scanf("%lld",&n);
        for(i=0;v[i]<=(n/2);i++){
            //printf("%lld==%d %lld==%d\n",i,ara[i],n-i,ara[n-i]);
            if(ara[n-v[i]]==true){
                count++;
            }
        }
        printf("Case %d: %lld\n",tcase++,count);
    }
    return 0;
}
