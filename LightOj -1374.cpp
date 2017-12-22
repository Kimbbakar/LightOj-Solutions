
#include<cstdio>
#include<iostream>

using namespace std;

int counter[1000005]={0};
int main()
{
    int number[10005];
    int i,t,n,tcase=1,flag;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        flag=0;
        for(i=1;i<=n;i++){
            counter[i]=-1;
        }
        for(i=0;i<n;i++){
            scanf("%d",&number[i]);
            if(counter[number[i]+1]==-1 && number[i]<=n && flag==0){
                counter[number[i]+1]=1;
            }
            else if(counter[n-number[i]]==-1 && number[i]<=n && flag==0){
                counter[n-number[i]]=1;
            }
            else if(flag==0){
                flag=1;
            }
        }
        if(flag==0){
            printf("Case %d: yes\n",tcase++);
        }
        else{
            printf("Case %d: no\n",tcase++);
        }
    }
    return 0;
}
