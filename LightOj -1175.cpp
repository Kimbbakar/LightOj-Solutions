#include<cstdio>
#include<vector>
#include<string>
#include<queue>

using namespace std;

class point
{
public:
    int x,y;
    void set_v(int a,int b)
    {
        x=a;
        y=b;
    }
};

int axe_x[]={1,-1,0,0};
int axe_y[]={0,0,1,-1};

void input(int r,int c,vector<vector<char> >&maze,queue<point>&f,queue<point>&ja)
{
    point my;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf(" %c",&maze[i][j]);
            my.set_v(i,j);
            if(maze[i][j]=='F')
                f.push(my);
            else if(maze[i][j]=='J')
                ja.push(my);
        }
    }
}

void bfs_1(int r,int c,queue<point>f,vector<vector<char> >&maze,vector<vector<int> >&fire)
{
    point now,nxt;
    while(!f.empty())
    {
        now=f.front();
        f.pop();
        if(maze[now.x][now.y]=='F')
            fire[now.x][now.y]=1;
        for(int i=0;i<4;i++)
        {
            int x=axe_x[i]+now.x;
            int y=axe_y[i]+now.y;
            if(x>=0 && x<r && y>=0 && y<c && fire[x][y]==0 && maze[x][y]!='F' && maze[x][y]!='#')
            {
                nxt.set_v(x,y);
                f.push(nxt);
                fire[x][y]=1+fire[now.x][now.y];
            }
        }
    }
}

int bfs_2(int r,int c,queue<point>j,vector<vector<char> >&maze,vector<vector<int> >&fire)
{
    vector<vector<int> >jan(r,vector<int>(c));
    point now,nxt;
    while(!j.empty())
    {
        now=j.front();
        j.pop();
        if(maze[now.x][now.y]=='J')
            jan[now.x][now.y]=1;
        //printf("** %d %d\n,",now.x,now.y);
        for(int i=0;i<4;i++)
        {
            int x=axe_x[i]+now.x;
            int y=axe_y[i]+now.y;
            if(x>=0 && x<r && y>=0 && y<c)
                if(fire[x][y]==0)fire[x][y]=1000;
            //printf("** %d %d\n",jan[now.x][now.y],fire[x][y]);
            //printf("%d %d\n",x,y);
            if(x>=0 && x<r && y>=0 && y<c && jan[x][y]==0 && maze[x][y]!='F' && maze[x][y]!='#' && jan[now.x][now.y]+1<fire[x][y])
            {
                //printf("%d %d\n",x,y);
                nxt.set_v(x,y);
                j.push(nxt);
                jan[x][y]=1+jan[now.x][now.y];
            }
            else if((x<0 || x>=r) || (y<0 || y>=c))
                return jan[now.x][now.y];
        }
    }
    return -1;
}

int main()
{
    int t,tcase,r,c;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%d %d",&r,&c);
            vector<vector<int> >fire(r,vector<int>(c));
            vector<vector<char> >maze(r,vector<char>(c));
            queue<point>f;
            queue<point>j;
            input(r,c,maze,f,j);
            if(!f.empty());
            bfs_1(r,c,f,maze,fire);
            int ans=bfs_2(r,c,j,maze,fire);
            printf("Case %d: ",tcase++);
            if(ans==-1)printf("IMPOSSIBLE\n");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
