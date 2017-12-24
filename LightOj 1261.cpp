#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;


int main()
{
    int t,tcase;
    int n,m,k,num,p;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            int pos[35][35]={0};
            int neg[35][35]={0};
            int take[35]={0};
            bool happy[35]={false};
            int flag=0;
            scanf("%d %d %d",&n,&m,&k);
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=k;j++)
                {
                    scanf("%d",&num);
                    if(num>0)
                        pos[i][num]=1;
                    else
                        neg[i][-1*num]=1;
                }
            }
            scanf("%d",&p);
            for(int i=1;i<=p;i++)
            {
                scanf("%d",&num);
                take[num]=1;
            }
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(take[i]==0)
                    {
                        if(neg[j][i]==1)
                            happy[j]=true;
                    }
                    else if(take[i]==1)
                    {
                        if(pos[j][i]==1)
                            happy[j]=true;
                    }
                }
            }
            for(int i=1;i<=n;i++)
                if(happy[i]==false)
                flag=1;
            printf("Case %d: ",tcase++);
            if(flag==0)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
