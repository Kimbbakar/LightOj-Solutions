//......1047 - Neighbor House.......

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class my
{
    public:
        int prv,up;
};

vector<vector<my> >ng(25,vector<my>(5));
int m;

void input()
{
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=3;j++)
        {
            scanf("%d",&ng[i][j].prv);
            ng[i][j].up=100000000;
        }
    }
}

void s(int i,int j,int amount)
{
    if(i<1 || j<1 || i>m || j>3) return;
    //printf("%d %d %d\n",i,j,amount);
    if(j==1)
    {
        if(ng[i][j].up>amount)
        {
            ng[i][j].up=amount;
            s(i+1,j+1,ng[i][j].prv+amount);
            s(i+1,j+2,ng[i][j].prv+amount);
        }
    }
    else if(j==2)
    {
        if(ng[i][j].up>amount)
        {
            ng[i][j].up=amount;
            s(i+1,j+1,ng[i][j].prv+amount);
            s(i+1,j-1,ng[i][j].prv+amount);
        }
    }
    else if(j==3)
    {
        if(ng[i][j].up>amount)
        {
            ng[i][j].up=amount;
            s(i+1,j-1,ng[i][j].prv+amount);
            s(i+1,j-2,ng[i][j].prv+amount);
        }
    }
}

int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            input();
            s(1,3,0);
            s(1,1,0);
            s(1,2,0);
            printf("Case %d: ",tcase++);
            printf("%d\n",min(ng[m][1].up+ng[m][1].prv,min(ng[m][2].up+ng[m][2].prv,ng[m][3].up+ng[m][3].prv) ));
        }
    }
    return 0;
}
