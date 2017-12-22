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
    long long i,count,j,k,d,t,max,tcase=1,n;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        vector<long long>v;
        scanf("%lld",&k);
        d=k;
        max=d;
        v.push_back(d);
        for(i=1;i<n;i++){
            scanf("%lld",&k);
            d=abs(d-k);
            v.push_back(d);
            if(d>max){
                max=d;

            }
            d=k;
        }
        count=0;
        d=max;
        for( i=0; i<v.size(); i++){
            if(d>=v[i]){
                if(d==v[i])
                    d--;
            }
            else{
                count++;
            }
        }

        printf("Case %lld: ",tcase++);
        if(count==0){
            printf("%lld\n",max);
        }
        else{
            printf("%lld\n",max+1);
        }
    }
    return 0;
}
