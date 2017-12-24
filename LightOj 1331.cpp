#include<stdio.h>
#include<math.h>

#define pi =acos(-1.0);
#define radin = 180/pi;
double triangel(double a,double b,double c)
{
    double p = (a+b+c)/2.0;
return sqrt(p*(p-a)*(p-b)*(p-c));
}

double sub_area(double r,double a,double b,double c)
{
    double angle = acos((a*a + b*b - c*c)/(2*a*b));
    return r*r*angle/2;
}

int main()
{
    int i,t;
    double r1,r2,r3,a,b,c;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        a=r1+r2;
        b=r3+r1;
        c=r2+r3;
        double area=triangel(a,b,c);
        double sub=sub_area(r1,a,b,c)+sub_area(r2,a,c,b)+sub_area(r3,b,c,a);
        double result=area-sub;
        printf("Case %d: %.10lf\n",i,result);
    }
    return 0;
}
