
#include <iostream>
#include <stdio.h>
#define MAX 5000005
#define MIN -2147483647
using namespace std;
typedef unsigned long long int ll;
int phi[5000001];
ll table[5000001];
void phi_function()
{
	phi[1] = 1;
	table[1]=0;
	for(int i=2; i<=5000001; ++i)
	{
	    if(phi[i]==0)
	    {
	        phi[i]=i-1;
			for(int j=i+i; j<=5000001; j+=i)
			{
				if(phi[j]==0)   phi[j] = j;
                phi[j]= phi[j]/i * (i-1);
			}
	    }
	}
	for(int i=2;i<5000001;i++)
	{
        table[i]=phi[i];
        table[i]*=phi[i];
        table[i]+=table[i-1];
	}
}

int main()
{
    phi_function();
    int T,Case=0;
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",++Case,table[b]-table[a-1]);
    }
}