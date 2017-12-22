#include<cstdio>
#include<cmath>

using namespace std;
 
int main()
{
    double v1,v2,v3,a1,a2,d,t1,t2,n;
    int i,j,t,tcase=1;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
        d=(pow(v1,2)/(2*a1))+(pow(v2,2)/(2*a2));
        t1=v1/a1,t2=v2/a2;
        if(t1>t2){
            n=t1*v3;
        }
        else{
            n=t2*v3;
        }
        printf("Case %d: %lf %lf\n",tcase++,d,n);
    }
    return 0;
}