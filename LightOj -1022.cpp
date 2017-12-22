#include<stdio.h>
#include<math.h>

int main()
{
    int num;
    scanf("%d",&num);
    int i;
    double r,result;
    double pi=2*acos(0.0);
    for(i=0;i<num;i++){
        scanf("%lf",&r);
        result=pow((r*2),2)-(pi*pow(r,2));
        printf("Case %d: %.02lf\n",(i+1),result);
    }
    return 0;
}
