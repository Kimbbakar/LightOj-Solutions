#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    scanf("%d",&t);
    int i;
    double pi=acos(-1);
    double r,R,n;
    for(i=0;i<t;i++){
        scanf("%lf%lf",&R,&n);
        double a=360/(2*n);
        double d=sin(a*(pi/180));
        r=((R*d)/(1+d));
        printf("Case %d: %lf\n",i+1,r);
    }
    return 0;
}
