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

int div(int ara[])
{
    int i,j;
    for(i=1;i<=1000;i++){
        for(j=i;j<=1000;j++){
            if(j%i==0){
                ara[j]++;
            }
        }
    }

}

int main()
{
    int ara[1005]={0},i,j,k=1,n,t;
    div(ara);
    int order[1005];
    for(i=1;i<=32;i++){
        for(j=1000;j>=1;j--){
            if(ara[j]==i){
                order[k++]=j;
            }
        }
    }
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        printf("Case %d: %d\n",i,order[n]);
    }
    return 0;

}












