#include<cstdio>
#include<vector>

using namespace std;
vector<int>dimond[250+10];
vector<int>dimond1[250+10];
void clr(int n)
{
    for(int i=0;i<2*n;i++)
    {
        dimond[i].clear();
        dimond1[i].clear();
    }
}
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        int tcase=1;
        int n,num;

        while(t--)
        {
            scanf("%d",&n);
            clr(n);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<=i;j++)
                {
                    scanf("%d",&num);
                    dimond[i].push_back(num);
                }
            }
            for(int i=n;i<2*n-1;i++)
            {
                for(int j=0;j<(2*n-1-i);j++)
                {
                    scanf("%d",&num);
                    dimond[i].push_back(num);
                }
            }
            dimond1[0].push_back(dimond[0][0]);
            for(int i=1;i<n;i++)
            {

                int sz=dimond[i].size();
                for(int j=0;j<sz;j++)
                {
                    dimond1[i].push_back(0);

                    if(j==0)
                        dimond1[i][j]=dimond[i][j]+dimond1[i-1][0];
                    else if(j==sz-1)
                        dimond1[i][j]=dimond[i][j]+dimond1[i-1][j-1];
                    else
                        dimond1[i-1][j-1]>=dimond1[i-1][j]?dimond1[i][j]=dimond[i][j]+dimond1[i-1][j-1]:dimond1[i][j]=dimond[i][j]+dimond1[i-1][j];
                }
            }
            for(int i=n;i<2*n-1;i++)
            {

                int sz=dimond[i].size();
                for(int j=0;j<sz;j++)
                {
                    dimond1[i].push_back(0);
                    if(dimond1[i-1][j]>=dimond1[i-1][j+1])
                    {
                        dimond1[i][j]=dimond[i][j]+dimond1[i-1][j];
                    }
                    else
                    {
                        dimond1[i][j]=dimond[i][j]+dimond1[i-1][j+1];
                    }
                }
            }
            printf("Case %d: %d\n",tcase++,dimond1[2*n-2][0]);
        }
    }
    return 0;
}
