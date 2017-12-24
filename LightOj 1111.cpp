#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    int i,j,k,m,n,o,t,tcase=1,a,b,count;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&k,&n,&m);
        queue<int>visitr;
        for(i=1;i<=k;i++){
            scanf("%d",&a);
            visitr.push(a);
        }
        vector<int>road[1005];
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            road[a].push_back(b);
        }
        int gone[1005]={0};
        while(!visitr.empty()){
            queue<int>way;
            way.push(visitr.front());
            int taken[1005]={0};
            while(!way.empty()){
                a=way.front();
                taken[a]=1;
                gone[a]++;
               // printf("<%d=%d>",a,gone[a]);
                for(i=0;i<road[a].size();i++){
                    if(taken[road[a][i]]==0){
                        //gone[road[a][i]]++;
                        taken[road[a][i]]=1;
                        way.push(road[a][i]);
                    }
                }
                way.pop();
            }
            visitr.pop();
        }
        count=0;
        for(i=1;i<=n;i++){
            if(gone[i]==k) count++;
        }
        printf("Case %d: %d\n",tcase++,count);
    }
    return 0;
}
