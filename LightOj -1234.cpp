


#include <math.h>
#include <stdio.h>
#define N 1000000
#define gamma 0.57721566490153286060651209
double psi_0(int n)
{
    return log(n)+1.0/(2.0*n)+gamma;
}
double a[N];
int main()
{
	int t,i,n;
	a[1]=1;
	for(i=2;i<=N;i++){
        a[i]=a[i-1]+1.0/i;
	}
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
        scanf("%d",&n);
		if(n<=N){
		    printf("Case %d: %.10lf\n",i,a[n]);
		}
		else{
		    printf("Case %d: %.10lf\n",i,psi_0(n));
		}
	}
	return 0;
}