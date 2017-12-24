#include<stdio.h>
#include<string.h>

int main()
{
    int a[500];
    char s[20];
    int i,t,x,y;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d",&x,&y);
        int L=100,R=101,p=0,n;
        printf("Case %d:\n",i);
        while(y--){
            scanf("%s",s);
            if(strcmp(s,"pushLeft")==0){
                scanf("%d",&n);
                if(p==x){
                    printf("The queue is full\n");
                }
                else{
                    a[L--]=n;
                    p++;
                    printf("Pushed in left: %d\n",n);
                }
            }
            else if(strcmp(s,"pushRight")==0){
                scanf("%d",&n);
                if(p==x){
                    printf("The queue is full\n");
                }
                else{
                    a[R++]=n;
                    p++;
                    printf("Pushed in right: %d\n",n);
                }
            }
            else if(strcmp(s,"popLeft")==0){
                if(p==0){
                    printf("The queue is empty\n");
                }
                else{
                    L++;
                    printf("Popped from left: %d\n",a[L]);
                    p--;
                }
            }
            else if(strcmp(s,"popRight")==0){
                if(p==0){
                    printf("The queue is empty\n");
                }
                else{
                    R--;
                    printf("Popped from right: %d\n",a[R]);
                    p--;
                }
            }
        }
    }
     return 0;
}
