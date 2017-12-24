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
    int s[105][3];
    char a[10];
    string x,y,z;
    map<string,int>m;
    map<int,string>o;
    int i,j,k,n,num,max,t,count,tcase=1;
    scanf("%d",&t);
    while(t--){
        max=0;
        num=0;
        count=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            cin>>x>>s[i][0]>>s[i][1]>>s[i][2];
            m[x]=i;
            o[i]=x;
            k=s[i][0]*s[i][1]*s[i][2];
            num=num+k;
            if(max<k){
                z=x;
                max=k;
            }
        }
        num=num/n;
        if(num==max){
            printf("Case %d: no thief\n",tcase++);
        }
        else{
            for(i=1;i<=n;i++){
                k=s[i][0]*s[i][1]*s[i][2];
                if(num>k){
                    y=o[i];
                    count++;
                    break;
                }
            }
               printf("Case %d: ",tcase++);
               cout<<z<<" took chocolate from "<<y<<"\n";
        }
    }
    return 0;
}
