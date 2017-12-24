#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    int i,j,k,count,n,m,a,b,t,tcase=1,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        count=0;
        vector<int>list[105];
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            list[a].push_back(b);
            list[b].push_back(a);
        }

        queue<int>q;
        q.push(1);
        int walk[105]={0};
        int sit[105]={0};
        int flag;

        while(!q.empty()){
            //printf("Osman\n");
            x=q.front();
            for(j=0;j<list[x].size();j++){
                y=list[x][j];
                flag=0;
                if(walk[y]==0 && (x==1 || sit[x]==1)){
                    walk[y]=1;
                    flag=1;
                }
                if(sit[y]==0 && walk[x]==1){
                    sit[y]=1;
                    flag=1;
                    count++;
                }
                if(flag==1) q.push(y);
            }
            q.pop();
        }
        printf("Case %d: %d\n",tcase++,count);
    }
    return 0;
}
