#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

char mat[510][510];
int visited[510][510];
int dist[510][510];
int fx[]= {+1,-1,+0,+0};
int fy[]= {+0,+0,+1,-1};
int m,n,p,test;

int bfs(int a,int b)
{
    queue<pair<int,int> >q;
    q.push(make_pair(a,b));
    visited[a][b]=1;
    pair<int,int> u;
    int i,x,y,counter=0;
    if(mat[a][b]=='C')
    {
        counter++;
    }
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        ///////
        for(i=0; i<4; i++)
        {
            x=u.first+fx[i];
            y=u.second+fy[i];
            if(x>=0&&x<m&&y>=0&&y<n&&mat[x][y]!='#'&&visited[x][y]==0)
            {
                visited[x][y]=1;
                if(mat[x][y]=='C')
                {
                    counter++;
                }
                q.push(make_pair(x,y));
            }
        }
    }
    return counter;
}

void bbfs(int a,int b,int counter)
{
    queue<pair<int,int> >q;
    q.push(make_pair(a,b));
    visited[a][b]=2;
    pair<int,int> u;
    int i,x,y;
    dist[a][b]=counter;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            x=u.first+fx[i];
            y=u.second+fy[i];
            if(x>=0&&x<m&&y>=0&&y<n&&mat[x][y]!='#'&&visited[x][y]==1)
            {
                visited[x][y]=2;
                /// dddddddddddd
                dist[x][y]=counter;
                q.push(make_pair(x,y));
            }
        }
    }
}


int main()
{


    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int i,j,k,x,y,answer;
    scanf("%d",&test);
    //ddddddddddd
    for(int zz=0;zz<test;zz++)
    {
        scanf("%d%d%d",&m,&n,&p);
        memset(visited,0,sizeof visited);
        memset(dist,0,sizeof dist);


        getchar();
        for(j=0;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                //cin>>mat[j][k];
                scanf("%c",&mat[j][k]);

                //cout<<mat[j][k]<<endl;
            }
            getchar();
        }


        printf("Case %d:\n",zz+1);
        for(i=1;i<=p;i++)
        {
            scanf("%d%d",&x,&y);
            /// fffffffff
            if(mat[x-1][y-1]=='#' )
                printf("0\n");
    ///
            else if(visited[x-1][y-1]==0)
            {
                answer=bfs(x-1,y-1);

                bbfs(x-1,y-1,answer);
                printf("%d\n",answer);
            }
            else
            {
                printf("%d\n",dist[x-1][y-1]);
            }
        }
    }
    return 0;
}
