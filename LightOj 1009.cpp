 #include<bits/stdc++.h>
#define sf(n) scanf("%d",&n);
#define For(n) for(int i=0;i<n;i++)
using namespace std;

vector< int > g[20001];
int visited[20004],mark[20004];
queue <int> Q;

int BFS(int src){
    int cost=0,r,u;
    int odd_even[2]={0};
    odd_even[1]=1;
    visited[src]=1;
    Q.push(src);
    while(!Q.empty()){

    u=Q.front();
        Q.pop();
    For(g[u].size()){
        if(!visited[g[u][i]]){
           odd_even[(visited[u]==1 )?0:1   ]++;
            visited[g[u][i]]=(visited[u]==1 )?2:1 ;
            Q.push(g[u][i]);
        }

    }
    }
    //cout << odd << " " << even << endl;
    return max(odd_even[0],odd_even[1]);
}

int djnt[20004];

int main()
{
   int N,u,v,sum,C,r,k;
   sf(C);
   For(C){
       sum=0;
       For(20001)
       {
            g[i].clear();
            mark[i]=0;
        }

       sf(N);
       k=0;
        For(N){
            sf(u); sf(v);
           g[u].push_back(v);
           g[v].push_back(u);
           if(!mark[u]){
               djnt[k++]=u;
               visited[u]=0;
               mark[u]=1;
           }
           if(!mark[v]){
               visited[v]=0;
               djnt[k++]=v;
               mark[v]=1;
           }
        }
       For(k){
           if(!visited[djnt[i]])
           {
                sum+= BFS(djnt[i]);
           }

       }
        printf("Case %d: %d\n",i+1,sum);
   }
}
