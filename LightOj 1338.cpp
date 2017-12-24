#include<stdio.h>
#include<string.h>

int sort(char a[])
{
    int n=strlen(a);
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                char m=a[j];
                a[j]=a[j+1];
                a[j+1]=m;
            }
        }
    }
}

int main()
{
    char a[150],b[150],c[150],d[150];
    int i,j,t,n=1;
    scanf("%d",&t);
    gets(a);
    while(t--){
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        int j=0,k=0;
        gets(a);
        for(i=0;i<strlen(a);i++){
            if(a[i]>='A' && a[i]<='Z'){
                c[j]=a[i]+32;
                j++;
            }
            else if(a[i]>='a' && a[i]<='z'){
                c[j]=a[i];
                j++;
            }
        }
        c[j]='\0';
        gets(b);
        for(i=0;i<strlen(b);i++){
            if(b[i]>='A' && b[i]<='Z'){
                d[k]=b[i]+32;
                k++;
            }
            else if(b[i]>='a' && b[i]<='z'){
                d[k]=b[i];
                k++;
            }
        }
        d[k]='\0';
        sort(c);
        sort(d);
        if(strcmp(c,d)==0){
            printf("Case %d: Yes\n",n++);
        }
        else{
            printf("Case %d: No\n",n++);
        }
    }
    return 0;
}

