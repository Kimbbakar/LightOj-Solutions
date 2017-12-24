#include<cstdio>
#include<queue>
#include<vector>
#include<utility>
#include<map>
using namespace std;

int main()
{
    int i,j,k,m,n,a,b,c,t,tcase=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int>list[30000];
        map<pair<int,int>,int>wight;
        for(i=1;i<n;i++){
            scanf("%d %d %d",&a,&b,&c);
            list[a].push_back(b);
            wight[make_pair(a,b)]=c;
            wight[make_pair(b,a)]=c;
            list[b].push_back(a);
        }
        queue<int>q;
        q.push(0);
        vector<int>keep1(30005);
        vector<int>taken1(30005);
        int max=0,idx=0;
        taken1[0]=1;
        while(!q.empty()){
            m=q.front();
            for(i=0;i<list[m].size();i++){
                if(taken1[list[m][i]]==0){
                    // printf("%d\n",keep1[list[m][i]]);
                    //printf("@ %d== %d %d %d\n",wight[make_pair(m,list[m][i])],m,list[m][i],keep1[m]);
                    taken1[list[m][i]]=1;
                    keep1[list[m][i]]=keep1[m]+wight[make_pair(m,list[m][i])];
                    if(keep1[list[m][i]]>max){
                        max=keep1[list[m][i]];
                        idx=list[m][i];
                    }
                    q.push(list[m][i]);
                }
            }
            q.pop();
        }
        //printf("<<%d %d>>\n",idx,max);
        q.push(idx);
        vector<int>keep2(30005);
        vector<int>taken2(30005);
        taken2[idx]=1;
        max=0;
        while(!q.empty()){
            m=q.front();
            for(i=0;i<list[m].size();i++){
                if(taken2[list[m][i]]==0){
                    taken2[list[m][i]]=1;
                    keep2[list[m][i]]=keep2[m]+wight[make_pair(m,list[m][i])];
                    //printf("%d %d %d\n",keep2[list[m][i]],m,list[m][i]);
                    if(keep2[list[m][i]]>max){
                        max=keep2[list[m][i]];
                    }
                q.push(list[m][i]);
                }
            }
            q.pop();
        }
        printf("Case %d: %d\n",tcase++,max);
    }
    return 0;
}
