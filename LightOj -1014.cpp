#include<cstdio>
#include<cmath>
using namespace std;

void sort(int ara[],int n)
{
    int i,j,t;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(ara[j]>ara[j+1]){
                t=ara[j];
                ara[j]=ara[j+1];
                ara[j+1]=t;
            }
        }
    }
}

int main()
{
    int p,l,q[2147400],t,tcase=1;
    int i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&p,&l);
        int left=p-l;
        if(left<=l){
            printf("Case %d: impossible\n",tcase++);
        }
        else{
            int root=sqrt(left);
            j=0;
            for(i=1;i<=root;i++){
                if(left%i==0){
                    if(i>l){
                        q[j++]=i;
                    }
                    if((left/i)>l && (i!=(left/i))){
                        q[j++]=left/i;
                    }
                }
            }
            sort(q,j);
            printf("Case %d:",tcase++);
            for(i=0;i<j;i++){
                printf(" %d",q[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

