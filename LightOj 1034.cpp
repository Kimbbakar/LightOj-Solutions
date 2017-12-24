#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int>list[10010];
vector<int>on(10010);

void input(int m,int n)
{
    int i,j,x,y;
    for(i=0;i<=m;i++){
        list[i].clear();
        on[i]=0;
    }
    for(i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        list[x].push_back(y);
        //list[y].push_back(x);
    }
}

void bfs(int m,int n,int num)
{
    int i,j,k,x,y;
    queue<int>q;
    q.push(num);
    on[num]=1;
    while(!q.empty()){
        x=q.front();
        q.pop();
        for(i=0;i<list[x].size();i++){
            if(on[list[x][i]]==0){
                on[list[x][i]]=1;
                q.push(list[x][i]);
            }
        }
    }
}

int main()
{
    int i,j,k,t,tcase=1,m,n,count1,count2;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&n);
        vector<int>b;
        input(m,n);
        count1=count2=0;
        for(i=1;i<=m;i++){
            on[i]=0;
        }
        for(i=1;i<=m;i++){
            if(on[i]==0){
                count1++;
                b.push_back(i);
                bfs(m,n,i);
            }
        }
        for(i=1;i<=m;i++){
            on[i]=0;
        }
        for(i=b.size()-1;i>=0;i--){

            if(on[b[i]]==0){
                count2++;
                bfs(m,n,b[i]);
            }
        }
        printf("Case %d: %d\n",tcase++,min(count1,count2));
    }
    return 0;
}
