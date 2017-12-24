#include<cstdio>
#include<vector>


using namespace std;

class my
{
    public:
        int prv,nxt;
};

void input(int n,vector<int>&coin,vector<int>&have)
{
    for(int i=0;i<n;i++)
        scanf("%d",&coin[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&have[coin[i]]);
}


int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        int n,m;
        while(t--)
        {
            int count=0;
            scanf("%d %d",&n,&m);
            vector<int>coin(1000000);
            vector<int>have(1000000);
            input(n,coin,have);
            vector<my>amount(1000000);
            for(int i=0;i<=m;i++)
                amount[i].prv=amount[i].nxt=0;
            for(int i=0;i<n;i++)
            {
                vector<int>use(1000000);
                amount[0].prv=amount[0].nxt=1;
                for(int j=coin[i];j<=m;j++)
                {
                    int need=j/coin[i];
                    amount[j].prv=amount[j].nxt;
                    if(amount[j].prv!=1)
                    {
                        if(1+use[j-coin[i]]<=have[coin[i]])
                        {
                            if(amount[j-coin[i]].nxt==1)
                            {
                                amount[j].nxt=1;
                                use[j]=1+use[j-coin[i]];
                            }

                            //printf("* %d %d\n",j,amount[j].nxt);
                        }

                        else
                        {
                            if(amount[j-have[coin[i]]*coin[i]].prv==1)
                            {
                                amount[j].nxt=1;
                                use[j]=have[coin[i]];
                            }
                            //printf("** %d %d\n",j,amount[j].nxt);
                        }
                    }

                }
            }
            for(int i=1;i<=m;i++)
                if(amount[i].nxt>=1) count++;
            printf("Case %d: %d\n",tcase++,count);

        }
    }
    return 0;
}
