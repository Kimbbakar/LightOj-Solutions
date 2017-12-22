#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    double AB,BC,AC,r;
    int t,tcase=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf",&AB,&AC,&BC,&r);
        r=r/(r+1);
        double ans=AB*sqrt(r);
        printf("Case %d: %.8lf\n",tcase++,ans);
    }
    return 0;
}
