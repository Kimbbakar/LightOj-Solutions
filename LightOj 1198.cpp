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

bool cmp(int a,int b)
{
    return (a>b);
}

int main()
{
    int ara1[55],ara2[55];
    int n,t,i,j,tcase=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&ara1[i]);
        }
        for(i=0;i<n;i++){
            scanf("%d",&ara2[i]);
        }
        sort(ara1,ara1+n);
        sort(ara2,ara2+n,cmp);
        int count=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(ara1[i]>ara2[j] && (ara1[i]!=0 && ara2[j]!=0)){
                    count+=2;
                    ara1[i]=ara2[j]=0;

                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(ara1[i]==ara2[j] && (ara1[i]!=0 && ara2[j]!=0)){
                    count+=1;
                    ara1[i]=ara2[j]=0;

                }
            }
        }

        printf("Case %d: %d\n",tcase++,count);
    }
    return 0;
}
