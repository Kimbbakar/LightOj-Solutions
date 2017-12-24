
#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    int i,j,k,t,tcase=1;
    int flag,a,b,count,n,m,c,x;
    scanf("%d",&t);
    int money[1005];
    while(t--){
        scanf("%d %d",&n,&m);
        vector<int>list[1005];
        vector<int>keep;
        int visit[1005]={0};
        count=0;
        for(i=1;i<=n;i++){
            scanf("%d",&money[i]);
            count+=money[i];
        }
        for(i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            list[a].push_back(b);
            list[b].push_back(a);
        }
        flag=0;
        printf("Case %d: ",tcase++);
        if(count%n!=0){
            printf("No\n");
        }
        else{
                    for(i=1;i<=n;i++){
            queue<int>q;
            count=c=0;
            if(visit[i]==0){
                //printf("<<%d>>\n",i);
                visit[i]=1;
                q.push(i);
                count+=money[i];
                c++;
                while(!q.empty()){
                    x=q.front();

                    for(k=0;k<list[x].size();k++){
                        if(visit[list[x][k]]==0){
                            count+=money[list[x][k]];
                            //printf("%d=%d %d\n",list[x][i],money[list[x][i]],count);
                            c++;
                            visit[list[x][k]]=1;
                            q.push(list[x][k]);

                        }
                    }
                    q.pop();
                }
                keep.push_back(count/c);
                //printf("%d %d\n",count,c);
            }
        }

        for(i=0;i<keep.size()-1;i++){
            if(keep[i]!=keep[i+1]){
                printf("No\n");
                flag=1;
                break;
            }
        }
        if(flag==0) printf("Yes\n");
        }
    }
    return 0;
}
