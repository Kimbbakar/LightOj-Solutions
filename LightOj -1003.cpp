#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

 bool comp(int a,int b)
 {
     if(a>b) return true;
     return false;
 }

int main()
{
    int i,j,k,p,count,t,tcase=1,m,n;
    string a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&m);
        vector<int>list[10005];
        map<string,int>mp;
        k=1;
        vector<int>dp(10005);
        for(i=1;i<=m;i++){
            cin>>a>>b;
            if(mp[a]==0) mp[a]=k++;
            if(mp[b]==0) mp[b]=k++;
            //cout<<a<<" "<<mp[a]<<" "<<b<<" "<<mp[b]<<"\n";
            list[mp[a]].push_back(mp[b]);
            dp[mp[b]]++;
        }
        count=0;
        for(i=1;i<k;i++){
            for(j=1;j<k;j++){

                if(dp[j]==0){
                    dp[j]=-1;
                    count++;
                    //printf("Test\n");
                    for(p=0;p<list[j].size();p++){
                        dp[list[j][p]]--;
                        //printf("%d %d\n",list[j][p],dp[list[j][p]]);
                    }
                }
            }
        }
        //sort(dp.begin(),dp.end(),comp);
       printf("Case %d: ",tcase++);
       if(count==(k-1)) printf("Yes\n");
       else printf("No\n");
    }
    return 0;
}
