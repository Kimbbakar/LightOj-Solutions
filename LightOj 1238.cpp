#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m,ai,aj,bi,bj,ci,cj;
char arr[25][25];
//int time[25][25];
void input()
{
    char ch;
    memset(arr,'\0',sizeof(arr));
    scanf("%d %d",&n,&m);
    scanf("%c",&ch);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%c",&arr[i][j]);
            if(arr[i][j]=='a')
            {
                ai=i;
                aj=j;
            }
            else if(arr[i][j]=='b')
            {
                bi=i;
                bj=j;
            }
            else if(arr[i][j]=='c')
            {
                ci=i;
                cj=j;
            }
        }
        scanf("%c",&ch);
    }
    return;
}
int BFS(int si,int sj)
{
    int time[25][25];
    //memset(time,10000,sizeof(time));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            time[i][j]=1000;
    }
    queue<int>qr;
    queue<int>qc;
    int row[4]={0,0,-1,1};
    int column[4]={1,-1,0,0};
    int r,c,new_r,new_c;
    qr.push(si);
    qc.push(sj);
    time[si][sj]=0;
    while(!qr.empty())
    {
        r=qr.front();
        c=qc.front();
        //cout<<r<<" "<<c<<endl;
        qr.pop();
        qc.pop();
        for(int i=0;i<4;i++)
        {
            new_r=r+row[i];
            new_c=c+column[i];
            if(new_r>0 && new_c>0 && new_r<=n && new_c<=m && arr[new_r][new_c]!='m' && arr[new_r][new_c]!='#'  && !(new_r==si && new_c==sj)){
            if(arr[new_r][new_c]=='h')
            {
                return(time[r][c]+1);
            }

            else
            {
                //cout<<"time "<<time[r][c]<<" "<<time[new_r][new_c]<<endl;
                if(time[new_r][new_c]>time[r][c]+1){
                time[new_r][new_c]=time[r][c]+1;
                //cout<<"TIME "<<time[new_r][new_c]<<endl;
                qr.push(new_r);
                qc.push(new_c);
                }
            }
            }
        }
    }
    return 0;
}
int main()
{
    int test,ans;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        input();
        int x=BFS(ai,aj);
        int y=BFS(bi,bj);
        int z=BFS(ci,cj);
        //cout<<x<<" "<<y<<" "<<z<<endl;
        if(x>=y && x>=z)
            ans=x;
        else if(y>=x && y>=z)
            ans=y;
        else if(z>=y && z>=x)
            ans=z;
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
