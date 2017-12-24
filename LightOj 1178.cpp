#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    double a,b,c,d,h,area,root,m;
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lf%lf%lf%lf",&a,&c,&b,&d);
        root=sqrt((-a+b+c+d)*(a-b+c+d)*(a-b-c+d)*(a-b+c-d));
        m=2*fabs(a-b);
        h=root/m;
        area=h*(a+b)*0.5;
        printf("Case %d: %.10lf\n",i,area);
    }
    return 0;
}
