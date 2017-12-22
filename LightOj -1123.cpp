//light oj-1123(trail maintenance )

 #include<cstdio>
 #include<vector>
 #include<utility>
 #include<map>
 #include<queue>

 using namespace std;


 vector<int>parent(205);
 vector<int>graph[205];
 //map<pair<int,int>,int>p;
 int bos[205][205];
 int cost,path;
 int n,w;

 class data
 {
     public:
     int f_v1,f_v2,f_c;
 };

 void clr()
 {
     cost=path=0;
     for(int i=1;i<=200;i++)
     {
         parent[i]=i;
         for(int j=1;j<=200;j++)
            bos[i][j]=0;
     }
 }

 int find_union(int a)
{
     if(parent[a]==a)return a;
     return parent[a]=find_union(parent[a]);
}

 data bfs(int s,int d)
 {
     queue<int>q;
     vector<data>taken(205);
     q.push(s);
     int now,next;
     taken[s].f_c=1;
     while(!q.empty())
     {
         now=q.front();
         q.pop();
         for(int i=0;i<graph[now].size();i++)
         {
             next=graph[now][i];
             //printf("in) %d %d(%d) %d %d\n",now,next,taken[next].f_c,p[make_pair(now,next)]);
             if( bos[now][next]>0)
             {
                 if(taken[next].f_c==0)
                 {

                     if(taken[now].f_c<bos[now][next])
                     {
                         taken[next].f_v1=now,taken[next].f_v2=next;
                         taken[next].f_c=bos[now][next];
                     }
                     else
                     {
                         taken[next].f_v1=taken[now].f_v1;
                         taken[next].f_v2=taken[now].f_v2;
                         taken[next].f_c=taken[now].f_c;
                     }
                     if(next==d) return taken[next];
                     q.push(next);
                }
             }

         }
     }
 }

 void input()
 {
     int v1,v2,c;
     int p1,p2;
     data my;
     while(w--)
     {
         scanf("%d %d %d",&v1,&v2,&c);
         p1=find_union(v1);
         p2=find_union(v2);
         //printf("%d %d %d\n",v1,v2,c);
        if(p1!=p2)
        {
            parent[p1]=p2;
            cost+=c;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
            //p[make_pair(v1,v2)]=c;
            //p[make_pair(v2,v1)]=c;
            bos[v1][v2]=c;
            bos[v2][v1]=c;
            path++;
        }
        else
        {
            //if(p[make_pair(v1,v2)]>0)
            if(bos[v1][v2]>0)
            {
                if(bos[v1][v2]>c)
                {
                    cost-=bos[v1][v2];
                    cost+=c;
                    bos[v1][v2]=c;
                    bos[v2][v1]=c;
                }
            }
            else
            {

                my=bfs(v1,v2);
                if(my.f_c>c)
                {
                    //printf("bfs %d %d %d\n",my.f_v1,my.f_v2,my.f_c);
                    graph[v1].push_back(v2);
                    graph[v2].push_back(v1);
                    bos[v1][v2]=c;
                    bos[v2][v1]=c;
                    bos[my.f_v1][my.f_v2]=0;
                    bos[my.f_v2][my.f_v1]=0;
                    cost-=my.f_c;
                    cost+=c;
                }
            }
        }
        //printf("%d\n",cost);
        //printf("%d %d\n",path,n-1);
        path<(n-1)?printf("-1\n"):printf("%d\n",cost);
     }
 }

 int main()
 {
     int t;
     //freopen("in.txt","r",stdin);
     while(scanf("%d",&t)==1)
     {

         int tcase=1;
         while(t--)
         {
             scanf("%d %d",&n,&w);
             printf("Case %d:\n",tcase++);
             clr();
             input();
         }
     }
     return 0;
 }
