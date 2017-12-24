#include<cstdio>
#include<vector>
#include<cmath>
#include<cstdlib>


using namespace std;


int zero(int n)
{
    int five=5;
    int count=0;
    while(n/five>0)
    {
        count+=(n/five);
        five*=5;
    }
    return count;
}

int b_sreach(int n)
{
    int first=1;
    int last=400000015;
    int mid,m,ans=-1;
    while(first<=last)
    {
        mid=(first+last)/2;
        m=zero(mid);
       // printf("%d %d %d\n",first,last,m);
        if(m>n)
            last=mid-1;
        else if(m<n)
            first=mid+1;
        else if(m==n)
        {
            ans=mid;
            last=mid-1;
        }
        //system("pause");
    }
    return ans;
}


int main()
{
    int t,tcase;
    int n;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%d",&n);
            int ans=b_sreach(n);
            printf("Case %d: ",tcase++);
            if(ans==-1)
                printf("impossible\n");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
