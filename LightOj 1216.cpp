#include<stdio.h>

int main()
{
    double r1,r2,r3,h,p;
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        r3=((p*(r1-r2))/h)+r2;
        double v=acos(-1)*p*(r3*r3+r2*r3+r2*r2)*1/3.0;
        printf("Case %d: %lf\n",i+1,v);
    }
    return 0;
}
