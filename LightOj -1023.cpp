#include<cstdio>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
    char a[30];
    int t,i,j,n,m;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        for(j=0;j<n;j++){
            a[j]=j+'A';
        }
        a[j]='\0';
        printf("Case %d:\n",i);
        while(m--){
            printf("%s\n",a);
            if(next_permutation(a,a+n)==false){
                break;
            }
        }
    }
    return 0;
}
