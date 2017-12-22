#include<stdio.h>

int main()
{
    int t,i;
    scanf("%d",&t);
    double a1,b1,a2,b2,a3,b3,a4,b4,v;
    for(i=0;i<t;i++){
        scanf("%lf%lf%lf%lf%lf%lf",&a1,&b1,&a2,&b2,&a3,&b3);
        a4=a1+a3-a2;
        b4=b1+b3-b2;
        v=0.5*((a1*b2+a2*b3+a3*b4+a4*b1)-(b1*a2+b2*a3+b3*a4+b4*a1));
        if(v<0){
            v=-1*v;
        }
        printf("Case %d: %.0lf %.0lf %.0lf\n",i+1,a4,b4,v);
    }
    return 0;
}
