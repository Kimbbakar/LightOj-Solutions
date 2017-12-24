#include<cstdio>
#include<vector>


using namespace std;

int main()
{
    int t,n,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%d",&n);
            vector<double>v(n);
            for(int i=0;i<n;i++)
                scanf("%lf",&v[i]);
            for(int i=n-1;i>=0;i--)
            {
                int count=0;
                double sum=0.0;
                for(int j=i+1;count<6 && j<n;j++)
                {
                    sum+=v[j];
                    count++;
                }
                if(count==0)
                    v[i]=v[i]+sum;
                else
                    v[i]=v[i]+(1.0/count)*sum;
            }
            printf("Case %d: %lf\n",tcase++,v[0]);
        }
    }
    return 0;
}
