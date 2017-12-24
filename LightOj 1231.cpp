#include<cstdio>
#include<vector>
#define mod 100000007

using namespace std;

class my
{
public:
    int prv,next;
};

void input(int &n,int &k,vector<int> &coin,vector<int> &count)
{
    scanf("%d %d",&n,&k);
    int a;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        coin.push_back(a);
    }
    for(int i=0;i<n;i++)
        scanf("%d",&count[coin[i]]);
}

int main()
{
    int k,n,t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            vector<int>count(1000);
            vector<int>coin;
            vector<my>result(1010);
            input(n,k,coin,count);

            result[0].prv=result[0].next=1;
            for(int i=0;i<coin.size();i++)
            {
                vector<int>use(1100);
                //printf("%d\n",coin[i]);
                for(int j=coin[i];j<=k;j++)
                {
                    result[j].prv=result[j].next;
                    int need=j/coin[i];
                    if(need<=count[coin[i]])
                    {
                        result[j].next=(result[j].prv%mod+result[j-coin[i]].next%mod)%mod;
                        if(result[j-coin[i]].next!=0)
                        use[j]=1+use[j-coin[i]];
                        //printf("%d) %d %d\n ",j,result[j].next,use[j]);

                    }
                    else
                    {
                        int r=result[j].prv;

                        for(int k=1;k<=count[coin[i]];k++)
                        {
                            r=(r%mod+result[j-k*coin[i]].prv%mod)%mod;
                            //printf("** %d %d\n",r,j-k*coin[i]);
                            if(result[j-k*coin[i]].prv!=0)
                            use[j]=k;
                        }
                        result[j].next=r;
                        //printf("%d) %d %d\n ",j,result[j].next,use[j]);
                    }
                }
               //printf("\n");
            }
            printf("Case %d: %d\n",tcase++,result[k].next);
        }
    }
    return 0;
}
