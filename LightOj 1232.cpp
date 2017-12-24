//......coin change 2.......

#include<cstdio>
#include<vector>
#define mod 100000007

using namespace std;

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
        count[coin[i]]=k;
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
            vector<int>result(10010);
            input(n,k,coin,count);
            result[0]=1;
            for(int i=0;i<coin.size();i++)
                 for(int j=coin[i];j<=k;j++)
                    result[j]=(result[j]%mod+result[j-coin[i]]%mod)%mod;
            printf("Case %d: %d\n",tcase++,result[k]);
        }
    }
    return 0;
}
