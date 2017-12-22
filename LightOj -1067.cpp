#include<cstdio>
#include<cmath>
#include<vector>
#define V 1000000
#define mod 1000003
using namespace std;

vector<long long>factorial(V+9);

void calculate()
{
    factorial[0]=factorial[1]=1;
    for(int i=2;i<=V;i++)
    {
        factorial[i]=((i%mod)*factorial[i-1]%mod)%mod;
    }
}

long long Big_mod(long long v,int p)
{
    if(p==0) return 1;
    if(p%2==0)
    {
        long long c=Big_mod(v,p/2);
        return ((c%mod)*(c%mod))%mod;
    }
    else
    {
        return ((v%mod)*Big_mod(v,p-1))%mod;
    }
}
int main()
{
    int t,tcase;
    long long m,n;
    while(scanf("%d",&t)==1)
    {
        calculate();
        tcase=1;
        while(t--)
        {
            scanf("%lld %lld",&m,&n);
            long long v=(factorial[m-n]*factorial[n])%mod;
            long long ans=(factorial[m]*Big_mod(v,mod-2))%mod;
            printf("Case %d: %lld\n",tcase++,ans);
        }
    }
    return 0;
}
