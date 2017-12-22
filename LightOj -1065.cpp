#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<assert.h>


using namespace std;

int  mod;

class matrix
{
    public:
        int row,col;
        int v[2][2];
};

int mod_value(int  value)
{
    return value%mod;
}


matrix matrix_mul(matrix A,matrix B)
{
    assert(A.col==B.row);
    matrix C;
    C.row=C.col=2;
    int sum=0;
    for(int i=0;i<A.row;i++)
    {
        for(int j=0;j<B.col;j++)
        {
            sum=0;
            for(int k=0;k<A.col;k++)
             {
                 sum+=(A.v[i][k]*B.v[k][j]);
                 sum=mod_value(sum);
             }
             C.v[i][j]=sum;
        }
    }
    return C;
}

matrix expo(matrix X,int n)
{
    if(n==1) return X;
    else if(n%2)
    {
        return matrix_mul(X,expo(X,n-1));
    }
    else
    {
        matrix L=expo(X,n/2);
        return matrix_mul(L,L);
    }
}

int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        int  a,b;
        int n;
        while(t--)
        {
            scanf("%d %d %d %d",&a,&b,&n,&mod);
            if(mod==1)mod=10;
            else if(mod==2)mod=100;
            else if(mod==3) mod=1000;
            else if(mod==4) mod=10000;
            matrix my;
            my.row=my.col=2;
            my.v[0][0]=my.v[0][1]=my.v[1][0]=1;
            my.v[1][1]=0;
            int  ans;
            printf("Case %d: ",tcase++);
            if(n==0)
                printf("%d\n",mod_value(a));
            else if(n==1)
                printf("%d\n",mod_value(b));
            else if(n==2)
                printf("%d\n",mod_value(a+b));
            else
            {
                my=expo(my,n-1);
                ans=b*my.v[0][0]+a*my.v[0][1];
                printf("%d\n",mod_value(ans));
            }
        }
    }
    return 0;
}
